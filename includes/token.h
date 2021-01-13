#ifndef LIB_RUBY_PARSER_TOKEN_H
#define LIB_RUBY_PARSER_TOKEN_H

#include <string>
#include <cstddef>
#include "helpers.h"
#include <iostream>
#include <memory>

namespace lib_ruby_parser
{
    class Loc
    {
    public:
        size_t begin;
        size_t end;

        Loc() = delete;
        Loc(Loc &&) = default;
        Loc(const Loc &) = default;
        explicit Loc(size_t begin, size_t end);
        friend std::ostream &operator<<(std::ostream &os, const Loc &loc);

        bool operator==(const Loc &other);
        bool operator!=(const Loc &other);
    };

    class Token
    {
    public:
        int token_type;
        std::string token_value;
        std::unique_ptr<Loc> loc;

        Token() = default;
        Token(Token &&) = default;
        Token(const Token &) = delete;
        Token &operator=(Token &&) = default;
        explicit Token(
            int token_type,
            std::string token_value,
            std::unique_ptr<Loc> loc);

        friend std::ostream &operator<<(std::ostream &os, const Token &token);

        bool operator==(const Token &other);
        bool operator!=(const Token &other);

        std::string name();
    };

} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_TOKEN_H
