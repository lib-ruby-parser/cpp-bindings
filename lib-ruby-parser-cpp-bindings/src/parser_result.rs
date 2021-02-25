use crate::bindings;
use crate::ptr::Ptr;

impl From<lib_ruby_parser::ParserResult> for Ptr<bindings::ParserResult> {
    fn from(parser_result: lib_ruby_parser::ParserResult) -> Ptr<bindings::ParserResult> {
        let lib_ruby_parser::ParserResult {
            ast,
            tokens,
            diagnostics,
            comments,
            magic_comments,
            input,
        } = parser_result;

        let ast = Ptr::<bindings::Node>::from(ast).unwrap();

        let tokens = bindings::TokenVec::from(tokens);
        let diagnostics = bindings::DiagnosticVec::from(diagnostics);
        let comments = bindings::CommentVec::from(comments);
        let magic_comments = bindings::MagicCommentVec::from(magic_comments);

        let input = Box::into_raw(Box::new(input)) as *mut std::ffi::c_void;

        let ptr = unsafe {
            bindings::make_parser_result(ast, tokens, diagnostics, comments, magic_comments, input)
        };

        Ptr::new(ptr)
    }
}
