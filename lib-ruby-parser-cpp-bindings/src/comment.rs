use crate::bindings;
use crate::Ptr;

impl From<lib_ruby_parser::source::CommentType> for bindings::CommentType {
    fn from(kind: lib_ruby_parser::source::CommentType) -> Self {
        match kind {
            lib_ruby_parser::source::CommentType::Inline => bindings::CommentType::INLINE,
            lib_ruby_parser::source::CommentType::Document => bindings::CommentType::DOCUMENT,
            lib_ruby_parser::source::CommentType::Unknown => bindings::CommentType::UNKNOWN,
        }
    }
}

impl From<lib_ruby_parser::source::Comment> for Ptr<bindings::Comment> {
    fn from(comment: lib_ruby_parser::source::Comment) -> Self {
        let ptr = unsafe {
            bindings::make_comment(
                bindings::CommentType::from(comment.kind),
                Ptr::<bindings::Loc>::from(comment.location).unwrap(),
            )
        };
        Ptr::new(ptr)
    }
}
