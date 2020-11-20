use crate::bindings::{
    make_diagnostic, make_loc, make_parser_result, make_range, make_token, size_t, Diagnostic,
    ErrorLevel_ERROR, ErrorLevel_WARNING, ParserResult, Range, Token,
};
use crate::NodePtr;
use crate::{map_vec_to_c_list, string_to_ptr};

pub trait CppFromRust<T> {
    fn convert(value: T) -> *mut Self;
}

impl CppFromRust<lib_ruby_parser::ParserResult> for ParserResult {
    fn convert(parser_result: lib_ruby_parser::ParserResult) -> *mut Self {
        let lib_ruby_parser::ParserResult {
            ast,
            tokens,
            diagnostics,
            ..
        } = parser_result;

        let ast = NodePtr::from(ast).unwrap();
        let (tokens, tokens_len) = map_vec_to_c_list(tokens, CppFromRust::convert);
        let (diagnostics, diagnostics_len) = map_vec_to_c_list(diagnostics, CppFromRust::convert);

        unsafe { make_parser_result(ast, tokens, tokens_len, diagnostics, diagnostics_len) }
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

impl CppFromRust<lib_ruby_parser::Diagnostic> for Diagnostic {
    fn convert(diagnostic: lib_ruby_parser::Diagnostic) -> *mut Self {
        let level = match diagnostic.level {
            lib_ruby_parser::ErrorLevel::Warning => ErrorLevel_WARNING,
            lib_ruby_parser::ErrorLevel::Error => ErrorLevel_ERROR,
        };
        let (message, message_len) = string_to_ptr(diagnostic.render_message());
        let range = CppFromRust::convert(diagnostic.range);
        unsafe { make_diagnostic(level, message, message_len, range) }
    }
}

impl CppFromRust<lib_ruby_parser::source::Range> for Range {
    fn convert(range: lib_ruby_parser::source::Range) -> *mut Self {
        unsafe { make_range(range.begin_pos as size_t, range.end_pos as size_t) }
    }
}
