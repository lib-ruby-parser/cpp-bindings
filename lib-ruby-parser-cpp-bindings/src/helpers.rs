use crate::bindings::{size_t, Node};
use crate::CppFromRust;
use std::ffi::CString;

pub fn ptr_value<T>(value: T) -> *mut T {
    Box::into_raw(Box::new(value))
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

pub fn nodes_to_ptr(nodes: Vec<lib_ruby_parser::Node>) -> (*mut Node, size_t) {
    let nodes: Vec<Node> = nodes
        .into_iter()
        .map(|node| *unsafe { Box::from_raw(CppFromRust::convert(node)) })
        .collect();

    let len = nodes.len() as size_t;
    let mut boxed_slice = nodes.into_boxed_slice();
    let ptr = boxed_slice.as_mut_ptr();
    std::mem::forget(boxed_slice);
    (ptr, len)
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

pub fn input_to_ptr(input: lib_ruby_parser::source::buffer::Input) -> (*mut i8, size_t) {
    let len = input.len() as size_t;
    let mut bytes = CString::new(input.bytes).unwrap().into_bytes_with_nul();
    let ptr = bytes.as_mut_ptr();
    std::mem::forget(bytes);
    (ptr as *mut i8, len)
}
