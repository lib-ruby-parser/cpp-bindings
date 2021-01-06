#ifndef LIB_RUBY_PARSER_PARSER_RESULT_H
#define LIB_RUBY_PARSER_PARSER_RESULT_H

#include <string>
#include "gen.h"
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
        extern ParserResult *parse(const char *code, size_t len, ParserOptions *options);

        ParserResult *make_parser_result(
            Node *ast,
            Token **tokens,
            size_t tokens_len,
            Diagnostic **diagnostics,
            size_t diagnostics_len,
            Comment **comments,
            size_t comments_len,
            MagicComment **magic_comments,
            size_t magic_comments_len,
            char *input,
            size_t input_len)
        {
            std::cout << "make_parser_result called" << std::endl;
            return new ParserResult(
                std::unique_ptr<Node>(ast),
                ptr_to_vec(tokens, tokens_len),
                ptr_to_vec(diagnostics, diagnostics_len),
                ptr_to_vec(comments, comments_len),
                ptr_to_vec(magic_comments, magic_comments_len),
                char_ptr_to_string(input, input_len));
        }
    }

    std::unique_ptr<ParserResult> ParserResult::from_source(std::string source, ParserOptions options)
    {
        return std::unique_ptr<ParserResult>(parse(source.c_str(), source.length(), &options));
    }
} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_PARSER_RESULT_H
