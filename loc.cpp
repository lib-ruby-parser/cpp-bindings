#include "utils.hpp"
#include "loc.hpp"

namespace lib_ruby_parser
{
    extern "C"
    {
        char *LIB_RUBY_PARSER_loc_source(const Loc *loc, const DecodedInput *input);
    }

    Loc::Loc(size_t begin_, size_t end_) : begin(begin_), end(end_) {}

    std::string Loc::source(const DecodedInput &decoded_input) const
    {
        char *source_ptr = LIB_RUBY_PARSER_loc_source(this, &decoded_input);
        std::string source(source_ptr);
        free(source_ptr);
        return source;
    }
} // lib_ruby_parser

// #ifdef TEST_ENV

#include "test_helper.hpp"
#include <cstdlib>
#include <iostream>

namespace lib_ruby_parser
{
    BLOB(Loc);
    BLOB(MaybeLoc);

    extern "C"
    {
        LocBlob lib_ruby_parser__test__make_loc(size_t begin, size_t end);
    }
    static void test_loc_fields(void)
    {
        annotate_test;

        Loc loc = from_blob<LocBlob, Loc>(lib_ruby_parser__test__make_loc(1, 2));
        assert_loc(loc, Loc(1, 2));
    }

    static void test_loc_source(void)
    {
        annotate_test;

        Loc loc(1, 5);
        DecodedInput input(
            String::Copied("(eval)"),
            SourceLineList(nullptr, 0, 0),
            ByteList::Copied("1 + 2 + 3 + 4", 13));

        std::string source = loc.source(input);
        assert_eq(source, " + 2");
    }

    extern "C"
    {
        MaybeLocBlob lib_ruby_parser__test__make_none_loc(void);
    }
    static void test_none_loc_fields(void)
    {
        annotate_test;

        MaybeLoc none_loc = from_blob<MaybeLocBlob, MaybeLoc>(
            lib_ruby_parser__test__make_none_loc());
        assert_none_loc(none_loc);
    }

    extern "C"
    {
        MaybeLocBlob lib_ruby_parser__test__make_some_loc(size_t begin, size_t end);
    }
    static void test_some_loc_fields(void)
    {
        annotate_test;

        MaybeLoc some_loc = from_blob<MaybeLocBlob, MaybeLoc>(
            lib_ruby_parser__test__make_some_loc(1, 2));
        assert_some_loc(some_loc, Loc(1, 2));
    }

    void run_test_group_loc(void)
    {
        const test_fn_t tests[] = {
            test_loc_fields,
            test_loc_source,
            test_none_loc_fields,
            test_some_loc_fields,
        };

        run_tests_as_group("loc", tests, sizeof(tests) / sizeof(test_fn_t));
    }
}

// #endif
