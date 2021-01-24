use crate::bindings;
use crate::Ptr;

fn map_vec_to_c_list<Source, Target>(
    vec: Vec<Source>,
    f: fn(Source) -> Ptr<Target>,
) -> (*mut *mut Target, bindings::size_t) {
    let vec = vec.into_iter().map(|i| f(i).unwrap()).collect::<Vec<_>>();
    let slice = Box::leak(vec.into_boxed_slice());
    (slice.as_mut_ptr(), slice.len() as bindings::size_t)
}

impl From<Vec<lib_ruby_parser::Token>> for bindings::TokenVec {
    fn from(tokens: Vec<lib_ruby_parser::Token>) -> Self {
        let (ptr, length) = map_vec_to_c_list(tokens, From::from);
        bindings::TokenVec { ptr, length }
    }
}

impl From<Vec<lib_ruby_parser::Diagnostic>> for bindings::DiagnosticVec {
    fn from(diagnostics: Vec<lib_ruby_parser::Diagnostic>) -> Self {
        let (ptr, length) = map_vec_to_c_list(diagnostics, From::from);
        bindings::DiagnosticVec { ptr, length }
    }
}

impl From<Vec<lib_ruby_parser::source::Comment>> for bindings::CommentVec {
    fn from(comments: Vec<lib_ruby_parser::source::Comment>) -> Self {
        let (ptr, length) = map_vec_to_c_list(comments, From::from);
        bindings::CommentVec { ptr, length }
    }
}

impl From<Vec<lib_ruby_parser::source::MagicComment>> for bindings::MagicCommentVec {
    fn from(magic_comments: Vec<lib_ruby_parser::source::MagicComment>) -> Self {
        let (ptr, length) = map_vec_to_c_list(magic_comments, From::from);
        bindings::MagicCommentVec { ptr, length }
    }
}

impl From<Vec<lib_ruby_parser::Node>> for bindings::NodeVec {
    fn from(nodes: Vec<lib_ruby_parser::Node>) -> Self {
        let (ptr, length) = map_vec_to_c_list(nodes, From::from);

        bindings::NodeVec { ptr, length }
    }
}
