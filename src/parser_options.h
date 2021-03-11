#ifndef LIB_RUBY_PARSER_PARSER_OPTIONS_H
#define LIB_RUBY_PARSER_PARSER_OPTIONS_H

#include <string>
#include <memory>
#include "custom_decoder.h"
#include "token_rewriter.h"

namespace lib_ruby_parser
{
    // Options to configure parsing
    class ParserOptions
    {
    public:
        // Name of the buffer you want to parse (appears in diagnostic messages)
        std::string buffer_name;

        // Boolean flag that enables debug printing (used for development)
        bool debug;

        // Custom decoder that is used when input has unsupported encoding
        std::unique_ptr<CustomDecoder> custom_decoder;

        // Token rewriter that can replace tokens on-the-fly
        std::unique_ptr<TokenRewriter> token_rewriter;

        // Boolean flag that (when enabled) enables recoding tokens in `ParserResult::tokens`.
        // When diables `ParserResult::tokens` is always empty
        bool record_tokens;

        explicit ParserOptions();
        ParserOptions(const ParserOptions &options) = delete;
        ParserOptions(ParserOptions &&options) = default;

        explicit ParserOptions(
            std::string buffer_name,
            bool debug,
            std::unique_ptr<CustomDecoder> custom_decoder,
            std::unique_ptr<TokenRewriter> token_rewriter,
            bool record_tokens);
    };

} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_PARSER_OPTIONS_H
