#include "range.h"

namespace lib_ruby_parser
{

    Range::Range(uint32_t begin_pos, uint32_t end_pos)
    {
        this->begin_pos = begin_pos;
        this->end_pos = end_pos;
    }

    bool Range::operator==(const Range &other)
    {
        return (begin_pos == other.begin_pos) && (end_pos == other.end_pos);
    }

    bool Range::operator!=(const Range &other)
    {
        return !(*this == other);
    }

    uint32_t Range::size()
    {
        return end_pos - begin_pos;
    }

    Bytes Range::source(Bytes &input)
    {
        return input.range(begin_pos, begin_pos + size());
    }

    std::ostream &operator<<(std::ostream &os, const Range &range)
    {
        return os << "(" << range.begin_pos << "..." << range.end_pos << ")";
    }
} // namespace lib_ruby_parser
