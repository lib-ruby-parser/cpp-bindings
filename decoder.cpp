#include <cstring>
#include <utility>
#include <iostream>
#include "decoder.hpp"
#include "utils.hpp"

namespace lib_ruby_parser
{
    extern "C"
    {
        void LIB_RUBY_PARSER_drop_input_error(InputError *input_error);
        void LIB_RUBY_PARSER_drop_decoder_result(DecoderResult *decoder_result);
    }

    // input error
    InputError::Value::Value()
    {
        std::memset(this, 0, sizeof(Value));
    }

    InputError::Value::Value(InputError::Value &&other)
    {
        std::memcpy(this, &other, sizeof(Value));
        std::memset(&other, 0, sizeof(Value));
    }

    InputError::Value::~Value() {}

    InputError::Value &InputError::Value::operator=(InputError::Value &&other)
    {
        std::memcpy(this, &other, sizeof(Value));
        std::memset(&other, 0, sizeof(Value));
        return *this;
    }

    InputError::InputError(Tag tag_,
                           Value as_) : tag(tag_),
                                        as(std::move(as_)) {}

    InputError InputError::UnsupportedEncoding(String unsupported_encoding)
    {
        InputError::Value value;
        value.unsupported_encoding = std::move(unsupported_encoding);
        return InputError(InputError::Tag::UNSUPPORTED_ENCODING, std::move(value));
    }
    InputError InputError::DecodingError(String decoding_error)
    {
        InputError::Value value;
        value.decoding_error = std::move(decoding_error);
        return InputError(InputError::Tag::DECODING_ERROR, std::move(value));
    }

    InputError::~InputError()
    {
        LIB_RUBY_PARSER_drop_input_error(this);
    }

    // decoder result
    DecoderResult::Value::Value()
    {
        std::memset(this, 0, sizeof(Value));
    }
    DecoderResult::Value::Value(Value &&other)
    {
        std::memcpy(this, &other, sizeof(Value));
        std::memset(&other, 0, sizeof(Value));
    }
    DecoderResult::Value::~Value() {}

    DecoderResult::DecoderResult(Tag tag_,
                                 Value as_) : tag(tag_),
                                              as(std::move(as_)) {}
    DecoderResult::~DecoderResult()
    {
        LIB_RUBY_PARSER_drop_decoder_result(this);
    }

    DecoderResult DecoderResult::Ok(ByteList decoded)
    {
        DecoderResult::Value value;
        value.ok = std::move(decoded);
        return DecoderResult(DecoderResult::Tag::OK, std::move(value));
    }
    DecoderResult DecoderResult::Err(InputError err)
    {
        DecoderResult::Value value;
        value.err = std::move(err);
        return DecoderResult(DecoderResult::Tag::ERR, std::move(value));
    }

    // decoder
    Decoder::Decoder(DecoderFunction f_) : f(f_) {}

    // maybe decoder
    MaybeDecoder::MaybeDecoder(Decoder decoder_) : decoder(decoder_) {}
    MaybeDecoder MaybeDecoder::Some(Decoder decoder_)
    {
        return MaybeDecoder(decoder_);
    }
    MaybeDecoder MaybeDecoder::None()
    {
        return MaybeDecoder(Decoder(nullptr));
    }

    bool MaybeDecoder::is_some() const
    {
        return this->decoder.f != nullptr;
    }
    bool MaybeDecoder::is_none() const
    {
        return this->decoder.f == nullptr;
    }
}

// #ifdef TEST_ENV

#include "test_helper.hpp"

namespace lib_ruby_parser
{
    BLOB(String);
    BLOB(InputError);
    BLOB(ByteList);
    BLOB(DecoderResult);
    BLOB(Decoder);
    BLOB(MaybeDecoder);

    extern "C"
    {
        InputErrorBlob lib_ruby_parser__test__make_input_error__unsupported_encoding(
            StringBlob unsupported_encoding);
        InputErrorBlob lib_ruby_parser__test__make_input_error__decoding_error(
            StringBlob decoding_error);
    }

    static const char *US_ASCII = "us-ascii";

    static void test_input_error_fields(void)
    {
        annotate_test;

        InputError input_error1 =
            from_blob<InputErrorBlob, InputError>(
                lib_ruby_parser__test__make_input_error__unsupported_encoding(
                    into_blob<String, StringBlob>(
                        String::Copied(US_ASCII))));
        assert_eq(input_error1.tag, InputError::Tag::UNSUPPORTED_ENCODING);
        assert_string_eq(input_error1.as.unsupported_encoding, US_ASCII);

        InputError input_error2 =
            from_blob<InputErrorBlob, InputError>(
                lib_ruby_parser__test__make_input_error__decoding_error(
                    into_blob<String, StringBlob>(String::Copied("bar"))));
        assert_eq(input_error2.tag, InputError::Tag::DECODING_ERROR);
        assert_string_eq(input_error2.as.decoding_error, "bar");
    }

    extern "C"
    {
        DecoderResultBlob lib_ruby_parser__test__make_decoder_result__ok(ByteListBlob bytes);
        DecoderResultBlob lib_ruby_parser__test__make_decoder_result__err(InputErrorBlob err);
    }

    static void test_decoder_result_fields(void)
    {
        annotate_test;

        DecoderResult ok_result = from_blob<DecoderResultBlob, DecoderResult>(
            lib_ruby_parser__test__make_decoder_result__ok(
                into_blob<ByteList, ByteListBlob>(
                    ByteList::Copied("bar", 3))));
        assert_eq(ok_result.tag, DecoderResult::Tag::OK);
        assert_byte_list(ok_result.as.ok, "bar");

        DecoderResult err_result = from_blob<DecoderResultBlob, DecoderResult>(
            lib_ruby_parser__test__make_decoder_result__err(
                lib_ruby_parser__test__make_input_error__unsupported_encoding(
                    into_blob<String, StringBlob>(String::Copied(US_ASCII)))));
        assert_eq(err_result.tag, DecoderResult::Tag::ERR);
        assert_eq(err_result.as.err.tag, InputError::Tag::UNSUPPORTED_ENCODING);
        assert_string_eq(err_result.as.err.as.unsupported_encoding, US_ASCII);
    }

    extern "C"
    {
        DecoderBlob lib_ruby_parser__test__always_ok_decoder(void);
        DecoderBlob lib_ruby_parser__test__always_err_decoder(void);
    }
    static DecoderResult call_decoder(Decoder decoder, String encoding, ByteList input)
    {
        StringBlob encoding_blob = into_blob<String, StringBlob>(std::move(encoding));
        ByteListBlob input_blob = into_blob<ByteList, ByteListBlob>(std::move(input));
        // cast fn from
        // (String, ByteList) -> DecoderResult
        // to
        // (StringBlob, ByteListBlob) -> DecoderResultBlob
        typedef DecoderResultBlob (*DecoderFunctionBlob)(StringBlob, ByteListBlob);
        DecoderFunctionBlob fn_blob =
            reinterpret_cast<DecoderFunctionBlob>(
                reinterpret_cast<void *>(
                    decoder.f));
        DecoderResultBlob result_blob = fn_blob(encoding_blob, input_blob);
        return from_blob<DecoderResultBlob, DecoderResult>(result_blob);
    }

    static void test_decoder_fields(void)
    {
        annotate_test;

        const char *ALWAYS_OK = "always_ok";
        const char *ALWAYS_ERR = "always_err";

        Decoder ok_decoder = from_blob<DecoderBlob, Decoder>(
            lib_ruby_parser__test__always_ok_decoder());
        DecoderResult ok_decoder_result = call_decoder(ok_decoder, String::Copied("utf-8"), ByteList::Copied("2 + 2", 5));
        assert_eq(ok_decoder_result.tag, DecoderResult::Tag::OK);
        assert_byte_list(ok_decoder_result.as.ok, ALWAYS_OK);

        Decoder err_decoder = from_blob<DecoderBlob, Decoder>(
            lib_ruby_parser__test__always_err_decoder());
        DecoderResult err_decoder_result = call_decoder(err_decoder, String::Copied("utf-8"), ByteList::Copied("2 + 2", 5));
        assert_eq(err_decoder_result.as.err.tag, InputError::Tag::DECODING_ERROR);
        assert_string_eq(err_decoder_result.as.err.as.unsupported_encoding, ALWAYS_ERR);
    }

    extern "C"
    {
        MaybeDecoderBlob lib_ruby_parser__test__some_always_ok_decoder(void);
        MaybeDecoderBlob lib_ruby_parser__test__none_decoder(void);
    }
    static void test_maybe_decoder_fields(void)
    {
        annotate_test;

        Decoder always_ok_decoder = from_blob<DecoderBlob, Decoder>(
            lib_ruby_parser__test__always_ok_decoder());

        MaybeDecoder some_decoder = from_blob<MaybeDecoderBlob, MaybeDecoder>(
            lib_ruby_parser__test__some_always_ok_decoder());
        assert(some_decoder.is_some());

        assert_eq(some_decoder.decoder.f, always_ok_decoder.f);
        MaybeDecoder none_decoder = from_blob<MaybeDecoderBlob, MaybeDecoder>(
            lib_ruby_parser__test__none_decoder());
        assert(none_decoder.is_none());
    }

    void run_test_group_decoder(void)
    {
        const test_fn_t tests[] = {
            test_input_error_fields,
            test_decoder_result_fields,
            test_decoder_fields,
            test_maybe_decoder_fields,
        };

        run_tests_as_group("decoder", tests, sizeof(tests) / sizeof(test_fn_t));
    }
}

// #endif
