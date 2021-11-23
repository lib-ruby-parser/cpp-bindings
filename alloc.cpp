#include <cstddef>
#include <cstdlib>

#include "alloc.hpp"

extern "C"
{
    void *lib_ruby_parser_external_alloc(size_t size)
    {
        return malloc(size);
    }
    void lib_ruby_parser_external_free(void *ptr)
    {
        free(ptr);
    }
}
