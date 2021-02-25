#include "diagnostic.h"
#include "helpers.h"

namespace lib_ruby_parser
{
    class Loc
    {
    public:
        bool operator!=(const Loc &other);
        friend std::ostream &operator<<(std::ostream &os, const Loc &loc);
    };

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

    extern "C"
    {
        BytePtr render_message_diagnostic(Diagnostic *diagnostic);
        BytePtr render_diagnostic(Diagnostic *diagnostic, BytePtr input);
    }

    std::string Diagnostic::render_message()
    {
        BytePtr ptr = render_message_diagnostic(this);
        return byte_ptr_to_owned_string(ptr);
    }
    std::string Diagnostic::render(const Bytes &input)
    {
        BytePtr ptr = render_diagnostic(this, input.borrow_ptr());
        return byte_ptr_to_owned_string(ptr);
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
