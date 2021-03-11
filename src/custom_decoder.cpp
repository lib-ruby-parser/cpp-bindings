#include <cstring>
#include "custom_decoder.h"
#include "helpers.h"

namespace lib_ruby_parser
{
    CustomDecoder::Result::Result(Bytes output) : data(std::move(output)){};
    CustomDecoder::Result::Result(std::string error_message) : data(std::move(error_message)){};

    CustomDecoder::Result CustomDecoder::Result::Ok(Bytes output)
    {
        return CustomDecoder::Result(std::move(output));
    }

    CustomDecoder::Result CustomDecoder::Result::Error(std::string error_message)
    {
        return CustomDecoder::Result(std::move(error_message));
    }

    CustomDecoder::~CustomDecoder() {}
} // namespace lib_ruby_parser
