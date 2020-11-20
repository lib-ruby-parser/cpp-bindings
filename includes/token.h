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
        Loc() = delete;
        Loc(Loc &&) = default;
        Loc(const Loc &) = delete;
        explicit Loc(size_t begin, size_t end) : begin(begin), end(end) {}

        size_t begin;
        size_t end;
        friend std::ostream &operator<<(std::ostream &os, const Loc &loc)
        {
            os << loc.begin << "..." << loc.end;
            return os;
        }

        inline bool operator==(const Loc &other)
        {
            return (begin == other.begin) && (end == other.end);
        }

        inline bool operator!=(const Loc &other)
        {
            return (begin != other.begin) || (end != other.end);
        }
    };

    class Token
    {
    public:
        Token() = delete;
        Token(Token &&) = default;
        Token(const Token &) = delete;
        explicit Token(int token_type, std::string token_value, std::unique_ptr<Loc> loc) : token_type(token_type), token_value(token_value), loc(std::move(loc)) {}
        int token_type;
        std::string token_value;
        std::unique_ptr<Loc> loc;

        friend std::ostream &operator<<(std::ostream &os, const Token &token)
        {
            os << "[" << token.token_type << ", " << token.token_value << ", " << *(token.loc.get()) << "]";
            return os;
        }

        inline bool operator==(const Token &other)
        {
            return (token_type == other.token_type) && (token_value == other.token_value) && (*(loc.get()) == *(other.loc.get()));
        }

        inline bool operator!=(const Token &other)
        {
            return !(*this == other);
        }
    };

    extern "C"
    {
        Loc *make_loc(size_t begin, size_t end)
        {
            return new Loc(begin, end);
        }

        Token *make_token(int token_type, char *token_value, size_t token_value_len, Loc *loc)
        {
            auto s = char_ptr_to_string(token_value, token_value_len);
            auto l = std::unique_ptr<Loc>(loc);
            return new Token(token_type, s, std::move(l));
        }
    }

} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_TOKEN_H
