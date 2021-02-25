#ifndef LIB_RUBY_PARSER_LOC_H
#define LIB_RUBY_PARSER_LOC_H

#include <stdint.h>
#include <string>
#include <iostream>
#include "bytes.h"
#include "input.h"

namespace lib_ruby_parser
{
    class Loc
    {
    public:
        uint32_t begin;
        uint32_t end;

        Loc() = delete;
        Loc(Loc &&) = default;
        Loc(const Loc &) = default;
        explicit Loc(uint32_t begin, uint32_t end);

        bool operator==(const Loc &other);
        bool operator!=(const Loc &other);
        uint32_t size();
        Bytes source(Input &input);

        friend std::ostream &operator<<(std::ostream &os, const Loc &loc);
    };

} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_LOC_H
