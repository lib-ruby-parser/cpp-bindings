#ifndef LIB_RUBY_PARSER_RANGE_H
#define LIB_RUBY_PARSER_RANGE_H

#include <cstddef>

namespace lib_ruby_parser
{
    class Range
    {
    public:
        size_t begin_pos;
        size_t end_pos;

        Range() = delete;
        Range(Range &&) = default;
        Range(const Range &) = delete;
        explicit Range(size_t begin_pos, size_t end_pos) : begin_pos(begin_pos), end_pos(end_pos) {}

        inline bool operator==(const Range &other)
        {
            return (begin_pos == other.begin_pos) && (end_pos == other.end_pos);
        }

        inline bool operator!=(const Range &other)
        {
            return !(*this == other);
        }

        inline size_t size()
        {
            return end_pos - begin_pos;
        }

        std::string source(const std::string &input)
        {
            return input.substr(begin_pos, size());
        }
    };

    extern "C"
    {
        Range *make_range(size_t begin_pos, size_t end_pos)
        {
            return new Range(begin_pos, end_pos);
        }
    }
} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_RANGE_H
