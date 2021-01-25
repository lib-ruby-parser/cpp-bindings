#ifndef LIB_RUBY_PARSER_INPUT_H
#define LIB_RUBY_PARSER_INPUT_H

#include <vector>
#include <string>
#include <iostream>
#include "byte_ptr.h"

namespace lib_ruby_parser
{
    class Bytes
    {
        char *bytes_;
        size_t size_;
        bool borrowed = false;

        BytePtr borrow_ptr() const;

    public:
        Bytes();
        ~Bytes();

        explicit Bytes(std::string s);
        explicit Bytes(char *ptr, size_t size);
        explicit Bytes(BytePtr byte_ptr);

        Bytes(Bytes &&);
        Bytes(const Bytes &) = delete;
        Bytes &operator=(Bytes &&other);

        BytePtr into_ptr();
        size_t size() const;
        Bytes clone() const;
        char at(size_t idx) const;
        Bytes range(size_t begin, size_t end) const;
        std::string to_string() const;
        std::string to_string_lossy() const;
        void mark_borrowed();

        bool operator==(const Bytes &other);
        bool operator==(const std::string &other);
        bool operator==(const char *other);
        friend std::ostream &operator<<(std::ostream &os, const Bytes &range);
    };
} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_INPUT_H
