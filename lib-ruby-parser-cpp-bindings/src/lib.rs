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
    input: bindings::BytePtr,
    options: *mut bindings::ParserOptions,
) -> *const bindings::ParserResult {
    let input = input.into_vec();
    let options = lib_ruby_parser::ParserOptions::from(Ptr::new(options));
    let result = lib_ruby_parser::Parser::new(&input, options).do_parse();
    Ptr::<bindings::ParserResult>::from(result).unwrap()
}

#[no_mangle]
pub extern "C" fn token_name(id: i32) -> bindings::BytePtr {
    bindings::BytePtr::from(lib_ruby_parser::token_name(id).to_owned())
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

#[no_mangle]
pub extern "C" fn input_source(input: *mut lib_ruby_parser::source::Input) -> *const i8 {
    let input = match unsafe { input.as_ref() } {
        Some(input) => input,
        None => {
            panic!("null ptr given to input_source");
            // return std::ptr::null()
        }
    };

    input.as_bytes().as_ptr() as *const i8
}

#[no_mangle]
pub extern "C" fn input_size(input: *mut lib_ruby_parser::source::Input) -> u32 {
    let input = match unsafe { input.as_ref() } {
        Some(input) => input,
        None => {
            panic!("null ptr given to input_size");
            // return 0
        }
    };

    input.as_bytes().len() as u32
}

#[no_mangle]
pub extern "C" fn input_range(
    input: *mut lib_ruby_parser::source::Input,
    begin: u32,
    end: u32,
) -> bindings::BytePtr {
    let input = match unsafe { input.as_ref() } {
        Some(input) => input,
        None => {
            panic!("null ptr given to input_range");
            // return bindings::BytePtr::empty()
        }
    };

    let bytes = input.as_bytes();
    let range = bytes[begin as usize..end as usize].to_owned();
    bindings::BytePtr::from(range)
}

#[no_mangle]
pub extern "C" fn input_free(input: *mut lib_ruby_parser::source::Input) {
    if input.is_null() {
        panic!("null ptr given to input_free");
        // return;
    }

    let input = unsafe { Box::from_raw(input) };
    drop(input);
}
