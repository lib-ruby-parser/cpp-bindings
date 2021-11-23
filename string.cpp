#include <cstdlib>
#include "string.hpp"
#include "utils.hpp"

namespace lib_ruby_parser
{
    BLOB(String);

    extern "C"
    {
        StringBlob LIB_RUBY_PARSER_new_string_owned(char *s, size_t len);
        StringBlob LIB_RUBY_PARSER_new_string_from_cstr(const char *s);
        void LIB_RUBY_PARSER_drop_string(String *string);

        bool LIB_RUBY_PARSER_maybe_string_is_some(const MaybeString *maybe_string);
        bool LIB_RUBY_PARSER_maybe_string_is_none(const MaybeString *maybe_string);
        void LIB_RUBY_PARSER_drop_maybe_string(MaybeString *maybe_string);
    }

    LIST_IMPL(String, char, LIB_RUBY_PARSER_drop_string);

    String String::Owned(char *s, size_t len)
    {
        return from_blob<StringBlob, String>(
            LIB_RUBY_PARSER_new_string_owned(s, len));
    }
    String String::Copied(const char *s)
    {
        return from_blob<StringBlob, String>(
            LIB_RUBY_PARSER_new_string_from_cstr(s));
    }

    MaybeString::MaybeString() : string(String(nullptr, 0, 0)){};
    MaybeString::MaybeString(String string_) : string(std::move(string_)){};

    bool MaybeString::is_some() const
    {
        return this->string.ptr != nullptr;
    }
    bool MaybeString::is_none() const
    {
        return this->string.ptr == nullptr;
    }
} // lib_ruby_parser

// #ifdef TEST_ENV

#include "test_helper.hpp"
#include <cstring>

namespace lib_ruby_parser
{
    BLOB(MaybeString);

    static char *new_owned_string(const char *s)
    {
        char *out = static_cast<char *>(malloc(strlen(s)));
        strncpy(out, s, strlen(s));
        return out;
    }

    extern "C"
    {
        StringBlob lib_ruby_parser__test__make_string_foo(void);
    }

    static void test_rust_string_fields(void)
    {
        annotate_test;

        String foo = from_blob<StringBlob, String>(
            lib_ruby_parser__test__make_string_foo());
        assert_string_eq(foo, "foo");

        String moved = std::move(foo);
    }

    static void test_owned_string_fields(void)
    {
        annotate_test;

        String bar = String::Owned(new_owned_string("bar"), 3);
        assert_string_eq(bar, "bar");
    }

    static void test_copied_string_fields(void)
    {
        annotate_test;

        String baz = String::Copied("baz");
        assert_string_eq(baz, "baz");
    }

    extern "C"
    {
        MaybeStringBlob lib_ruby_parser__test__make_some_string_foo(void);
        MaybeStringBlob lib_ruby_parser__test__make_none_string(void);
    }

    static void test_maybe_string_fields(void)
    {
        annotate_test;

        MaybeString some_string = from_blob<MaybeStringBlob, MaybeString>(
            lib_ruby_parser__test__make_some_string_foo());
        assert(some_string.is_some());
        assert_string_eq(some_string.string, "foo");

        MaybeString none_string = from_blob<MaybeStringBlob, MaybeString>(
            lib_ruby_parser__test__make_none_string());
        assert(none_string.is_none());
    }

    void run_test_group_string(void)
    {
        const test_fn_t tests[] = {
            test_rust_string_fields,
            test_owned_string_fields,
            test_copied_string_fields,
            test_maybe_string_fields,
        };

        run_tests_as_group("string", tests, sizeof(tests) / sizeof(test_fn_t));
    }
}

// #endif
