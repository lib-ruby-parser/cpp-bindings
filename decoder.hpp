#ifndef LIB_RUBY_PARSER_DECODER_HPP
#define LIB_RUBY_PARSER_DECODER_HPP

#include <cstdbool>
#include <cstring>
#include "string.hpp"
#include "bytes.hpp"

namespace lib_ruby_parser
{
    class InputError
    {
    public:
        enum class Tag
        {
            UNSUPPORTED_ENCODING,
            DECODING_ERROR
        };

        union Value
        {
            String unsupported_encoding;
            String decoding_error;

            Value();
            Value(Value &&);
            ~Value();

            Value &operator=(Value &&);
        };

        Tag tag;
        Value as;

        InputError(Tag tag, Value as);
        InputError(InputError &&) = default;
        ~InputError();

        InputError &operator=(InputError &&) = default;

        static InputError UnsupportedEncoding(String unsupported_encoding);
        static InputError DecodingError(String decoding_error);
    };

    struct DecoderResult
    {
        enum class Tag
        {
            OK,
            ERR
        };

        union Value
        {
            ByteList ok;
            InputError err;

            Value();
            Value(Value &&);
            Value &operator=(Value &&);
            ~Value();
        };

        Tag tag;
        Value as;

        DecoderResult(Tag tag, Value as);
        DecoderResult(DecoderResult &&) = default;
        DecoderResult &operator=(DecoderResult &&) = default;
        ~DecoderResult();

        static DecoderResult Ok(ByteList decoded);
        static DecoderResult Err(InputError err);
    };

    extern "C"
    {
        struct DecoderResultBlob
        {
            uint8_t bytes[sizeof(DecoderResult)];
        };
    }

    String string_from_string_blob(StringBlob blob);
    ByteList byte_list_from_byte_list_blob(ByteListBlob blob);
    DecoderResultBlob decoder_result_to_blob(DecoderResult decoder_result);

    extern "C"
    {
        typedef DecoderResultBlob (*DecoderFunction)(void *, StringBlob, ByteListBlob);
    }
    class Decoder
    {
    public:
        DecoderFunction f;
        void *state;

        explicit Decoder(DecoderFunction f, void *state);
    };

    class MaybeDecoder
    {
    public:
        Decoder decoder;

        bool is_some() const;
        bool is_none() const;

        explicit MaybeDecoder(Decoder decoder);

        static MaybeDecoder Some(Decoder decoder);
        static MaybeDecoder None();
    };
} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_DECODER_HPP
