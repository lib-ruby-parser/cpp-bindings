#include "test_helper.hpp"
#include "../source_line.hpp"

namespace lib_ruby_parser
{
    BLOB(SourceLine);
    BLOB(SourceLineList);

    extern "C"
    {
        SourceLineBlob lib_ruby_parser__test__make_source_line(size_t begin, size_t end, bool ends_with_eof);
    }
    static void test_source_line_fields(void)
    {
        annotate_test;

        SourceLine source_line = from_blob<SourceLineBlob, SourceLine>(
            lib_ruby_parser__test__make_source_line(1, 2, true));
        assert_source_line(source_line, 1, 2, true);
    }

    extern "C"
    {
        SourceLineListBlob lib_ruby_parser__test__make_source_line_list(SourceLineBlob source_line);
    }
    static void test_source_line_list_fields(void)
    {
        annotate_test;

        SourceLineList source_line_list = from_blob<SourceLineListBlob, SourceLineList>(
            lib_ruby_parser__test__make_source_line_list(
                lib_ruby_parser__test__make_source_line(1, 2, true)));
        assert_eq(source_line_list.len, 1);
        assert_source_line(source_line_list.ptr[0], 1, 2, true);
    }

    void run_test_group_source_line(void)
    {
        const test_fn_t tests[] = {
            test_source_line_fields,
            test_source_line_list_fields,
        };

        run_tests_as_group("source_line", tests, sizeof(tests) / sizeof(test_fn_t));
    }

}
