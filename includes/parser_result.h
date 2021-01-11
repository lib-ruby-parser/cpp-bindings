#ifndef LIB_RUBY_PARSER_PARSER_RESULT_H
#define LIB_RUBY_PARSER_PARSER_RESULT_H

#include <string>
#include "node.h"
#include "token.h"
#include "diagnostic.h"
#include "comment.h"
#include "magic_comment.h"
#include "parser_options.h"

namespace lib_ruby_parser
{
    class ParserResult;
}

extern "C"
{
    extern lib_ruby_parser::ParserResult *parse(const char *code, size_t len, lib_ruby_parser::ParserOptions *options);
}

namespace lib_ruby_parser
{
    class ParserResult
    {
    public:
        ParserResult() = delete;
        explicit ParserResult(
            std::unique_ptr<Node> ast,
            std::vector<Token> tokens,
            std::vector<Diagnostic> diagnostics,
            std::vector<Comment> comments,
            std::vector<MagicComment> magic_comments,
            std::string input) : ast(std::move(ast)),
                                 tokens(std::move(tokens)),
                                 diagnostics(std::move(diagnostics)),
                                 comments(std::move(comments)),
                                 magic_comments(std::move(magic_comments)),
                                 input(input) {}

        std::unique_ptr<Node> ast;
        std::vector<Token> tokens;
        std::vector<Diagnostic> diagnostics;
        std::vector<Comment> comments;
        std::vector<MagicComment> magic_comments;
        std::string input;

        static std::unique_ptr<ParserResult> from_source(std::string source, ParserOptions options);
    };

    extern "C"
    {
        struct TokenVec
        {
            Token **list;
            size_t length;
        };

        struct DiagnosticVec
        {
            Diagnostic **list;
            size_t length;
        };

        struct CommentVec
        {
            Comment **list;
            size_t length;
        };

        struct MagicCommentVec
        {
            MagicComment **list;
            size_t length;
        };
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

    std::unique_ptr<ParserResult> ParserResult::from_source(std::string source, ParserOptions options)
    {
        return std::unique_ptr<ParserResult>(parse(source.c_str(), source.length(), &options));
    }
} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_PARSER_RESULT_H
