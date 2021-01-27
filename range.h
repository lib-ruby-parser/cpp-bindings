#ifndef LIB_RUBY_PARSER_RANGE_H
#define LIB_RUBY_PARSER_RANGE_H

#include <cstddef>
#include <string>
#include <iostream>
#include "bytes.h"

namespace lib_ruby_parser
{
    class Range
    {
    public:
        uint32_t begin_pos;
        uint32_t end_pos;

        Range() = delete;
        Range(Range &&) = default;
        Range(const Range &) = default;
        explicit Range(uint32_t begin_pos, uint32_t end_pos);

        bool operator==(const Range &other);
        bool operator!=(const Range &other);
        uint32_t size();
        Bytes source(Bytes &input);

        friend std::ostream &operator<<(std::ostream &os, const Range &range);
    };

} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_RANGE_H
