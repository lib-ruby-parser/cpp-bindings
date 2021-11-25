#include <cstdint>
#include <cstddef>
#include <string>

#include "../lib-ruby-parser.hpp"

using namespace lib_ruby_parser;

extern "C" int LLVMFuzzerTestOneInput(char *data, size_t size)
{
    std::string input(data, size);
    auto result = ParserResult::from_source(Bytes(input), ParserOptions());
    return 0;
}
