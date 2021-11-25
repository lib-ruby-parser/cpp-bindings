#ifndef LIB_RUBY_PARSER_DECODER_HPP
#define LIB_RUBY_PARSER_DECODER_HPP

#include <cstdbool>
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

    class DecoderResult
    {
    public:
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
            ~Value();
        };

        Tag tag;
        Value as;

        DecoderResult(Tag tag, Value as);
        DecoderResult(DecoderResult &&) = default;
        ~DecoderResult();

        static DecoderResult Ok(ByteList decoded);
        static DecoderResult Err(InputError err);
    };

    typedef DecoderResult (*DecoderFunction)(String, ByteList);
    class Decoder
    {
    public:
        DecoderFunction f;

        explicit Decoder(DecoderFunction f);
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

#ifdef TEST_ENV
    void run_test_group_decoder(void);
#endif
} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_DECODER_HPP
