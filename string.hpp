#ifndef LIB_RUBY_PARSER_String_HPP
#define LIB_RUBY_PARSER_String_HPP

#include <cstddef>
#include <cstdint>
#include <cstdbool>

namespace lib_ruby_parser
{
    /// Representation of a String.
    /// `ptr` is NOT NULL-terminated.
    /// `capacity` doesn't matter.
    class String
    {
    public:
        char *ptr;
        size_t capacity;
        size_t len;

        String() = delete;
        String(char *ptr, size_t len, size_t capacity);

        String(const String &) = delete;
        String &operator=(String const &) = delete;

        String(String &&);
        String &operator=(String &&);

        ~String();

        static String Owned(char *s, size_t len);
        static String Copied(const char *s);
    };

    /// Rerpresentation of Option<String>.
    /// Rust has a Option<non-null ptr> optimization that None is NULL on the byte level.
    /// Thus, it's not a tagged enum.
    /// To check whether it's a Some(String) or None use helpers:
    /// + LIB_RUBY_PARSER_maybe_string_is_some
    /// + LIB_RUBY_PARSER_maybe_string_is_none
    class MaybeString
    {
    public:
        String string;

        MaybeString();
        explicit MaybeString(String s);

        MaybeString(const MaybeString &) = delete;
        MaybeString &operator=(MaybeString const &) = delete;

        MaybeString(MaybeString &&) = default;
        MaybeString &operator=(MaybeString &&) = default;

        ~MaybeString() = default;

        /// Returns `true` if pointer is `Some(String)`
        bool is_some() const;
        /// Returns `true` if pointer is `None`
        bool is_none() const;
    };
} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_String_HPP
