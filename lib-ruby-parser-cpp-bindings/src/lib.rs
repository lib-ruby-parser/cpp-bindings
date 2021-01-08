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
    let options = unsafe { options.as_ref() }
        .map(|options| lib_ruby_parser::ParserOptions::from(options))
        .unwrap_or_else(|| lib_ruby_parser::ParserOptions::default());
    let rust_parser_result = lib_ruby_parser::Parser::new(input, options).do_parse();
    CppFromRust::convert(rust_parser_result)
}

#[no_mangle]
pub extern "C" fn token_name(id: i32) -> *mut i8 {
    helpers::string_to_char_ptr(lib_ruby_parser::token_name(id).to_owned())
}

impl From<&ParserOptions> for lib_ruby_parser::ParserOptions {
    fn from(options: &ParserOptions) -> Self {
        let buffer_name = unsafe { std::ffi::CStr::from_ptr(options.buffer_name) }
            .to_owned()
            .into_string()
            .unwrap();
        let debug = options.debug;
        let record_tokens = options.record_tokens;
        Self {
            buffer_name,
            debug,
            decoder: lib_ruby_parser::source::CustomDecoder::default(),
            token_rewriter: None,
            record_tokens,
        }
    }
}
