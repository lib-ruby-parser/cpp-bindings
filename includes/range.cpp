#include "range.h"

namespace lib_ruby_parser
{

    Range::Range(size_t begin_pos, size_t end_pos)
    {
        this->begin_pos = begin_pos;
        this->end_pos = end_pos;
    }

    std::string Range::source(const std::string &input)
    {
        return input.substr(begin_pos, size());
    }

    extern "C"
    {
        Range *make_range(size_t begin_pos, size_t end_pos)
        {
            return new Range(begin_pos, end_pos);
        }
    }
} // namespace lib_ruby_parser
