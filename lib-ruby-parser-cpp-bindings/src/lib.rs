#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]
#![allow(dead_code)]
#![allow(improper_ctypes)]

extern crate lib_ruby_parser;

pub mod bindings;
use bindings::*;

mod helpers;
use helpers::*;

mod cpp_from_rust;
pub use cpp_from_rust::CppFromRust;
mod cpp_from_rust_gen;

mod string_ptr;
pub use string_ptr::StringPtr;

mod node_ptr;
pub use node_ptr::NodePtr;

mod range_ptr;
pub use range_ptr::RangePtr;

#[no_mangle]
pub extern "C" fn parse(
    input: *const u8,
    length: usize,
    options: *mut ParserOptions,
) -> *const ParserResult {
    println!("1");
    let input = unsafe { std::slice::from_raw_parts(input, length) };
    println!("2");
    let options = unsafe { options.as_ref() }
        .map(|options| lib_ruby_parser::ParserOptions::from(options))
        .unwrap_or_else(|| lib_ruby_parser::ParserOptions::default());
    println!("3");
    let rust_parser_result = lib_ruby_parser::Parser::new(input, options).do_parse();
    println!("4");
    let cpp_parser_result = CppFromRust::convert(rust_parser_result);
    println!("5");
    cpp_parser_result
}

#[no_mangle]
pub extern "C" fn token_name(id: i32) -> *mut i8 {
    let (ptr, _) = string_to_ptr(lib_ruby_parser::token_name(id).to_owned());
    ptr
}

impl From<&ParserOptions> for lib_ruby_parser::ParserOptions {
    fn from(options: &ParserOptions) -> Self {
        println!("converting 1");
        let buffer_name = unsafe { std::ffi::CStr::from_ptr(options.buffer_name) }
            .to_owned()
            .into_string()
            .unwrap();
        println!("converting 2, {}", buffer_name);
        let debug = options.debug;
        let record_tokens = options.record_tokens;
        drop(options);
        println!("converting 3");
        let result = Self {
            buffer_name,
            debug,
            decoder: lib_ruby_parser::source::CustomDecoder::default(),
            token_rewriter: None,
            record_tokens,
        };

        println!("converting 4");

        result
    }
}
