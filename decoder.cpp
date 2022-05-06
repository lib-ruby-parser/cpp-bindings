#include <cstring>
#include <utility>
#include <iostream>
#include "decoder.hpp"
#include "utils.hpp"

namespace lib_ruby_parser
{
    extern "C"
    {
        void LIB_RUBY_PARSER_drop_input_error(InputError *input_error);
        void LIB_RUBY_PARSER_drop_decoder_result(DecoderResult *decoder_result);
    }

    // input error
    InputError::Value::Value()
    {
        std::memset(this, 0, sizeof(Value));
    }

    InputError::Value::Value(InputError::Value &&other)
    {
        std::memcpy(this, &other, sizeof(Value));
        std::memset(&other, 0, sizeof(Value));
    }

    InputError::Value::~Value() {}

    InputError::Value &InputError::Value::operator=(InputError::Value &&other)
    {
        std::memcpy(this, &other, sizeof(Value));
        std::memset(&other, 0, sizeof(Value));
        return *this;
    }

    InputError::InputError(Tag tag_,
                           Value as_) : tag(tag_),
                                        as(std::move(as_)) {}

    InputError InputError::UnsupportedEncoding(String unsupported_encoding)
    {
        InputError::Value value;
        value.unsupported_encoding = std::move(unsupported_encoding);
        return InputError(InputError::Tag::UNSUPPORTED_ENCODING, std::move(value));
    }
    InputError InputError::DecodingError(String decoding_error)
    {
        InputError::Value value;
        value.decoding_error = std::move(decoding_error);
        return InputError(InputError::Tag::DECODING_ERROR, std::move(value));
    }

    InputError::~InputError()
    {
        LIB_RUBY_PARSER_drop_input_error(this);
    }

    // decoder result
    DecoderResult::Value::Value()
    {
        std::memset(this, 0, sizeof(Value));
    }
    DecoderResult::Value::Value(Value &&other)
    {
        std::memcpy(this, &other, sizeof(Value));
        std::memset(&other, 0, sizeof(Value));
    }
    DecoderResult::Value::~Value() {}

    DecoderResult::DecoderResult(Tag tag_,
                                 Value as_) : tag(tag_),
                                              as(std::move(as_)) {}
    DecoderResult::~DecoderResult()
    {
        LIB_RUBY_PARSER_drop_decoder_result(this);
    }

    DecoderResult DecoderResult::Ok(ByteList decoded)
    {
        DecoderResult::Value value;
        value.ok = std::move(decoded);
        return DecoderResult(DecoderResult::Tag::OK, std::move(value));
    }
    DecoderResult DecoderResult::Err(InputError err)
    {
        DecoderResult::Value value;
        value.err = std::move(err);
        return DecoderResult(DecoderResult::Tag::ERR, std::move(value));
    }

    // decoder
    Decoder::Decoder(DecoderFunction f_, void *state_) : f(f_), state(state_) {}

    // maybe decoder
    MaybeDecoder::MaybeDecoder(Decoder decoder_) : decoder(decoder_) {}
    MaybeDecoder MaybeDecoder::Some(Decoder decoder_)
    {
        return MaybeDecoder(decoder_);
    }
    MaybeDecoder MaybeDecoder::None()
    {
        return MaybeDecoder(Decoder(nullptr, nullptr));
    }

    bool MaybeDecoder::is_some() const
    {
        return this->decoder.f != nullptr;
    }
    bool MaybeDecoder::is_none() const
    {
        return this->decoder.f == nullptr;
    }
}
