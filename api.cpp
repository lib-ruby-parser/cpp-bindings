#include "api.hpp"
#include "utils.hpp"

namespace lib_ruby_parser
{
    BLOB(ParserResult);
    BLOB(ParserOptions);
    BLOB(ByteList);

    extern "C"
    {
        ParserResultBlob LIB_RUBY_PARSER_parse(ByteListBlob input, ParserOptionsBlob options);
    }

    ParserResult parse(ByteList input, ParserOptions options)
    {
        return from_blob<ParserResultBlob, ParserResult>(
            LIB_RUBY_PARSER_parse(
                into_blob<ByteList, ByteListBlob>(std::move(input)),
                into_blob<ParserOptions, ParserOptionsBlob>(std::move(options))));
    }
}
