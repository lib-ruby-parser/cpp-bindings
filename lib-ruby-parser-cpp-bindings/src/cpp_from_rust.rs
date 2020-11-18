use crate::bindings::{make_parser_result, ParserResult};
use crate::NodePtr;

pub trait CppFromRust<T> {
    fn convert(value: T) -> *mut Self;
}

impl CppFromRust<lib_ruby_parser::ParserResult> for ParserResult {
    fn convert(parser_result: lib_ruby_parser::ParserResult) -> *mut Self {
        let lib_ruby_parser::ParserResult { ast, .. } = parser_result;

        let ast = NodePtr::from(ast).unwrap();

        unsafe { make_parser_result(ast) }
    }
}
