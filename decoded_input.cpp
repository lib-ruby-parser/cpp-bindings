#include <utility>
#include "utils.hpp"
#include "decoded_input.hpp"

namespace lib_ruby_parser
{
    BLOB(DecodedInput);

    DecodedInput::DecodedInput(String name_,
                               SourceLineList lines_,
                               ByteList bytes_) : name(std::move(name_)),
                                                  lines(std::move(lines_)),
                                                  bytes(std::move(bytes_)) {}
}

#ifdef TEST_ENV

#include "test_helper.hpp"

namespace lib_ruby_parser
{
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

    void run_test_group_decoded_input(void)
    {
        const test_fn_t tests[] = {
            test_decoded_input,
        };

        run_tests_as_group("decoded_input", tests, sizeof(tests) / sizeof(test_fn_t));
    }
}

#endif