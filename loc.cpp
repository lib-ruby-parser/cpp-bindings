#include "utils.hpp"
#include "loc.hpp"

namespace lib_ruby_parser
{
    extern "C"
    {
        char *LIB_RUBY_PARSER_loc_source(const Loc *loc, const DecodedInput *input);
    }

    Loc::Loc(size_t begin_, size_t end_) : begin(begin_), end(end_) {}

    std::string Loc::source(const DecodedInput &decoded_input) const
    {
        char *source_ptr = LIB_RUBY_PARSER_loc_source(this, &decoded_input);
        std::string source(source_ptr);
        free(source_ptr);
        return source;
    }
} // lib_ruby_parser
