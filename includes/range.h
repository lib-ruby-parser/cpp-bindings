#ifndef LIB_RUBY_PARSER_RANGE_H
#define LIB_RUBY_PARSER_RANGE_H

#include <cstddef>
#include <string>

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
        explicit Range(size_t begin_pos, size_t end_pos);

        bool operator==(const Range &other);
        bool operator!=(const Range &other);
        size_t size();
        std::string source(const std::string &input);
    };

    extern "C"
    {
        Range *make_range(size_t begin_pos, size_t end_pos);
    }
} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_RANGE_H
