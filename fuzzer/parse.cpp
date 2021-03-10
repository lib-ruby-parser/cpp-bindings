#include <stdint.h>
#include <stddef.h>
#include <string>

#include "../target/lib-ruby-parser.h"

using namespace lib_ruby_parser;

extern "C" int LLVMFuzzerTestOneInput(char *data, size_t size)
{
    std::string input(data, size);
    auto result = ParserResult::from_source(Bytes(input), ParserOptions());
    return 0;
}
