#ifndef LIB_RUBY_PARSER_PARSER_RESULT_H
#define LIB_RUBY_PARSER_PARSER_RESULT_H

#include <string>
#include "gen.h"
#include "token.h"

namespace lib_ruby_parser
{
    class ParserResult
    {
    public:
        ParserResult() = delete;
        explicit ParserResult(std::unique_ptr<Node> ast, std::vector<Token> tokens) : ast(std::move(ast)), tokens(std::move(tokens)) {}

        std::unique_ptr<Node> ast;
        std::vector<Token> tokens;

        static std::unique_ptr<ParserResult> from_source(std::string source);
    };

    extern "C"
    {
        extern ParserResult *parse(const char *code, size_t len);

        ParserResult *make_parser_result(Node *ast, Token **tokens, size_t tokens_len)
        {
            return new ParserResult(std::unique_ptr<Node>(ast), ptr_to_vec(tokens, tokens_len));
        }
    }

    std::unique_ptr<ParserResult> ParserResult::from_source(std::string source)
    {
        return std::unique_ptr<ParserResult>(parse(source.c_str(), source.length()));
    }
} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_PARSER_RESULT_H
