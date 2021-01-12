#include "parser_result.h"

namespace lib_ruby_parser
{
    ParserResult::ParserResult(
        std::unique_ptr<Node> ast,
        std::vector<Token> tokens,
        std::vector<Diagnostic> diagnostics,
        std::vector<Comment> comments,
        std::vector<MagicComment> magic_comments,
        std::string input)
    {
        this->ast = std::move(ast);
        this->tokens = std::move(tokens);
        this->diagnostics = std::move(diagnostics);
        this->comments = std::move(comments);
        this->magic_comments = std::move(magic_comments);
        this->input = input;
    }

    std::unique_ptr<ParserResult> ParserResult::from_source(Bytes source, ParserOptions options)
    {
        return std::unique_ptr<ParserResult>(parse(source.ptr(), source.size(), &options));
    }

    std::vector<Token> tokens_vec_to_cpp_vec(TokenVec tokens)
    {
        return ptr_to_vec<Token>(tokens.list, tokens.length);
    }

    std::vector<Diagnostic> diagnostics_vec_to_cpp_vec(DiagnosticVec diagnostics)
    {
        return ptr_to_vec<Diagnostic>(diagnostics.list, diagnostics.length);
    }

    std::vector<Comment> comments_vec_to_cpp_vec(CommentVec comments)
    {
        return ptr_to_vec<Comment>(comments.list, comments.length);
    }

    std::vector<MagicComment> magic_comments_vec_to_cpp_vec(MagicCommentVec magic_comments)
    {
        return ptr_to_vec<MagicComment>(magic_comments.list, magic_comments.length);
    }

    ParserResult *make_parser_result(
        Node *ast,
        TokenVec tokens,
        DiagnosticVec diagnostics,
        CommentVec comments,
        MagicCommentVec magic_comments,
        char *input)
    {
        return new ParserResult(
            std::unique_ptr<Node>(ast),
            tokens_vec_to_cpp_vec(tokens),
            diagnostics_vec_to_cpp_vec(diagnostics),
            comments_vec_to_cpp_vec(comments),
            magic_comments_vec_to_cpp_vec(magic_comments),
            char_ptr_to_string(input));
    }

} // namespace lib_ruby_parser
