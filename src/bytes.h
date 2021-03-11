#ifndef LIB_RUBY_PARSER_BYTES_H
#define LIB_RUBY_PARSER_BYTES_H

#include <vector>
#include <string>
#include <iostream>
#include "byte_ptr.h"

namespace lib_ruby_parser
{
    // A sequence of Bytes, potentially invalid in UTF-8
    class Bytes
    {
        // Pointer to beginning of the byte sequence
        char *bytes_;

        // Size of the byte sequence
        uint32_t size_;

        // Indicates that Bytes are "borrowed",
        // when set to true disables cleanup in destructor.
        // TODO: remove this hack by making a cleanup on all call sites.
        bool borrowed = false;

    public:
        // Destructor
        ~Bytes();

        // Constructs Bytes from a string (by copying)
        explicit Bytes(std::string s);

        // Constructs Bytes from a given ptr and size (by taking ownership)
        explicit Bytes(char *ptr, uint32_t size);

        // Constructs Bytes from a BytePtr (by taking ownership)
        explicit Bytes(BytePtr byte_ptr);

        Bytes(Bytes &&);
        Bytes(const Bytes &) = delete;
        Bytes &operator=(Bytes &&other);

        // Returns a BytePtr that shares data with initial Bytes
        // Deleting returned BytePtr will cause a segfault.
        BytePtr borrow_ptr() const;

        // Consumes `this` and returns a BytePtr with own data.
        BytePtr into_ptr();

        // Returns size of the byte sequence
        uint32_t size() const;

        // Returns a copy of `this`
        Bytes clone() const;

        // Returns a byte at the given index
        char at(uint32_t idx) const;

        // Returns a sub-sequence at the given range
        Bytes range(uint32_t begin, uint32_t end) const;

        // Returns a string that contains the same byte sequence (by copying)
        std::string to_string() const;

        // Returns a UTF-8 valid string that contains the same byte sequence.
        // Invalid UTF-8 bytes are replaced with a special REPLACEMENT char.
        std::string to_string_lossy() const;

        // Marks `this` as borrowed, so that destructor will not free the inner pointer.
        // TODO: remove this hack.
        void mark_borrowed();

        bool operator==(const Bytes &other);
        bool operator==(const std::string &other);
        bool operator==(const char *other);
        friend std::ostream &operator<<(std::ostream &os, const Bytes &bytes);
    };
} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_BYTES_H
