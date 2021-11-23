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

// #ifdef TEST_ENV

#include "test_helper.hpp"

namespace lib_ruby_parser
{
    BLOB(ParserOptions);

    extern "C"
    {
        ParserOptionsBlob lib_ruby_parser__test__make_parser_options(void);
    }

    static void test_parser_options(void)
    {
        annotate_test;

        ParserOptions parser_options = from_blob<ParserOptionsBlob, ParserOptions>(
            lib_ruby_parser__test__make_parser_options());
        assert_string_eq(parser_options.buffer_name, "(eval)");
        assert(parser_options.token_rewriter.is_none());
        assert(parser_options.decoder.is_none());
        assert(parser_options.record_tokens);
    }

    void run_test_group_parser_options(void)
    {
        const test_fn_t tests[] = {
            test_parser_options,
        };

        run_tests_as_group("parser_options", tests, sizeof(tests) / sizeof(test_fn_t));
    }
}

// #endif
