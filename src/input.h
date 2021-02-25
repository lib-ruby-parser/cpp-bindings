#ifndef LIB_RUBY_PARSER_INPUT_H
#define LIB_RUBY_PARSER_INPUT_H

#include <stdint.h>
#include <string>
#include "bytes.h"

namespace lib_ruby_parser
{
    class Input
    {
        void *ptr;

    public:
        Input() = default;
        explicit Input(void *);
        Input(const Input &) = delete;
        Input(Input &&) = default;
        ~Input();

        const char *source();
        Bytes range(uint32_t begin, uint32_t end);
        uint32_t size();
    };
}

#endif // LIB_RUBY_PARSER_INPUT_H
