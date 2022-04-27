#ifndef LIB_RUBY_PARSER_SOURCE_LINE_HPP
#define LIB_RUBY_PARSER_SOURCE_LINE_HPP

#include <cstddef>
#include <cstdbool>

namespace lib_ruby_parser
{
    /// `SourceLine` struct from `lib-ruby-parser`
    class SourceLine
    {
    public:
        size_t start;
        size_t end;
        bool ends_with_eof;

        SourceLine(size_t start, size_t end, size_t ends_with_eof);
    };

    /// Equivalent of `Vec<SourceLine>`
    class SourceLineList
    {
    public:
        SourceLine *ptr;
        size_t capacity;
        size_t len;

        SourceLineList() = delete;
        SourceLineList(SourceLine *ptr, size_t len, size_t capacity);
        ~SourceLineList();

        SourceLineList(const SourceLineList &) = delete;
        SourceLineList &operator=(SourceLineList const &) = delete;

        SourceLineList(SourceLineList &&);
        SourceLineList &operator=(SourceLineList &&);
    };

#ifdef TEST_ENV
    void run_test_group_source_line(void);
#endif

} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_SOURCE_LINE_HPP
