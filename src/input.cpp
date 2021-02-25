#include "input.h"

namespace lib_ruby_parser
{
    extern "C"
    {
        const char *input_source(void *ptr);
        uint32_t input_size(void *ptr);
        BytePtr input_range(void *ptr, uint32_t begin, uint32_t end);
        void input_free(void *ptr);
    }

    Input::Input(void *ptr)
    {
        this->ptr = ptr;
    }

    Input::~Input()
    {
        // FIXME
        // input_free(this->ptr);
    }

    const char *Input::source()
    {
        return input_source(this->ptr);
    }

    Bytes Input::range(uint32_t begin, uint32_t end)
    {
        return Bytes(input_range(ptr, begin, end));
    }

    uint32_t Input::size()
    {
        return input_size(this->ptr);
    }
}
