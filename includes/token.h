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

        std::string name();
    };

    extern "C"
    {
        Loc *make_loc(size_t begin, size_t end);
        Token *make_token(int token_type, char *token_value, Loc *loc);
        extern char *token_name(int id);
    }
} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_TOKEN_H
