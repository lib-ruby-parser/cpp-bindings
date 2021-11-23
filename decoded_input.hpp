#ifndef LIB_RUBY_PARSER_DECODED_INPUT_HPP
#define LIB_RUBY_PARSER_DECODED_INPUT_HPP

#include "string.hpp"
#include "source_line.hpp"
#include "bytes.hpp"

namespace lib_ruby_parser
{
    /*
        Equivalent of `lib_ruby_parser::source::DecodedInput`
    */
    class DecodedInput
    {
    public:
        String name;
        SourceLineList lines;
        ByteList bytes;

        DecodedInput() = delete;
        DecodedInput(String name, SourceLineList lines, ByteList bytes);

        DecodedInput(const DecodedInput &) = delete;
        DecodedInput &operator=(DecodedInput const &) = delete;

        DecodedInput(DecodedInput &&) = default;
        DecodedInput &operator=(DecodedInput &&) = default;
    };

    // #ifdef TEST_ENV
    void run_test_group_decoded_input(void);
    // #endif
}

#endif // LIB_RUBY_PARSER_DECODED_INPUT_HPP
