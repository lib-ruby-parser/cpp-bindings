#ifndef LIB_RUBY_PARSER_DIAGNOSTIC_H
#define LIB_RUBY_PARSER_DIAGNOSTIC_H

#include <string>
#include <memory>
#include <iostream>
#include "error_level.h"
#include "bytes.h"

namespace lib_ruby_parser
{
    class Loc;
    class DiagnosticMessage;

    class Diagnostic
    {
    public:
        ErrorLevel level;
        std::unique_ptr<DiagnosticMessage> message;
        std::unique_ptr<Loc> loc;

        Diagnostic() = delete;
        Diagnostic(Diagnostic &&) = default;
        Diagnostic(const Diagnostic &) = delete;
        explicit Diagnostic(ErrorLevel level,
                            std::unique_ptr<DiagnosticMessage> message,
                            std::unique_ptr<Loc> loc);

        std::string render_message();
        std::string render(const Bytes &input);
    };

} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_DIAGNOSTIC_H
