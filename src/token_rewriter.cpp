#include "token_rewriter.h"

namespace lib_ruby_parser
{
    TokenRewriter::Result::Result(
        Token token,
        TokenRewriter::RewriteAction rewrite_action,
        LexStateAction lex_state_action) : token(std::move(token)),
                                           rewrite_action(rewrite_action),
                                           lex_state_action(lex_state_action){};

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

    TokenRewriter::~TokenRewriter() {}
} // namespace lib_ruby_parser
