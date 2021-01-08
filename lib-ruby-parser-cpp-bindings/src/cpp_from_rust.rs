use crate::bindings::{
    make_comment, make_diagnostic, make_loc, make_magic_comment, make_parser_result, make_range,
    make_token, size_t, Comment, CommentType, Diagnostic, ErrorLevel, MagicComment,
    MagicCommentKind, ParserResult, Range, Token,
};
use crate::helpers::string_to_char_ptr;
use crate::NodePtr;
use crate::{input_to_ptr, map_vec_to_c_list};

pub trait CppFromRust<T> {
    fn convert(value: T) -> *mut Self;
}

impl CppFromRust<lib_ruby_parser::ParserResult> for ParserResult {
    fn convert(parser_result: lib_ruby_parser::ParserResult) -> *mut Self {
        let lib_ruby_parser::ParserResult {
            ast,
            tokens,
            diagnostics,
            comments,
            magic_comments,
            input,
        } = parser_result;

        let ast = NodePtr::from(ast).unwrap();
        let (tokens, tokens_len) = map_vec_to_c_list(tokens, CppFromRust::convert);
        let (diagnostics, diagnostics_len) = map_vec_to_c_list(diagnostics, CppFromRust::convert);
        let (comments, comments_len) = map_vec_to_c_list(comments, CppFromRust::convert);
        let (magic_comments, magic_comments_len) =
            map_vec_to_c_list(magic_comments, CppFromRust::convert);
        let input = input_to_ptr(input);

        unsafe {
            make_parser_result(
                ast,
                tokens,
                tokens_len,
                diagnostics,
                diagnostics_len,
                comments,
                comments_len,
                magic_comments,
                magic_comments_len,
                input,
            )
        }
    }
}

impl CppFromRust<lib_ruby_parser::Token> for Token {
    fn convert(token: lib_ruby_parser::Token) -> *mut Self {
        let token_value = string_to_char_ptr(token.token_value.to_string_lossy());

        unsafe {
            make_token(
                token.token_type,
                token_value,
                make_loc(token.loc.begin as size_t, token.loc.end as size_t),
            )
        }
    }
}

impl CppFromRust<lib_ruby_parser::Diagnostic> for Diagnostic {
    fn convert(diagnostic: lib_ruby_parser::Diagnostic) -> *mut Self {
        let level = match diagnostic.level {
            lib_ruby_parser::ErrorLevel::Warning => ErrorLevel::WARNING,
            lib_ruby_parser::ErrorLevel::Error => ErrorLevel::ERROR,
        };
        let message = string_to_char_ptr(diagnostic.render_message());
        let range = CppFromRust::convert(diagnostic.range);
        unsafe { make_diagnostic(level, message, range) }
    }
}

impl CppFromRust<lib_ruby_parser::source::Range> for Range {
    fn convert(range: lib_ruby_parser::source::Range) -> *mut Self {
        unsafe { make_range(range.begin_pos as size_t, range.end_pos as size_t) }
    }
}

impl CppFromRust<lib_ruby_parser::source::Comment> for Comment {
    fn convert(comment: lib_ruby_parser::source::Comment) -> *mut Self {
        let kind = match comment.kind {
            lib_ruby_parser::source::CommentType::Inline => CommentType::INLINE,
            lib_ruby_parser::source::CommentType::Document => CommentType::DOCUMENT,
            lib_ruby_parser::source::CommentType::Unknown => CommentType::UNKNOWN,
        };
        unsafe { make_comment(kind, CppFromRust::convert(comment.location)) }
    }
}

impl CppFromRust<lib_ruby_parser::source::MagicComment> for MagicComment {
    fn convert(magic_comment: lib_ruby_parser::source::MagicComment) -> *mut Self {
        let kind = match magic_comment.kind {
            lib_ruby_parser::source::MagicCommentKind::Encoding => MagicCommentKind::ENCODING,
            lib_ruby_parser::source::MagicCommentKind::FrozenStringLiteral => {
                MagicCommentKind::FROZEN_STRING_LITERAL
            }
            lib_ruby_parser::source::MagicCommentKind::WarnIndent => MagicCommentKind::WARN_INDENT,
            lib_ruby_parser::source::MagicCommentKind::ShareableContstantValue => {
                MagicCommentKind::SHAREABLE_CONSTANT_VALUE
            }
        };
        unsafe {
            make_magic_comment(
                kind,
                CppFromRust::convert(magic_comment.key_l),
                CppFromRust::convert(magic_comment.value_l),
            )
        }
    }
}
