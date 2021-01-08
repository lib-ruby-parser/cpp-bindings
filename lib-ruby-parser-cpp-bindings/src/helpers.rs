use crate::bindings::{self, size_t, Node};
use crate::CppFromRust;
use std::ffi::CString;

pub fn ptr_value<T>(value: T) -> *mut T {
    Box::into_raw(Box::new(value))
}

pub fn string_to_char_ptr(s: String) -> *mut i8 {
    let mut bytes = CString::new(s).unwrap().into_bytes_with_nul();
    let ptr = bytes.as_mut_ptr();
    std::mem::forget(bytes);
    ptr as *mut i8
}

pub fn maybe_string_to_char_ptr(s: Option<String>) -> *mut i8 {
    if let Some(s) = s {
        string_to_char_ptr(s)
    } else {
        string_to_char_ptr(String::from(""))
    }
}

pub fn string_value_to_char_ptr(s: lib_ruby_parser::StringValue) -> *mut i8 {
    string_to_char_ptr(s.to_string_lossy())
}

pub fn chars_to_char_ptr(s: Vec<char>) -> *mut i8 {
    string_to_char_ptr(s.iter().collect::<String>())
}

pub fn string_to_ptr(s: String) -> (*mut i8, size_t) {
    let len = s.len() as size_t;
    let mut bytes = CString::new(s).unwrap().into_bytes_with_nul();
    let ptr = bytes.as_mut_ptr();
    std::mem::forget(bytes);
    (ptr as *mut i8, len)
}

pub fn vec_to_ptr(vec: Vec<u8>) -> (*mut i8, size_t) {
    let len = vec.len() as size_t;
    let mut boxed_slice = vec.into_boxed_slice();
    let ptr = boxed_slice.as_mut_ptr();
    std::mem::forget(boxed_slice);
    (ptr as *mut i8, len)
}

pub fn nodes_vec_to_cpp(nodes: Vec<lib_ruby_parser::Node>) -> bindings::NodeVec {
    let nodes: Vec<*mut Node> = nodes
        .into_iter()
        .map(|node| CppFromRust::convert(node))
        .collect();

    let len = nodes.len() as size_t;
    let mut boxed_slice = nodes.into_boxed_slice();
    let ptr = boxed_slice.as_mut_ptr();
    std::mem::forget(boxed_slice);
    bindings::NodeVec {
        list: ptr,
        length: len,
    }
}

pub fn map_vec_to_c_list<T, Target>(vec: Vec<T>, f: fn(T) -> Target) -> (*mut Target, size_t) {
    let mut boxed_slice = vec
        .into_iter()
        .map(f)
        .collect::<Vec<_>>()
        .into_boxed_slice();
    let len = boxed_slice.len() as size_t;
    let ptr = boxed_slice.as_mut_ptr();
    std::mem::forget(boxed_slice);
    (ptr, len)
}

pub fn input_to_ptr(input: lib_ruby_parser::source::buffer::Input) -> *mut i8 {
    let mut bytes = CString::new(input.bytes).unwrap().into_bytes_with_nul();
    let ptr = bytes.as_mut_ptr();
    std::mem::forget(bytes);
    ptr as *mut i8
}
