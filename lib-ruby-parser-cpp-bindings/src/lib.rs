#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]
#![allow(dead_code)]
#![allow(improper_ctypes)]

extern crate lib_ruby_parser;

pub mod bindings;
mod cpp_from_rust;
mod cpp_from_rust_gen;
mod helpers;
mod node_ptr;
mod range_ptr;

use bindings::*;

pub use cpp_from_rust::CppFromRust;

pub use node_ptr::NodePtr;

pub use range_ptr::RangePtr;

#[no_mangle]
pub extern "C" fn parse(
    input: *const u8,
    length: usize,
    options: *mut ParserOptions,
) -> *const ParserResult {
    let input = unsafe { std::slice::from_raw_parts(input, length) };
    let options = if options.is_null() {
        lib_ruby_parser::ParserOptions::default()
    } else {
        convert_parser_options(options)
    };
    let rust_parser_result = lib_ruby_parser::Parser::new(input, options).do_parse();
    CppFromRust::convert(rust_parser_result)
}

#[no_mangle]
pub extern "C" fn token_name(id: i32) -> *mut i8 {
    helpers::string_to_char_ptr(lib_ruby_parser::token_name(id).to_owned())
}

fn convert_parser_options(options: *mut ParserOptions) -> lib_ruby_parser::ParserOptions {
    if options.is_null() {
        return lib_ruby_parser::ParserOptions::default();
    }

    let buffer_name = unsafe {
        let ptr = bindings::parser_options_buffer_name(options);
        std::ffi::CStr::from_ptr(ptr)
    }
    .to_owned()
    .into_string()
    .unwrap();

    let decoder =
        convert_custom_decoder(unsafe { bindings::parser_options_custom_decoder(options) });

    let options = unsafe { options.as_ref() }.unwrap();

    let debug = options.debug;
    let record_tokens = options.record_tokens;

    lib_ruby_parser::ParserOptions {
        buffer_name,
        debug,
        decoder,
        token_rewriter: None,
        record_tokens,
    }
}

fn convert_custom_decoder(
    decoder_ptr: *mut CustomDecoder,
) -> lib_ruby_parser::source::CustomDecoder {
    if decoder_ptr.is_null() {
        return lib_ruby_parser::source::CustomDecoder::default();
    }

    let decode = move |encoding: &str,
                       input: &[u8]|
          -> Result<Vec<u8>, lib_ruby_parser::source::InputError> {
        let cpp_result = unsafe {
            bindings::rewrite(
                decoder_ptr,
                encoding.as_ptr() as *const i8,
                encoding.len() as size_t,
                input.as_ptr() as *const i8,
                input.len() as size_t,
            )
        };
        if cpp_result.success {
            let output = unsafe {
                std::slice::from_raw_parts(
                    cpp_result.output as *mut u8,
                    cpp_result.output_length as usize,
                )
            }
            .to_vec();
            unsafe { free_str(cpp_result.output as *mut i8) };
            Ok(output)
        } else {
            let error_message =
                unsafe { std::ffi::CString::from_raw(cpp_result.error_message as *mut i8) }
                    .to_string_lossy()
                    .into_owned();
            Err(lib_ruby_parser::source::InputError::DecodingError(
                error_message,
            ))
        }
    };

    lib_ruby_parser::source::CustomDecoder::new(Box::new(decode))
}
