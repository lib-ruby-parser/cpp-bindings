#ifndef LIB_RUBY_PARSER_SHARED_BYTE_LIST_HPP
#define LIB_RUBY_PARSER_SHARED_BYTE_LIST_HPP

#include <cstddef>

namespace lib_ruby_parser
{
    /// Equivalent of `&[u8]` in Rust.
    /// Holds a constant pointer + length.
    class SharedByteList
    {
    public:
        const char *ptr;
        size_t len;

        SharedByteList() = delete;
        SharedByteList(const char *ptr, size_t len);
    };
} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_SHARED_BYTE_LIST_HPP
