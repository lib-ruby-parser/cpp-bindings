#include <utility>
#include "utils.hpp"
#include "decoded_input.hpp"

namespace lib_ruby_parser
{
    BLOB(DecodedInput);

    DecodedInput::DecodedInput(String name_,
                               SourceLineList lines_,
                               ByteList bytes_) : name(std::move(name_)),
                                                  lines(std::move(lines_)),
                                                  bytes(std::move(bytes_)) {}
}
