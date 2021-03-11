#ifndef LIB_RUBY_PARSER_TOKEN_H
#define LIB_RUBY_PARSER_TOKEN_H

#include <string>
#include <stdint.h>
#include <iostream>
#include <memory>
#include "bytes.h"
#include "loc.h"

namespace lib_ruby_parser
{
    // A token that is emitted by a lexer and consumed by a parser
    class Token
    {
    public:
        // Numeric representation of the token type.
        //
        // Can be used for fast comparison, but values are not guaranteed to be the same
        // across all versions of lib-ruby-parser, so don't persist it.
        int token_type;

        // Value of the token
        Bytes token_value;

        // Location of the token
        std::unique_ptr<Loc> loc;

        Token() = delete;
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

        // Returns human-readable name of the token type
        std::string name() const;
    };

} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_TOKEN_H
