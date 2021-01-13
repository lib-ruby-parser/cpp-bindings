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

    std::ostream &operator<<(std::ostream &os, const Diagnostic &diagnostic)
    {
        switch (diagnostic.level)
        {
        case ErrorLevel::WARNING:
            os << "WARNING";
            break;
        case ErrorLevel::ERROR:
            os << "ERROR";
            break;
        default:
            break;
        }
        return os << ": " << diagnostic.message << *(diagnostic.range.get());
    }
} // namespace lib_ruby_parser
