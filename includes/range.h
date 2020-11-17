#ifndef LIB_RUBY_PARSER_RANGE_H
#define LIB_RUBY_PARSER_RANGE_H

#include <cstddef>
#include <memory>

class Range
{
public:
    size_t begin_pos;
    size_t end_pos;

    Range(size_t begin_pos, size_t end_pos) : begin_pos(begin_pos), end_pos(end_pos) {}

    size_t size()
    {
        return 0;
    }
};

#endif // LIB_RUBY_PARSER_RANGE_H
