#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]
#![allow(dead_code)]
#![allow(improper_ctypes)]

use std::slice;

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
pub extern "C" fn parse(input: *const u8, length: usize) -> *const ParserResult {
    let input = unsafe { slice::from_raw_parts(input, length) };
    let options = lib_ruby_parser::ParserOptions {
        ..Default::default()
    };
    let rust_parser_result = lib_ruby_parser::Parser::new(input, options).do_parse();
    let cpp_parser_result = CppFromRust::convert(rust_parser_result);
    cpp_parser_result
}
