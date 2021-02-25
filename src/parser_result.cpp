#include "parser_result.h"

namespace lib_ruby_parser
{
    extern "C"
    {
        ParserResult *parse(BytePtr input, ParserOptions *options);
    }

    std::unique_ptr<ParserResult> ParserResult::from_source(Bytes source, ParserOptions options)
    {
        return std::unique_ptr<ParserResult>(parse(source.into_ptr(), &options));
    }
} // namespace lib_ruby_parser
