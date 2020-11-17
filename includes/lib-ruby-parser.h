#ifndef LIB_RUBY_PARSER_H
#define LIB_RUBY_PARSER_H

#include "types.h"
#include "bindings.h"
#include "gen.h"
#include "make.h"

class ParserResult
{
public:
    ParserResult() = delete;
    ParserResult(std::unique_ptr<Node> ast) : ast(std::move(ast)) {}
    std::unique_ptr<Node> ast;

    static std::unique_ptr<ParserResult> from(const char *code, size_t len);
};

extern "C"
{
    extern ParserResult *parse(const char *code, size_t len);

    ParserResult *make_parser_result(Node *ast)
    {
        return new ParserResult(std::unique_ptr<Node>(ast));
    }
}

std::unique_ptr<ParserResult> ParserResult::from(const char *code, size_t len)
{
    return std::unique_ptr<ParserResult>(parse(code, len));
}

#endif // LIB_RUBY_PARSER_H
