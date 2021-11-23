#ifndef LIB_RUBY_PARSER_ALLOC_HPP
#define LIB_RUBY_PARSER_ALLOC_HPP

// explicit allocator that is used by Rust part.
// enabled only for mingw, other targets don't need it.
extern "C"
{
    void *lib_ruby_parser_external_alloc(size_t size);
    void lib_ruby_parser_external_free(void *ptr);
}

#endif // LIB_RUBY_PARSER_ALLOC_HPP
