#ifndef LIB_RUBY_PARSER_TOKEN_HPP
#define LIB_RUBY_PARSER_TOKEN_HPP

#include <string>
#include "bytes.hpp"
#include "loc.hpp"
#include "token_ids.hpp"

namespace lib_ruby_parser
{
    /// Equivalent of `lib_ruby_parser::Token`
    class Token
    {
    public:
        int32_t token_type;
        Bytes token_value;
        Loc loc;
        int32_t lex_state_before;
        int32_t lex_state_after;

        Token() = delete;
        Token(
            int32_t token_type,
            Bytes token_value,
            Loc loc,
            int32_t lex_state_before,
            int32_t lex_state_after);

        Token(const Token &) = delete;
        Token &operator=(Token const &) = delete;

        Token(Token &&) = default;
        Token &operator=(Token &&) = default;

        /// Returns token name (like "kDEF") for a given token.
        std::string token_name() const;
    };

    /// Equivalent of `Vec<lib_ruby_parser::Token>`
    class TokenList
    {
    public:
        Token *ptr;
        size_t capacity;
        size_t len;

        TokenList() = delete;
        TokenList(Token *ptr, size_t len, size_t capacity);
        ~TokenList();

        TokenList(const TokenList &) = delete;
        TokenList &operator=(TokenList const &) = delete;

        TokenList(TokenList &&);
        TokenList &operator=(TokenList &&);
    };

#ifdef TEST_ENV
    void run_test_group_token(void);
#endif
} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_TOKEN_HPP
