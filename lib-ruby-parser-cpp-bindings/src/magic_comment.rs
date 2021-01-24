use crate::bindings;
use crate::Ptr;

impl From<lib_ruby_parser::source::MagicCommentKind> for bindings::MagicCommentKind {
    fn from(kind: lib_ruby_parser::source::MagicCommentKind) -> Self {
        match kind {
            lib_ruby_parser::source::MagicCommentKind::Encoding => {
                bindings::MagicCommentKind::ENCODING
            }
            lib_ruby_parser::source::MagicCommentKind::FrozenStringLiteral => {
                bindings::MagicCommentKind::FROZEN_STRING_LITERAL
            }
            lib_ruby_parser::source::MagicCommentKind::WarnIndent => {
                bindings::MagicCommentKind::WARN_INDENT
            }
            lib_ruby_parser::source::MagicCommentKind::ShareableContstantValue => {
                bindings::MagicCommentKind::SHAREABLE_CONSTANT_VALUE
            }
        }
    }
}

impl From<lib_ruby_parser::source::MagicComment> for Ptr<bindings::MagicComment> {
    fn from(magic_comment: lib_ruby_parser::source::MagicComment) -> Self {
        let ptr = unsafe {
            bindings::make_magic_comment(
                bindings::MagicCommentKind::from(magic_comment.kind),
                Ptr::<bindings::Range>::from(magic_comment.key_l).unwrap(),
                Ptr::<bindings::Range>::from(magic_comment.value_l).unwrap(),
            )
        };

        Ptr::new(ptr)
    }
}
