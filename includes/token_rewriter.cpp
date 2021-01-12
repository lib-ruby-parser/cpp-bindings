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

    Token token_from_raw_token(RawToken raw_token)
    {
        return Token(
            raw_token.token_type,
            std::string(raw_token.token_value_ptr, raw_token.token_value_len),
            std::make_unique<Loc>(
                raw_token.loc_begin,
                raw_token.loc_end));
    }

    RawToken raw_token_to_token(Token token)
    {
        RawToken result;
        result.token_type = token.token_type;
        result.token_value_ptr = string_to_char_ptr(token.token_value);
        result.token_value_len = token.token_value.length();
        result.loc_begin = token.loc->begin;
        result.loc_end = token.loc->end;
        return result;
    }

    extern "C"
    {
        RawTokenRewriterResult rewrite_token(TokenRewriter *rewriter, RawToken raw_token, const char *input_ptr, size_t input_len)
        {
            auto token = token_from_raw_token(raw_token);
            auto input = Bytes(input_ptr, input_len);

            auto cpp_result = rewriter->rewrite_token(std::move(token), std::move(input));

            RawTokenRewriterResult c_result;

            switch (cpp_result.lex_state_action.kind)
            {
            case TokenRewriter::LexStateAction::Kind::SET:
                c_result.lex_state_action = RawLexStateAction::LEX_STATE_SET;
                c_result.next_state = cpp_result.lex_state_action.next_state;
                break;
            case TokenRewriter::LexStateAction::Kind::KEEP:
                c_result.lex_state_action = RawLexStateAction::LEX_STATE_KEEP;
            default:
                break;
            }

            switch (cpp_result.rewrite_action)
            {
            case TokenRewriter::RewriteAction::KEEP:
                c_result.rewrite_action = RawRewriteAction::REWRITE_ACTION_KEEP;
                break;
            case TokenRewriter::RewriteAction::DROP:
                c_result.rewrite_action = RawRewriteAction::REWRITE_ACTION_DROP;
                break;

            default:
                break;
            }
            c_result.token = raw_token_to_token(std::move(cpp_result.token));

            return c_result;
        }
    }
} // namespace lib_ruby_parser
