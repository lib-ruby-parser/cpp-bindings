#ifndef LIB_RUBY_PARSER_TOKEN_CUSTOM_DECODER_H
#define LIB_RUBY_PARSER_TOKEN_CUSTOM_DECODER_H

#include <string>
#include <vector>
#include <variant>
#include "bytes.h"

namespace lib_ruby_parser
{
    // Base class responsible for decoding unsupported encodings (other than ascii-8bit/utf-8)
    class CustomDecoder
    {
    public:
        // Utility class that is used to return data from a custom decoder
        class Result
        {
        public:
            std::variant<Bytes, std::string> data;

            Result() = delete;
            explicit Result(Bytes output);
            explicit Result(std::string error_message);

            Result(Result &&) = default;
            Result(const Result &) = delete;

            // Constructs "ok" response with re-encoded input
            static Result Ok(Bytes output);

            // Constructs "error" response with error message
            static Result Error(std::string error_message);
        };

        // A method that must be overwritten in child classes.
        //
        // It takes recognized encoding + input.
        // It must return either `Result::Ok(decoded)` or `Result::Error(error_message)`
        virtual Result rewrite(const std::string &encoding, const Bytes &input) = 0;
        virtual ~CustomDecoder();
    };

} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_TOKEN_CUSTOM_DECODER_H
