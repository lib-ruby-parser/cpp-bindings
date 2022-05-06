#include "diagnostic.hpp"
#include "utils.hpp"

namespace lib_ruby_parser
{
    extern "C"
    {
        char *LIB_RUBY_PARSER_render_diagnostic(
            const Diagnostic *diagnostic,
            const DecodedInput *input);
    }

    Diagnostic::Diagnostic(
        ErrorLevel level_,
        DiagnosticMessage message_,
        Loc loc_) : level(level_),
                    message(std::move(message_)),
                    loc(loc_) {}

    std::string Diagnostic::render(const DecodedInput &input) const
    {
        char *rendered_ptr = LIB_RUBY_PARSER_render_diagnostic(this, &input);
        std::string rendered(rendered_ptr);
        free(rendered_ptr);
        return rendered;
    }

    LIST_IMPL(DiagnosticList, Diagnostic, LIB_RUBY_PARSER_drop_diagnostic_list);
} // namespace lib_ruby_parser
