#ifndef LIB_RUBY_PARSER_TOKEN_H
#define LIB_RUBY_PARSER_TOKEN_H

#include <string>
#include "helpers.h"
#include <iostream>

namespace lib_ruby_parser
{
    class Loc
    {
    public:
        size_t begin;
        size_t end;

        Loc() = delete;
        Loc(Loc &&) = default;
        Loc(const Loc &) = delete;
        explicit Loc(size_t begin, size_t end);
        friend std::ostream &operator<<(std::ostream &os, const Loc &loc);

        inline bool operator==(const Loc &other);
        inline bool operator!=(const Loc &other);
    };

    class Token
    {
    public:
        int token_type;
        std::string token_value;
        std::unique_ptr<Loc> loc;

        Token() = delete;
        Token(Token &&) = default;
        Token(const Token &) = delete;
        explicit Token(
            int token_type,
            std::string token_value,
            std::unique_ptr<Loc> loc);

        friend std::ostream &operator<<(std::ostream &os, const Token &token);

        inline bool operator==(const Token &other);
        inline bool operator!=(const Token &other);

        std::string name();
    };

    extern "C"
    {
        Loc *make_loc(size_t begin, size_t end);
        Token *make_token(int token_type, char *token_value, Loc *loc);
    }
} // namespace lib_ruby_parser

extern "C"
{
    char *token_name(int id);
}

#endif // LIB_RUBY_PARSER_TOKEN_H
