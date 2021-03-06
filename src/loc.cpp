#include "loc.h"

namespace lib_ruby_parser
{

    Loc::Loc(uint32_t begin, uint32_t end)
    {
        this->begin = begin;
        this->end = end;
    }

    Loc::~Loc() {}

    bool Loc::operator==(const Loc &other)
    {
        return (begin == other.begin) && (end == other.end);
    }

    bool Loc::operator!=(const Loc &other)
    {
        return !(*this == other);
    }

    uint32_t Loc::size() const
    {
        return end - begin;
    }

    Bytes Loc::source(const Input &input) const
    {
        return input.range(begin, begin + size());
    }

    std::ostream &operator<<(std::ostream &os, const Loc &loc)
    {
        return os << "(" << loc.begin << "..." << loc.end << ")";
    }
} // namespace lib_ruby_parser
