#include "token_rewriter.hpp"
#include "utils.hpp"

namespace lib_ruby_parser
{
    extern "C"
    {
        void LIB_RUBY_PARSER_drop_token_rewriter_result(TokenRewriterResult *token_rewriter_result);
    }

    TokenRewriter::TokenRewriter(TokenRewriterFunction f_) : f(f_) {}

    MaybeTokenRewriter::MaybeTokenRewriter(TokenRewriter token_rewriter_) : token_rewriter(token_rewriter_) {}

    bool MaybeTokenRewriter::is_some() const
    {
        return this->token_rewriter.f != nullptr;
    }

    bool MaybeTokenRewriter::is_none() const
    {
        return this->token_rewriter.f == nullptr;
    }

    TokenRewriterResult::~TokenRewriterResult()
    {
        LIB_RUBY_PARSER_drop_token_rewriter_result(this);
    }

    MaybeTokenRewriter MaybeTokenRewriter::Some(TokenRewriter token_rewriter_)
    {
        return MaybeTokenRewriter(token_rewriter_);
    }
    MaybeTokenRewriter MaybeTokenRewriter::None()
    {
        return MaybeTokenRewriter(TokenRewriter(nullptr));
    }
} // namespace lib_ruby_parser
