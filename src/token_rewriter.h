#ifndef LIB_RUBY_PARSER_TOKEN_REWRITER_H
#define LIB_RUBY_PARSER_TOKEN_REWRITER_H

#include <string>
#include "token.h"
#include "bytes.h"

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
            explicit Result(Token token, TokenRewriter::RewriteAction rewrite_action, LexStateAction lex_state_action) : token(std::move(token)), rewrite_action(rewrite_action), lex_state_action(lex_state_action){};
        };

        virtual Result rewrite_token(Token token, Bytes input) = 0;
        virtual ~TokenRewriter() {}
    };

} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_TOKEN_REWRITER_H
