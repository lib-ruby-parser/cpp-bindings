#include "test_helper.hpp"
#include "../decoder.hpp"
#include "../api.hpp"
#include "../utils.hpp"

namespace lib_ruby_parser
{
#ifndef INPUT_ERROR_HAS_BLOB
#define INPUT_ERROR_HAS_BLOB
    BLOB(InputError);
#endif // INPUT_ERROR_HAS_BLOB

#ifndef DECODER_HAS_BLOB
#define DECODER_HAS_BLOB
    BLOB(Decoder);
#endif // DECODER_HAS_BLOB

#ifndef MAYBE_DECODER_HAS_BLOB
#define MAYBE_DECODER_HAS_BLOB
    BLOB(MaybeDecoder);
#endif // MAYBE_DECODER_HAS_BLOB

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
        DecoderBlob lib_ruby_parser__test__always_ok_decoder(const char *output);
        DecoderBlob lib_ruby_parser__test__always_err_decoder(const char *output);
    }
    static DecoderResult call_decoder(Decoder decoder, void *state, String encoding, ByteList input)
    {
        StringBlob encoding_blob = into_blob<String, StringBlob>(std::move(encoding));
        ByteListBlob input_blob = into_blob<ByteList, ByteListBlob>(std::move(input));
        // cast fn from
        // (String, ByteList) -> DecoderResult
        // to
        // (StringBlob, ByteListBlob) -> DecoderResultBlob
        typedef DecoderResultBlob (*DecoderFunctionBlob)(void *, StringBlob, ByteListBlob);
        DecoderFunctionBlob fn_blob =
            reinterpret_cast<DecoderFunctionBlob>(
                reinterpret_cast<void *>(
                    decoder.f));
        DecoderResultBlob result_blob = fn_blob(state, encoding_blob, input_blob);
        return from_blob<DecoderResultBlob, DecoderResult>(result_blob);
    }

    static void test_decoder_fields(void)
    {
        annotate_test;

        Decoder ok_decoder = from_blob<DecoderBlob, Decoder>(
            lib_ruby_parser__test__always_ok_decoder("anything"));
        DecoderResult ok_decoder_result = call_decoder(ok_decoder, const_cast<char *>("foo"), String::Copied("utf-8"), ByteList::Copied("2 + 2", 5));
        assert_eq(ok_decoder_result.tag, DecoderResult::Tag::OK);
        assert_byte_list(ok_decoder_result.as.ok, "foo");

        Decoder err_decoder = from_blob<DecoderBlob, Decoder>(
            lib_ruby_parser__test__always_err_decoder("anything"));
        DecoderResult err_decoder_result = call_decoder(err_decoder, const_cast<char *>("bar"), String::Copied("utf-8"), ByteList::Copied("2 + 2", 5));
        assert_eq(err_decoder_result.as.err.tag, InputError::Tag::DECODING_ERROR);
        assert_string_eq(err_decoder_result.as.err.as.unsupported_encoding, "bar");
    }

    extern "C"
    {
        MaybeDecoderBlob lib_ruby_parser__test__some_always_ok_decoder(const char *output);
        MaybeDecoderBlob lib_ruby_parser__test__none_decoder(void);
    }
    static void test_maybe_decoder_fields(void)
    {
        annotate_test;

        Decoder always_ok_decoder = from_blob<DecoderBlob, Decoder>(
            lib_ruby_parser__test__always_ok_decoder("foo"));

        MaybeDecoder some_decoder = from_blob<MaybeDecoderBlob, MaybeDecoder>(
            lib_ruby_parser__test__some_always_ok_decoder("foo"));
        assert(some_decoder.is_some());

        assert_eq(some_decoder.decoder.f, always_ok_decoder.f);
        MaybeDecoder none_decoder = from_blob<MaybeDecoderBlob, MaybeDecoder>(
            lib_ruby_parser__test__none_decoder());
        assert(none_decoder.is_none());
    }

    extern "C"
    {
        DecoderResultBlob custom_decoder(void *state, StringBlob encoding_blob, ByteListBlob input_blob);
        DecoderResultBlob custom_decoder(void *state, StringBlob encoding_blob, ByteListBlob input_blob)
        {
            assert_eq(*(static_cast<int *>(state)), 42);
            String encoding = string_from_string_blob(encoding_blob);
            assert_string_eq(encoding, "unknown");
            ByteList input = from_blob<ByteListBlob, ByteList>(input_blob);
            assert_byte_list(input, "# encoding: unknown\n2 + 3");
            return decoder_result_to_blob(DecoderResult::Ok(ByteList::Copied("# encoding: unknown\nfoo", 23)));
        }
    }
    static void test_custom_decoder()
    {
        annotate_test;
        int state = 42;

        ParserResult result = parse(
            ByteList::Copied("# encoding: unknown\n2 + 3", 25),
            ParserOptions(
                String::Copied("(eval)"),
                MaybeDecoder(Decoder(custom_decoder, static_cast<void *>(&state))),
                MaybeTokenRewriter(TokenRewriter(nullptr)),
                false));

        assert_byte_list(result.input.bytes, "# encoding: unknown\nfoo");
    }

    void run_test_group_decoder(void);
    void run_test_group_decoder(void)
    {
        const test_fn_t tests[] = {
            test_input_error_fields,
            test_decoder_result_fields,
            test_decoder_fields,
            test_maybe_decoder_fields,
            test_custom_decoder,
        };

        run_tests_as_group("decoder", tests, sizeof(tests) / sizeof(test_fn_t));
    }
}
