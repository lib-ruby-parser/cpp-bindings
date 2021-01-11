#include "diagnostic.h"
#include "helpers.h"

namespace lib_ruby_parser
{

    Diagnostic::Diagnostic(ErrorLevel level,
                           std::string message,
                           std::unique_ptr<Range> range)
    {
        this->level = level;
        this->message = message;
        this->range = std::move(range);
    }

    bool Diagnostic::operator==(const Diagnostic &other)
    {
        return (level == other.level) && (message == other.message) && (*(range.get()) == *(other.range.get()));
    }

    bool Diagnostic::operator!=(const Diagnostic &other)
    {
        return !(*this == other);
    }

    extern "C"
    {
        Diagnostic *make_diagnostic(ErrorLevel level, char *message, Range *range)
        {
            return new Diagnostic(level, char_ptr_to_string(message), std::unique_ptr<Range>(range));
        }
    }
} // namespace lib_ruby_parser
