#include "diagnostic.h"
#include "helpers.h"

namespace lib_ruby_parser
{

    Diagnostic::Diagnostic(ErrorLevel level,
                           std::unique_ptr<DiagnosticMessage> message,
                           std::unique_ptr<Loc> loc)
    {
        this->level = level;
        this->message = std::move(message);
        this->loc = std::move(loc);
    }

    extern "C"
    {
        BytePtr render_message_diagnostic(const Diagnostic *diagnostic);
        BytePtr render_diagnostic(const Diagnostic *diagnostic, BytePtr input);
    }

    std::string Diagnostic::render_message() const
    {
        BytePtr ptr = render_message_diagnostic(this);
        return byte_ptr_to_owned_string(ptr);
    }

    std::string Diagnostic::render(const Bytes &input) const
    {
        BytePtr ptr = render_diagnostic(this, input.borrow_ptr());
        return byte_ptr_to_owned_string(ptr);
    }
} // namespace lib_ruby_parser
