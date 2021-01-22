#include "byte_ptr.h"
#include <iostream>

namespace lib_ruby_parser
{
    extern "C"
    {
        BytePtr make_byte_ptr(const char *ptr, size_t size)
        {
            BytePtr result;
            result.size = size;
            if (size != 0 && ptr != nullptr)
            {
                result.ptr = (char *)malloc(size * sizeof(char));
                memcpy(result.ptr, ptr, size);
                std::cout << "\nmake_byte_ptr \"" << std::string(result.ptr, size) << "\" (size = " << size << ", ptr = " << (void *)result.ptr << ")\n";
            }
            else
            {
                result.ptr = nullptr;
            }
            return result;
        }

        void free_byte_ptr(BytePtr byte_ptr)
        {
            if (byte_ptr.size != 0 && byte_ptr.ptr != nullptr)
            {
                std::cout << "\nfree_byte_ptr \"" << std::string(byte_ptr.ptr, byte_ptr.size) << "\" (size = " << byte_ptr.size << ", ptr = " << (void *)byte_ptr.ptr << ")\n";
                free(byte_ptr.ptr);
            }
            byte_ptr.ptr = nullptr;
            byte_ptr.size = 0;
        }
    }

    std::string byte_ptr_to_owned_string(BytePtr byte_ptr)
    {
        auto result = std::string(byte_ptr.ptr, byte_ptr.size);
        free_byte_ptr(byte_ptr);
        return result;
    }

    std::string byte_ptr_to_utf8_lossy_string(BytePtr byte_ptr)
    {
        auto utf8_byte_ptr = byte_ptr_to_utf8_lossy_byte_ptr(byte_ptr);
        return byte_ptr_to_owned_string(utf8_byte_ptr);
    }

    std::vector<char> byte_ptr_to_vec(BytePtr byte_ptr)
    {
        auto vec = std::vector<char>();
        vec.reserve(byte_ptr.size);
        for (size_t i = 0; i < byte_ptr.size; i++)
        {
            vec.push_back(byte_ptr.ptr[i]);
        }
        return vec;
    }
} // namespace lib_ruby_parser
