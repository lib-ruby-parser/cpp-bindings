use crate::bindings;
use crate::Ptr;

impl From<Ptr<bindings::ParserOptions>> for lib_ruby_parser::ParserOptions {
    fn from(ptr: Ptr<bindings::ParserOptions>) -> Self {
        let options = ptr.unwrap();

        if options.is_null() {
            return lib_ruby_parser::ParserOptions::default();
        }

        let buffer_ptr = unsafe { bindings::parser_options_buffer_name(options) };
        let decoder_ptr = unsafe { bindings::parser_options_custom_decoder(options) };
        let token_rewriter_ptr = unsafe { bindings::parser_options_token_rewriter(options) };

        let debug = unsafe { bindings::parser_options_debug(options) };
        let record_tokens = unsafe { bindings::parser_options_record_tokens(options) };

        lib_ruby_parser::ParserOptions {
            buffer_name: buffer_ptr.into_string_lossy(),
            debug,
            decoder: Ptr::new(decoder_ptr).into(),
            token_rewriter: Ptr::new(token_rewriter_ptr).into(),
            record_tokens,
        }
    }
}
