#include "diagnostic.h"
#include "helpers.h"

namespace lib_ruby_parser
{

    Diagnostic::Diagnostic(ErrorLevel level,
                           diagnostic_message_variant_t message,
                           std::unique_ptr<Loc> loc)
    {
        this->level = level;
        this->message = std::move(message);
        this->loc = std::move(loc);
    }

    bool Diagnostic::operator==(const Diagnostic &other)
    {
        if (level != other.level)
        {
            return false;
        }

        if (*loc != *(other.loc))
        {
            return false;
        }

        bool x = std::visit([](auto &&lhs, auto &&rhs) {
            using LhsT = std::decay_t<decltype(lhs)>;
            using RhsT = std::decay_t<decltype(rhs)>;

            if constexpr (std::is_same_v<LhsT, RhsT>)
            {
                if (*lhs == *rhs)
                {
                    return true;
                }
            }

            return false;
        },
                            message, other.message);

        return x;
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
        return os << ": " << *(diagnostic.loc.get());
    }
} // namespace lib_ruby_parser
