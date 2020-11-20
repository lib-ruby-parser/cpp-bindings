#ifndef LIB_RUBY_PARSER_PARSER_RESULT_H
#define LIB_RUBY_PARSER_PARSER_RESULT_H

#include <string>
#include "gen.h"
#include "token.h"
#include "diagnostic.h"

namespace lib_ruby_parser
{
    class ParserResult
    {
    public:
        ParserResult() = delete;
        explicit ParserResult(
            std::unique_ptr<Node> ast,
            std::vector<Token> tokens,
            std::vector<Diagnostic> diagnostics) : ast(std::move(ast)),
                                                   tokens(std::move(tokens)),
                                                   diagnostics(std::move(diagnostics)) {}

        std::unique_ptr<Node> ast;
        std::vector<Token> tokens;
        std::vector<Diagnostic> diagnostics;

        static std::unique_ptr<ParserResult> from_source(std::string source);
    };

    extern "C"
    {
        extern ParserResult *parse(const char *code, size_t len);

        ParserResult *make_parser_result(
            Node *ast,
            Token **tokens,
            size_t tokens_len,
            Diagnostic **diagnostics,
            size_t diagnostics_len)
        {
            return new ParserResult(
                std::unique_ptr<Node>(ast),
                ptr_to_vec(tokens, tokens_len),
                ptr_to_vec(diagnostics, diagnostics_len));
        }
    }

    std::unique_ptr<ParserResult> ParserResult::from_source(std::string source)
    {
        return std::unique_ptr<ParserResult>(parse(source.c_str(), source.length()));
    }
} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_PARSER_RESULT_H
