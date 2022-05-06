#ifndef LIB_RUBY_PARSER_TOKEN_REWRITER_HPP
#define LIB_RUBY_PARSER_TOKEN_REWRITER_HPP

#include <cstdint>
#include <cstdbool>
#include "token.hpp"
#include "shared_byte_list.hpp"

namespace lib_ruby_parser
{
    enum class RewriteAction
    {
        DROP,
        KEEP
    };

    class LexStateAction
    {
    public:
        enum class Tag
        {
            SET,
            KEEP
        };

        union Value
        {
            int32_t set;
        };

        Tag tag;
        Value as;
    };

    class TokenRewriterResult
    {
    public:
        Token *rewritten_token;
        RewriteAction token_action;
        LexStateAction lex_state_action;

        TokenRewriterResult(const TokenRewriterResult &) = default;
        TokenRewriterResult &operator=(TokenRewriterResult const &) = default;

        ~TokenRewriterResult();
    };

    class TokenRewriter;
    typedef TokenRewriterResult (*TokenRewriterFunction)(Token *, SharedByteList);
    class TokenRewriter
    {
    public:
        TokenRewriterFunction f;

        explicit TokenRewriter(TokenRewriterFunction f);
    };

    class MaybeTokenRewriter
    {
    public:
        TokenRewriter token_rewriter;

        explicit MaybeTokenRewriter(TokenRewriter token_rewriter);

        bool is_some() const;
        bool is_none() const;

        static MaybeTokenRewriter Some(TokenRewriter decoder);
        static MaybeTokenRewriter None();
    };
} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_TOKEN_REWRITER_HPP
