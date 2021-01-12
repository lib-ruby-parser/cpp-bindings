#include <cstring>
#include "parser_options.h"

namespace lib_ruby_parser
{
    ParserOptions::ParserOptions()
    {
        this->buffer_name = "(eval)";
        this->debug = false;
        this->custom_decoder = nullptr;
        this->token_rewriter = nullptr;
        this->record_tokens = false;
    }

    ParserOptions::ParserOptions(
        std::string buffer_name,
        bool debug,
        std::unique_ptr<CustomDecoder> custom_decoder,
        std::unique_ptr<TokenRewriter> token_rewriter,
        bool record_tokens)
    {
        this->buffer_name = buffer_name;
        this->debug = debug;
        this->custom_decoder = std::move(custom_decoder);
        this->token_rewriter = std::move(token_rewriter);
        this->record_tokens = record_tokens;
    }

    extern "C"
    {
        const char *parser_options_buffer_name(ParserOptions *options)
        {
            return options->buffer_name.c_str();
        }

        CustomDecoder *parser_options_custom_decoder(ParserOptions *options)
        {
            return options->custom_decoder.get();
        }
    }
} // namespace lib_ruby_parser
