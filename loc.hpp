#ifndef LOC_HPP
#define LOC_HPP

#include <cstddef>
#include <cstdint>
#include <string>
#include "decoded_input.hpp"

namespace lib_ruby_parser
{
    /*
        `Loc` struct from `lib-ruby-parser`
    */
    class Loc
    {
    public:
        size_t begin;
        size_t end;

        explicit Loc(size_t begin_, size_t end_);

        std::string source(const DecodedInput &decoded_input) const;
    };

    /*
        Returns source code of the given location.
        Equivalent of `lib_ruby_parser::Loc::source`
    */
    // char *loc_source(const Loc *loc, const DecodedInput *input);

    /*
        Equivalent of `Option<Loc>`
    */
    class MaybeLoc
    {
    public:
        enum class Tag
        {
            NONE = 0,
            SOME = 1,
        };

        union Value
        {
            Loc loc;
            uint8_t none;
        };

        Tag tag;
        Value as;

        static MaybeLoc Some(Loc loc);
        static MaybeLoc None();
    };

    // #ifdef TEST_ENV
    void run_test_group_loc(void);
    // #endif
} // namespace lib_ruby_parser

#endif // LOC_HPP
