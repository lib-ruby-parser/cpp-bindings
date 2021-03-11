#ifndef LIB_RUBY_PARSER_LOC_H
#define LIB_RUBY_PARSER_LOC_H

#include <stdint.h>
#include <string>
#include <iostream>
#include "bytes.h"
#include "input.h"

namespace lib_ruby_parser
{
    // Represents some location in the source
    class Loc
    {
    public:
        // Begin of the range
        uint32_t begin;

        // End of the range
        uint32_t end;

        Loc() = delete;
        Loc(Loc &&) = default;
        Loc(const Loc &) = default;
        explicit Loc(uint32_t begin, uint32_t end);
        ~Loc();

        bool operator==(const Loc &other);
        bool operator!=(const Loc &other);

        // Returns size of the range
        uint32_t size() const;

        // Returns source of the range
        Bytes source(const Input &input) const;

        friend std::ostream &operator<<(std::ostream &os, const Loc &loc);
    };

} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_LOC_H
