#ifndef LIB_RUBY_PARSER_BYTES_HPP
#define LIB_RUBY_PARSER_BYTES_HPP

#include <cstddef>

namespace lib_ruby_parser
{
    /*
        Representation of a Vec<u8>.
        `capacity` doesn't matter.
    */
    class ByteList
    {
    public:
        char *ptr;
        size_t capacity;
        size_t len;

        ByteList() = delete;
        ByteList(char *ptr, size_t len, size_t capacity);

        ByteList(const ByteList &) = delete;
        ByteList &operator=(ByteList const &) = delete;

        ByteList(ByteList &&);
        ByteList &operator=(ByteList &&);

        ~ByteList();

        static ByteList Owned(char *s, size_t len);
        static ByteList Copied(const char *s, size_t len);
    };
    /*
        Rerpresentation of `Bytes` struct from lib-ruby-parser.
    */
    class Bytes
    {
    public:
        ByteList raw;

        Bytes() = delete;
        explicit Bytes(ByteList raw);

        Bytes(const Bytes &) = delete;
        Bytes &operator=(Bytes const &) = delete;

        Bytes(Bytes &&) = default;
        Bytes &operator=(Bytes &&) = default;
    };

#ifdef TEST_ENV
    void run_test_group_bytes(void);
#endif

} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_BYTES_HPP