#include "source_line.hpp"
#include "utils.hpp"

namespace lib_ruby_parser
{
    SourceLine::SourceLine(size_t start_,
                           size_t end_,
                           size_t ends_with_eof_) : start(start_),
                                                    end(end_),
                                                    ends_with_eof(ends_with_eof_) {}

    LIST_IMPL(SourceLineList, SourceLine, LIB_RUBY_PARSER_drop_source_line_list);
} // namespace lib_ruby_parser
