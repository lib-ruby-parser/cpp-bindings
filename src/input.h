#ifndef LIB_RUBY_PARSER_INPUT_H
#define LIB_RUBY_PARSER_INPUT_H

#include <stdint.h>
#include <string>
#include "bytes.h"

namespace lib_ruby_parser
{
    // Representation of the source code
    class Input
    {
    public:
        // Pointer to Rust struct
        // Touching it may cause a segfault
        void *ptr;

        Input() = default;
        explicit Input(void *);
        Input(const Input &) = delete;
        Input(Input &&);
        ~Input();

        // Returns source of the input
        const char *source() const;

        // Returns part of the input with a given begin..end range
        Bytes range(uint32_t begin, uint32_t end) const;

        // Returns size of the input
        uint32_t size() const;
    };
}

#endif // LIB_RUBY_PARSER_INPUT_H
