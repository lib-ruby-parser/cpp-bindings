#ifndef LIB_RUBY_PARSER_TOKEN_CUSTOM_DECODER_H
#define LIB_RUBY_PARSER_TOKEN_CUSTOM_DECODER_H

#include <string>
#include <vector>
#include "range.h"
#include "bytes.h"

namespace lib_ruby_parser
{
    class CustomDecoder
    {
    public:
        class Result
        {
        public:
            bool success;
            Bytes output;
            std::string error_message;

            Result() = default;
            Result(Result &&) = default;
            Result(const Result &) = delete;

            static Result Ok(Bytes output);
            static Result Error(std::string error_message);
        };

        virtual Result rewrite(std::string encoding, Bytes input) = 0;
        virtual ~CustomDecoder(){};
    };

    extern "C"
    {
        struct CustomDecoderResult
        {
            bool success;

            char *output;
            size_t output_length;

            char *error_message;
            size_t error_message_length;

            static CustomDecoderResult Ok(char *output, size_t length);
            static CustomDecoderResult Error(char *error_message, size_t length);
        };

        CustomDecoderResult rewrite(CustomDecoder *decoder, const char *encoding_ptr, size_t encoding_length, const char *input_ptr, size_t input_length);
    }
} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_TOKEN_CUSTOM_DECODER_H
