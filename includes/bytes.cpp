#include "bytes.h"

namespace lib_ruby_parser
{
    Bytes::Bytes(std::string s)
    {
        this->bytes = std::vector(s.begin(), s.end());
    }

    Bytes::Bytes(std::vector<char> bytes)
    {
        this->bytes = std::move(bytes);
    }

    Bytes::Bytes(const char *ptr, size_t length)
    {
        this->bytes = std::vector<char>();
        this->bytes.reserve(length);
        for (size_t i = 0; i < length; i++)
        {
            this->bytes.push_back(ptr[i]);
        }
    }

    const char *Bytes::ptr()
    {
        return bytes.data();
    }

    size_t Bytes::size() const
    {
        return bytes.size();
    }

    Bytes Bytes::clone() const
    {
        return Bytes(this->bytes);
    }

    bool Bytes::operator==(const Bytes &other)
    {
        return this->bytes == other.bytes;
    }

    std::ostream &operator<<(std::ostream &os, const Bytes &bytes)
    {
        os << "Bytes[";
        for (auto byte : bytes.bytes)
        {
            os << byte << ",";
        }
        os << "]";
        return os;
    }
} // namespace lib_ruby_parser
