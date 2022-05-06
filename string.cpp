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
