#include "bytes.hpp"
#include "utils.hpp"

namespace lib_ruby_parser
{
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
