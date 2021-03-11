#ifndef LIB_RUBY_PARSER_TOKEN_REWRITER_H
#define LIB_RUBY_PARSER_TOKEN_REWRITER_H

#include <string>
#include "token.h"
#include "bytes.h"

namespace lib_ruby_parser
{
    // Base class for all token rewriters.
    class TokenRewriter
    {
    public:
        // Enum that controls dropping or keeping individual tokens.
        enum class RewriteAction
        {
            DROP,
            KEEP
        };

        // Enum that controls keeping and changing the state of the lexer after emitting
        // individual tokens.
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

        // Utility class that represents response of the TokenRewriter
        class Result
        {
        public:
            Token token;
            RewriteAction rewrite_action;
            LexStateAction lex_state_action;
            Result() = delete;
            explicit Result(Token token,
                            TokenRewriter::RewriteAction rewrite_action,
                            LexStateAction lex_state_action);
        };

        // Abstract method that must be implemented in base classes to perform rewriting.
        //
        // It takes a token that was emitted by a lexer (but not yet given to a parser) and original input.
        //
        // It can return `RewriteAction::DROP` to drop this token
        //
        // It can return `LexStateAction::Set(new state)` to change lexer state and force it to handle the rest of the input
        // in a differnt way.
        //
        // It can even return a new token
        virtual Result rewrite_token(Token &token, const Bytes &input) = 0;
        virtual ~TokenRewriter();
    };

} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_TOKEN_REWRITER_H
