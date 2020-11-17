use crate::bindings::{make_parser_result, make_range, size_t, Node, ParserResult, Range};

pub trait CppFromRust<T> {
    fn convert(value: T) -> *mut Self;
}

impl CppFromRust<lib_ruby_parser::source::Range> for Range {
    fn convert(range: lib_ruby_parser::source::Range) -> *mut Self {
        unsafe { make_range(range.begin_pos as size_t, range.end_pos as size_t) }
    }
}

impl CppFromRust<Option<lib_ruby_parser::source::Range>> for Range {
    fn convert(range: Option<lib_ruby_parser::source::Range>) -> *mut Self {
        match range {
            Some(range) => {
                let a: *mut Range = CppFromRust::convert(range);
                a
            }
            None => std::ptr::null_mut(),
        }
    }
}

impl CppFromRust<Option<Box<lib_ruby_parser::Node>>> for Node {
    fn convert(maybe_node: Option<Box<lib_ruby_parser::Node>>) -> *mut Self {
        match maybe_node {
            Some(node) => CppFromRust::convert(node),
            None => std::ptr::null_mut(),
        }
    }
}

impl CppFromRust<Option<lib_ruby_parser::Node>> for Node {
    fn convert(maybe_node: Option<lib_ruby_parser::Node>) -> *mut Self {
        match maybe_node {
            Some(node) => CppFromRust::convert(node),
            None => std::ptr::null_mut(),
        }
    }
}

impl CppFromRust<lib_ruby_parser::ParserResult> for ParserResult {
    fn convert(parser_result: lib_ruby_parser::ParserResult) -> *mut Self {
        let lib_ruby_parser::ParserResult { ast, .. } = parser_result;

        let ast = CppFromRust::convert(ast);

        unsafe { make_parser_result(ast) }
    }
}
