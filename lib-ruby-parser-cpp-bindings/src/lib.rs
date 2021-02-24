#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]
#![allow(dead_code)]
#![allow(improper_ctypes)]

extern crate lib_ruby_parser;

mod bindings;
mod byte_ptr;
mod cpp_from_rust;
mod cpp_from_rust_gen;
mod node;
mod ptr;

mod comment;
mod custom_decoder;
mod diagnostic;
mod list;
mod loc;
mod magic_comment;
mod message_gen;
mod parser_options;
mod parser_result;
mod render_message;
mod token;
mod token_rewriter;

use bindings::BytePtr;
use ptr::Ptr;

#[no_mangle]
pub extern "C" fn parse(
    input: BytePtr,
    options: *mut bindings::ParserOptions,
) -> *const bindings::ParserResult {
    let input = input.into_vec();
    let options = lib_ruby_parser::ParserOptions::from(Ptr::new(options));
    let result = lib_ruby_parser::Parser::new(&input, options).do_parse();
    Ptr::<bindings::ParserResult>::from(result).unwrap()
}

#[no_mangle]
pub extern "C" fn token_name(id: i32) -> BytePtr {
    BytePtr::from(lib_ruby_parser::token_name(id).to_owned())
}

#[no_mangle]
pub extern "C" fn byte_ptr_to_utf8_lossy_byte_ptr(
    byte_ptr: bindings::BytePtr,
) -> bindings::BytePtr {
    bindings::BytePtr::from(byte_ptr.to_string_lossy())
}

#[no_mangle]
pub extern "C" fn byte_ptr_into_utf8_lossy_byte_ptr(
    byte_ptr: bindings::BytePtr,
) -> bindings::BytePtr {
    bindings::BytePtr::from(byte_ptr.into_string_lossy())
}
