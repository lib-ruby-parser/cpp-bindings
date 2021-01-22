#include "bytes.h"
#include <cstring>
#include <iostream>

namespace lib_ruby_parser
{
    char *copy_bytes(const char *ptr, size_t size)
    {
        if (size == 0 || ptr == nullptr)
        {
            return nullptr;
        }
        auto result = (char *)malloc(size * sizeof(char));
        memcpy(result, ptr, size);
        std::cout << "\ncopy_bytes \"" << std::string(result, size) << "\" (size = " << size << ", ptr = " << (void *)result << ")\n";
        return result;
    }

    Bytes::Bytes()
    {
        this->size_ = 0;
        this->bytes_ = nullptr;
        this->borrowed = false;
    }

    Bytes::~Bytes()
    {
        if (borrowed)
        {
            return;
        }
        if (size_ != 0 && bytes_ != nullptr)
        {
            std::cout << "\n~Bytes \"" << std::string(bytes_, size_) << "\" (size = " << size_ << ", ptr = " << (void *)bytes_ << ")\n";
            free(bytes_);
        }
        this->bytes_ = nullptr;
        this->size_ = 0;
    }

    BytePtr Bytes::borrow_ptr() const
    {
        BytePtr ptr;
        ptr.ptr = bytes_;
        ptr.size = size_;
        return ptr;
    }

    Bytes::Bytes(std::string s)
    {
        this->bytes_ = copy_bytes(s.c_str(), s.length());
        this->size_ = s.length();
    }
    Bytes::Bytes(char *ptr, size_t size)
    {
        this->bytes_ = ptr;
        this->size_ = size;
    }
    Bytes::Bytes(BytePtr byte_ptr)
    {
        this->bytes_ = (char *)byte_ptr.ptr;
        this->size_ = byte_ptr.size;

        byte_ptr.ptr = nullptr;
        byte_ptr.size = 0;
    }

    Bytes::Bytes(Bytes &&other)
    {
        this->size_ = other.size_;
        this->bytes_ = other.bytes_;
        this->borrowed = other.borrowed;

        other.size_ = 0;
        other.bytes_ = nullptr;
        other.borrowed = true;
    }

    Bytes &Bytes::operator=(Bytes &&other)
    {
        if (size_ != 0 && bytes_ != nullptr)
        {
            free(bytes_);
        }
        this->size_ = other.size_;
        this->bytes_ = other.bytes_;
        this->borrowed = other.borrowed;

        other.size_ = 0;
        other.bytes_ = nullptr;
        other.borrowed = true;

        return *this;
    }

    BytePtr Bytes::into_ptr()
    {
        BytePtr ptr;
        ptr.ptr = bytes_;
        ptr.size = size_;

        this->bytes_ = nullptr;
        this->size_ = 0;

        return ptr;
    }

    size_t Bytes::size() const
    {
        return size_;
    }

    Bytes Bytes::clone() const
    {
        return Bytes(copy_bytes(bytes_, size_), size_);
    }

    char Bytes::at(size_t idx) const
    {
        return bytes_[idx];
    }

    Bytes Bytes::range(size_t begin, size_t end) const
    {
        auto size = end - begin;
        auto ptr_begin = bytes_ + begin * sizeof(char);
        auto ptr = copy_bytes(ptr_begin, size);
        return Bytes(ptr, size);
    }

    std::string Bytes::to_string() const
    {
        return std::string(bytes_, size_);
    }

    std::string Bytes::to_string_lossy() const
    {
        auto utf8_ptr = byte_ptr_to_utf8_lossy_byte_ptr(borrow_ptr());
        return byte_ptr_to_owned_string(utf8_ptr);
    }

    void Bytes::mark_borrowed()
    {
        this->borrowed = true;
    }

    bool Bytes::operator==(const Bytes &other)
    {
        return (bytes_ == other.bytes_) && (size_ == other.size_);
    }

    bool Bytes::operator==(const std::string &other)
    {
        return to_string() == other;
    }

    bool Bytes::operator==(const char *other)
    {
        return to_string() == other;
    }

    std::ostream &operator<<(std::ostream &os, const Bytes &bytes)
    {
        os << "Bytes[";
        for (size_t i = 0; i < bytes.size_; i++)
        {
            os << bytes.at(i) << ',';
        }
        os << "]";
        return os;
    }
} // namespace lib_ruby_parser
