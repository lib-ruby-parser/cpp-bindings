#ifndef LIB_RUBY_PARSER_BYTE_PTR_H
#define LIB_RUBY_PARSER_BYTE_PTR_H

#include <string>
#include <vector>
#include <stdint.h>

namespace lib_ruby_parser
{
    extern "C"
    {
        // Low-level data structure that is used in Rust <-> C++ communications.
        // Represents a sequence of bytes.
        struct BytePtr
        {
        public:
            // Pointer to beginning of the byte sequence
            char *ptr;

            // Size of the byte sequence
            uint32_t size;
        };

        // Constructor of the BytePtr
        BytePtr make_byte_ptr(const char *ptr, uint32_t size);

        // Destructor of the BytePtr
        void free_byte_ptr(BytePtr byte_ptr);

        // Converts given `byte_ptr` into a UTF-8-valid BytePtr.
        // It doesn't modify or drop given `byte_ptr`.
        BytePtr byte_ptr_to_utf8_lossy_byte_ptr(BytePtr byte_ptr);
    }

    // Converts given BytePtr to a string.
    // This function doesn't care about UTF-8-incompatible byte sequences,
    // and so resulting string can be invalid in UTF-8.
    // It doesn't modify or drop given `byte_ptr`.
    std::string byte_ptr_to_owned_string(const BytePtr &byte_ptr);

    // Converts given BytePtr to a string.
    // All UTF-8-incompatible byte sub-sequences in the given BytePtr
    // are substituted with a special REPLACEMENT char.
    // It doesn't modify or drop given `byte_ptr`.
    std::string byte_ptr_to_owned_string_lossy(const BytePtr &byte_ptr);

    // Converts given BytePtr to a vector of bytes.
    // This function doesn't care about UTF-8-incompatible byte sequences,
    // and so resulting vector can be invalid in UTF-8.
    // It doesn't modify or drop given `byte_ptr`.
    std::vector<char> byte_ptr_to_vec(const BytePtr &byte_ptr);
} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_BYTE_PTR_H
