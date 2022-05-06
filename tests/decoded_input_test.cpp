#include "test_helper.hpp"
#include "../decoded_input.hpp"
#include "../utils.hpp"

namespace lib_ruby_parser
{
#ifndef DECODED_INPUT_HAS_BLOB
#define DECODED_INPUT_HAS_BLOB
    BLOB(DecodedInput);
#endif // DECODED_INPUT_HAS_BLOB

    extern "C"
    {
        DecodedInputBlob lib_ruby_parser__test__make_decoded_input(void);
    }
    static void test_decoded_input(void)
    {
        annotate_test;

        DecodedInput decoded_input = from_blob<DecodedInputBlob, DecodedInput>(
            lib_ruby_parser__test__make_decoded_input());

        assert_string_eq(decoded_input.name, "(eval)");
        assert_eq(decoded_input.lines.len, 1);
        assert_source_line(decoded_input.lines.ptr[0], 10, 20, false);
        assert_byte_list(decoded_input.bytes, "2 + 2");
    }

    void run_test_group_decoded_input(void);
    void run_test_group_decoded_input(void)
    {
        const test_fn_t tests[] = {
            test_decoded_input,
        };

        run_tests_as_group("decoded_input", tests, sizeof(tests) / sizeof(test_fn_t));
    }
}
