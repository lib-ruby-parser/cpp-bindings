#ifndef LIB_RUBY_PARSER_MESSAGE_H
#define LIB_RUBY_PARSER_MESSAGE_H

#include <string>
#include <variant>
#include <memory>
#include "gen/messages/variant.h"

namespace lib_ruby_parser
{
    // Generic message of the diagnostic (tagged union)
    class DiagnosticMessage
    {
    public:
        // std::variant of all possible messages
        diagnostic_message_variant_t variant;
        DiagnosticMessage(diagnostic_message_variant_t variant);

        // Returns `true` if `DiagnosticMessage` holds requested variant
        template <typename T>
        bool is() const
        {
            return std::holds_alternative<std::unique_ptr<T>>(variant);
        }

        // Returns pointer to requested variant.
        // `diagnostic_message.is<Foo>()` must be used before calling
        // `Foo *foo = diagnostic_message.get<Foo>()`
        template <typename T>
        T *get() const
        {
            return std::get<std::unique_ptr<T>>(variant).get();
        }
    };

}

#endif // LIB_RUBY_PARSER_MESSAGE_H
