#ifndef LIB_RUBY_PARSER_MESSAGE_H
#define LIB_RUBY_PARSER_MESSAGE_H

#include <string>
#include <variant>
#include <memory>
#include "message_variant.h"

namespace lib_ruby_parser
{

    class DiagnosticMessage
    {
    public:
        diagnostic_message_variant_t variant;
        DiagnosticMessage(diagnostic_message_variant_t variant) : variant(std::move(variant)) {}

        template <typename T>
        bool is()
        {
            return std::holds_alternative<std::unique_ptr<T>>(variant);
        }

        template <typename T>
        T *get()
        {
            return std::get<std::unique_ptr<T>>(variant).get();
        }
    };

}

#endif // LIB_RUBY_PARSER_MESSAGE_H
