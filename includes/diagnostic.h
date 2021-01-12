#ifndef LIB_RUBY_PARSER_DIAGNOSTIC_H
#define LIB_RUBY_PARSER_DIAGNOSTIC_H

#include <string>
#include <memory>
#include <iostream>
#include "range.h"

namespace lib_ruby_parser
{
    enum ErrorLevel
    {
        WARNING,
        ERROR
    };

    class Diagnostic
    {
    public:
        ErrorLevel level;
        std::string message;
        std::unique_ptr<Range> range;

        Diagnostic() = delete;
        Diagnostic(Diagnostic &&) = default;
        Diagnostic(const Diagnostic &) = delete;
        explicit Diagnostic(ErrorLevel level,
                            std::string message,
                            std::unique_ptr<Range> range);

        bool operator==(const Diagnostic &other);
        bool operator!=(const Diagnostic &other);

        friend std::ostream &operator<<(std::ostream &os, const Diagnostic &diagnostic);
    };

    extern "C"
    {
        Diagnostic *make_diagnostic(ErrorLevel level, char *message, Range *range);
    }
} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_DIAGNOSTIC_H
