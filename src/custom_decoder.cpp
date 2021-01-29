#include <cstring>
#include "custom_decoder.h"
#include "helpers.h"

namespace lib_ruby_parser
{
    CustomDecoder::Result CustomDecoder::Result::Ok(Bytes output)
    {
        CustomDecoder::Result result;
        result.success = true;
        result.output = std::move(output);
        return result;
    }

    CustomDecoder::Result CustomDecoder::Result::Error(std::string error_message)
    {
        CustomDecoder::Result result;
        result.success = false;
        result.error_message = std::move(error_message);
        return result;
    }
} // namespace lib_ruby_parser
