#include "parser_options.hpp"
#include "utils.hpp"

namespace lib_ruby_parser
{
    ParserOptions::ParserOptions(
        String buffer_name_,
        MaybeDecoder decoder_,
        MaybeTokenRewriter token_rewriter_,
        bool record_tokens_) : buffer_name(std::move(buffer_name_)),
                               decoder(decoder_),
                               token_rewriter(token_rewriter_),
                               record_tokens(record_tokens_) {}
}
