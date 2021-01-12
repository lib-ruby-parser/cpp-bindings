#include "custom_decoder.h"
#include "helpers.h"

namespace lib_ruby_parser
{
    CustomDecoder::Result CustomDecoder::Result::Ok(std::string output)
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

    extern "C"
    {
        CustomDecoderResult CustomDecoderResult::Ok(char *output, size_t length)
        {
            CustomDecoderResult result;
            result.output = output;
            result.output_length = length;
            result.success = true;
            return result;
        }

        CustomDecoderResult CustomDecoderResult::Error(char *error_message, size_t length)
        {
            CustomDecoderResult result;
            result.error_message = error_message;
            result.error_message_length = length;
            result.success = false;
            return result;
        }

        CustomDecoderResult rewrite(CustomDecoder *decoder, const char *encoding_ptr, size_t encoding_length, const char *input_ptr, size_t input_length)
        {
            auto encoding = std::string(encoding_ptr, encoding_length);
            auto input = std::string(input_ptr, input_length);

            auto cpp_result = decoder->rewrite(std::move(encoding), std::move(input));

            if (cpp_result.success)
            {
                auto output = string_to_char_ptr(cpp_result.output);
                auto length = cpp_result.output.length();
                return CustomDecoderResult::Ok(output, length);
            }
            else
            {
                auto error_message = string_to_char_ptr(cpp_result.error_message);
                auto length = cpp_result.error_message.length();
                return CustomDecoderResult::Error(error_message, length);
            }
        }
    }
} // namespace lib_ruby_parser
