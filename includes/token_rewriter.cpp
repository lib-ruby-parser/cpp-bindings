#include "token_rewriter.h"
#include "helpers.h"
#include <iostream>

namespace lib_ruby_parser
{
    TokenRewriter::LexStateAction TokenRewriter::LexStateAction::Set(int next_state)
    {
        TokenRewriter::LexStateAction result;
        result.kind = TokenRewriter::LexStateAction::Kind::SET;
        result.next_state = next_state;
        return result;
    }

    TokenRewriter::LexStateAction TokenRewriter::LexStateAction::Keep()
    {
        TokenRewriter::LexStateAction result;
        result.kind = TokenRewriter::LexStateAction::Kind::KEEP;
        return result;
    }

    TokenRewriter::Result::Result(Token token, TokenRewriter::RewriteAction rewrite_action, TokenRewriter::LexStateAction lex_state_action)
    {
        this->token = std::move(token);
        this->rewrite_action = rewrite_action;
        this->lex_state_action = lex_state_action;
    }
} // namespace lib_ruby_parser
