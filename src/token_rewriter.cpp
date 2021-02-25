#include "token_rewriter.h"

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
} // namespace lib_ruby_parser
