#ifndef LIB_RUBY_PARSER_TOKEN_H
#define LIB_RUBY_PARSER_TOKEN_H

#include <string>
#include <cstddef>
#include "helpers.h"
#include "bytes.h"
#include <iostream>
#include <memory>

namespace lib_ruby_parser
{
    class Token
    {
    public:
        int token_type;
        Bytes token_value;
        std::unique_ptr<Loc> loc;

        Token() = default;
        Token(Token &&) = default;
        Token(const Token &) = delete;
        Token &operator=(Token &&) = default;
        explicit Token(
            int token_type,
            Bytes token_value,
            std::unique_ptr<Loc> loc);

        friend std::ostream &operator<<(std::ostream &os, const Token &token);

        bool operator==(const Token &other);
        bool operator!=(const Token &other);

        std::string name();
    };

} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_TOKEN_H
