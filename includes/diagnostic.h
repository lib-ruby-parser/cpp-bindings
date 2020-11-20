#ifndef LIB_RUBY_PARSER_DIAGNOSTIC_H
#define LIB_RUBY_PARSER_DIAGNOSTIC_H

#include <string>
#include "range.h"
#include "helpers.h"

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
                            std::unique_ptr<Range> range) : level(level), message(message), range(std::move(range)) {}

        inline bool operator==(const Diagnostic &other)
        {
            return (level == other.level) && (message == other.message) && (*(range.get()) == *(other.range.get()));
        }

        inline bool operator!=(const Diagnostic &other)
        {
            return !(*this == other);
        }
    };

    extern "C"
    {
        Diagnostic *make_diagnostic(ErrorLevel level, char *message, size_t message_len, Range *range)
        {
            return new Diagnostic(level, char_ptr_to_string(message, message_len), std::unique_ptr<Range>(range));
        }
    }
} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_DIAGNOSTIC_H
