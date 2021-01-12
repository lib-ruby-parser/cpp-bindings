#ifndef LIB_RUBY_PARSER_INPUT_H
#define LIB_RUBY_PARSER_INPUT_H

#include <vector>
#include <string>
#include <iostream>

namespace lib_ruby_parser
{
    class Bytes
    {
        std::vector<char> bytes;

    public:
        explicit Bytes() = default;
        Bytes(Bytes &&) = default;
        Bytes(const Bytes &) = delete;
        Bytes &operator=(Bytes &&) = default;

        Bytes(std::string s);
        Bytes(std::vector<char> data);
        Bytes(const char *ptr, size_t length);

        const char *ptr();
        size_t size() const;
        Bytes clone() const;

        bool operator==(const Bytes &other);
        friend std::ostream &operator<<(std::ostream &os, const Bytes &range);
    };
} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_INPUT_H
