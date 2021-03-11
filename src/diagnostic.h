#ifndef LIB_RUBY_PARSER_DIAGNOSTIC_H
#define LIB_RUBY_PARSER_DIAGNOSTIC_H

#include <string>
#include <memory>
#include <iostream>
#include "error_level.h"
#include "bytes.h"
#include "loc.h"
#include "message.h"

namespace lib_ruby_parser
{
    // Diagnostic message returned from the parser
    class Diagnostic
    {
    public:
        // Level of the diagnostic (error or warning)
        ErrorLevel level;

        // Message of the diagnostic
        std::unique_ptr<DiagnosticMessage> message;

        // Location of the diagnostic
        std::unique_ptr<Loc> loc;

        Diagnostic() = delete;
        Diagnostic(Diagnostic &&) = default;
        Diagnostic(const Diagnostic &) = delete;
        explicit Diagnostic(ErrorLevel level,
                            std::unique_ptr<DiagnosticMessage> message,
                            std::unique_ptr<Loc> loc);

        // Renders a message of the diagnostic into a string
        std::string render_message() const;

        // Renders full diagnostic into a string
        std::string render(const Bytes &input) const;
    };

} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_DIAGNOSTIC_H
