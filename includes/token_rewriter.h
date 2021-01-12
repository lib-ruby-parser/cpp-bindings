#ifndef LIB_RUBY_PARSER_TOKEN_REWRITER_H
#define LIB_RUBY_PARSER_TOKEN_REWRITER_H

#include <string>
#include "token.h"
#include "bytes.h"
#include "helpers.h"

namespace lib_ruby_parser
{
    class TokenRewriter
    {
    public:
        enum class RewriteAction
        {
            DROP,
            KEEP
        };

        class LexStateAction
        {
        public:
            enum class Kind
            {
                SET,
                KEEP
            };
            Kind kind;
            int next_state;

            LexStateAction() = default;
            static LexStateAction Set(int next_state);
            static LexStateAction Keep();
        };

        class Result
        {
        public:
            Token token;
            RewriteAction rewrite_action;
            LexStateAction lex_state_action;
            Result() = delete;
            explicit Result(Token token, TokenRewriter::RewriteAction rewrite_action, LexStateAction lex_state_action);
        };

        virtual Result rewrite_token(Token token, Bytes input) = 0;
        virtual ~TokenRewriter() {}
    };

    extern "C"
    {
        enum RawRewriteAction
        {
            REWRITE_ACTION_KEEP,
            REWRITE_ACTION_DROP,
        };

        enum RawLexStateAction
        {
            LEX_STATE_SET,
            LEX_STATE_KEEP
        };

        struct RawToken
        {
            int token_type;
            const char *token_value_ptr;
            size_t token_value_len;
            size_t loc_begin;
            size_t loc_end;
        };

        struct RawTokenRewriterResult
        {
            RawRewriteAction rewrite_action;
            RawLexStateAction lex_state_action;
            int next_state;

            RawToken token;
        };

        RawTokenRewriterResult rewrite_token(TokenRewriter *rewriter, RawToken token, const char *input_ptr, size_t input_len);
    }
} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_TOKEN_REWRITER_H
