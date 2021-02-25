#ifndef LIB_RUBY_PARSER_BYTE_PTR_H
#define LIB_RUBY_PARSER_BYTE_PTR_H

#include <string>
#include <vector>
#include <stdint.h>

namespace lib_ruby_parser
{
    extern "C"
    {
        struct BytePtr
        {
        public:
            char *ptr;
            uint32_t size;
        };

        BytePtr make_byte_ptr(const char *ptr, uint32_t size);
        void free_byte_ptr(BytePtr byte_ptr);

        // Defined in Rust
        BytePtr byte_ptr_to_utf8_lossy_byte_ptr(BytePtr byte_ptr);
    }

    std::string byte_ptr_to_owned_string(BytePtr byte_ptr);
    std::string byte_ptr_to_owned_string_lossy(BytePtr byte_ptr);
    std::vector<char> byte_ptr_to_vec(BytePtr byte_ptr);
} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_BYTE_PTR_H
