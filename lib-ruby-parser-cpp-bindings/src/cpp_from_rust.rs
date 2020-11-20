use crate::bindings::{make_loc, make_parser_result, make_token, size_t, ParserResult, Token};
use crate::NodePtr;
use crate::{map_vec_to_c_list, string_to_ptr};

pub trait CppFromRust<T> {
    fn convert(value: T) -> *mut Self;
}

impl CppFromRust<lib_ruby_parser::ParserResult> for ParserResult {
    fn convert(parser_result: lib_ruby_parser::ParserResult) -> *mut Self {
        let lib_ruby_parser::ParserResult { ast, tokens, .. } = parser_result;

        let ast = NodePtr::from(ast).unwrap();
        let (tokens, tokens_len) = map_vec_to_c_list(tokens, CppFromRust::convert);

        unsafe { make_parser_result(ast, tokens, tokens_len) }
    }
}

impl CppFromRust<lib_ruby_parser::Token> for Token {
    fn convert(token: lib_ruby_parser::Token) -> *mut Self {
        let (token_value, token_value_len) = string_to_ptr(token.token_value.to_string_lossy());

        unsafe {
            make_token(
                token.token_type,
                token_value,
                token_value_len,
                make_loc(token.loc.begin as size_t, token.loc.end as size_t),
            )
        }
    }
}
