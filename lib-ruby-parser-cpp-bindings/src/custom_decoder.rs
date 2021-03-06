use crate::bindings;
use crate::BytePtr;
use crate::Ptr;

fn decode_with_decoder(
    encoding: BytePtr,
    input: BytePtr,
    decoder: *mut bindings::CustomDecoder,
) -> Result<Vec<u8>, lib_ruby_parser::source::InputError> {
    let cpp_result = unsafe { bindings::rewrite(decoder, encoding, input) };

    if cpp_result.success {
        let output = cpp_result.output.into_vec();
        Ok(output)
    } else {
        let error_message = cpp_result.error_message.into_string_lossy();
        Err(lib_ruby_parser::source::InputError::DecodingError(
            error_message,
        ))
    }
}

impl From<Ptr<bindings::CustomDecoder>>
    for Option<Box<dyn lib_ruby_parser::source::CustomDecoder>>
{
    fn from(decoder_ptr: Ptr<bindings::CustomDecoder>) -> Self {
        let decoder_ptr = decoder_ptr.unwrap();

        if decoder_ptr.is_null() {
            return None;
        }

        let decode = move |encoding: &str, input: &[u8]| {
            let encoding = BytePtr::from(encoding);
            let input = BytePtr::from(input);
            decode_with_decoder(encoding, input, decoder_ptr)
        };

        Some(Box::new(
            lib_ruby_parser::source::RustFnBasedCustomDecoder::new(Box::new(decode)),
        ))
    }
}
