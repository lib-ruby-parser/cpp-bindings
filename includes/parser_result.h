#ifndef LIB_RUBY_PARSER_PARSER_RESULT_H
#define LIB_RUBY_PARSER_PARSER_RESULT_H

#include <string>
#include <memory>
#include <cstddef>
#include "node.h"
#include "token.h"
#include "diagnostic.h"
#include "comment.h"
#include "magic_comment.h"
#include "parser_options.h"

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
            std::string input);

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

    // std::vector<Token> tokens_vec_to_cpp_vec(TokenVec tokens);
    // std::vector<Diagnostic> diagnostics_vec_to_cpp_vec(DiagnosticVec diagnostics);
    // std::vector<Comment> comments_vec_to_cpp_vec(CommentVec comments);
    // std::vector<MagicComment> magic_comments_vec_to_cpp_vec(MagicCommentVec magic_comments);

    ParserResult *make_parser_result(
        Node *ast,
        TokenVec tokens,
        DiagnosticVec diagnostics,
        CommentVec comments,
        MagicCommentVec magic_comments,
        char *input);
} // namespace lib_ruby_parser

extern "C"
{
    lib_ruby_parser::ParserResult *parse(const char *code, size_t len, lib_ruby_parser::ParserOptions *options);
}

#endif // LIB_RUBY_PARSER_PARSER_RESULT_H
