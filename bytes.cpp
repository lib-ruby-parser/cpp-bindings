#include "bytes.hpp"
#include "utils.hpp"

namespace lib_ruby_parser
{
    BLOB(ByteList);
    BLOB(Bytes);

    extern "C"
    {
        ByteListBlob LIB_RUBY_PARSER_new_bytes_owned(char *s, size_t len);
        ByteListBlob LIB_RUBY_PARSER_new_bytes_from_cstr(const char *s, size_t len);
    }

    LIST_IMPL(ByteList, char, LIB_RUBY_PARSER_drop_byte_list);

    ByteList ByteList::Owned(char *s, size_t len)
    {
        return from_blob<ByteListBlob, ByteList>(
            LIB_RUBY_PARSER_new_bytes_owned(s, len));
    }
    ByteList ByteList::Copied(const char *s, size_t len)
    {
        return from_blob<ByteListBlob, ByteList>(
            LIB_RUBY_PARSER_new_bytes_from_cstr(s, len));
    }

    Bytes::Bytes(ByteList raw_) : raw(std::move(raw_)) {}
} // namespace lib_ruby_parser

#ifdef TEST_ENV

#include "test_helper.hpp"
#include <cstdlib>
#include <iostream>

namespace lib_ruby_parser
{
    extern "C"
    {
        ByteListBlob lib_ruby_parser__test__make_byte_list(char i1, char i2, char i3);
    }

    static void test_byte_list_fields(void)
    {
        annotate_test;

        ByteList byte_list = from_blob<ByteListBlob, ByteList>(
            lib_ruby_parser__test__make_byte_list('1', '2', '3'));
        assert_byte_list(byte_list, "123");

        ByteList moved = std::move(byte_list);
    }

    static void test_byte_list_constructors(void)
    {
        annotate_test;

        char *owned = static_cast<char *>(malloc(4));
        owned[0] = '1';
        owned[1] = '2';
        owned[2] = '3';
        owned[3] = '4';
        ByteList byte_list_owned = ByteList::Owned(owned, 4);
        assert_byte_list(byte_list_owned, "1234");

        ByteList byte_list_coped = ByteList::Copied("56789", 5);
        assert_byte_list(byte_list_coped, "56789");
    }

    extern "C"
    {
        BytesBlob lib_ruby_parser__test__make_bytes(char i1, char i2, char i3);
    }
    static void test_bytes_fields(void)
    {
        annotate_test;

        Bytes bytes = from_blob<BytesBlob, Bytes>(
            lib_ruby_parser__test__make_bytes('a', 'b', 'c'));
        assert_byte_list(bytes.raw, "abc");
    }

    void run_test_group_bytes(void)
    {
        const test_fn_t tests[] = {
            test_byte_list_fields,
            test_byte_list_constructors,
            test_bytes_fields,
        };

        run_tests_as_group("bytes", tests, sizeof(tests) / sizeof(test_fn_t));
    }

}

#endif
