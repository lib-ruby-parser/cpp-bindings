#include "shared_byte_list.hpp"

namespace lib_ruby_parser
{
    SharedByteList::SharedByteList(const char *ptr_,
                                   size_t len_) : ptr(ptr_),
                                                  len(len_) {}

} // namespace lib_ruby_parser

#ifdef TEST_ENV

#include "test_helper.hpp"

namespace lib_ruby_parser
{
    extern "C"
    {
        SharedByteList lib_ruby_parser__test__make_shared_byte_list_foo(void);
    }

    static void test_shared_byte_list_fields(void)
    {
        annotate_test;

        SharedByteList foo = lib_ruby_parser__test__make_shared_byte_list_foo();
        assert(foo.len == 3);
        assert_str_eq(foo.ptr, "foo");
    }

    void run_test_group_shared_byte_list(void)
    {
        const test_fn_t tests[] = {
            test_shared_byte_list_fields,
        };

        run_tests_as_group("shared_byte_list", tests, sizeof(tests) / sizeof(test_fn_t));
    }
} // namespace lib_ruby_parser

#endif
