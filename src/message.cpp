#include "message.h"

namespace lib_ruby_parser
{
    DiagnosticMessage::DiagnosticMessage(diagnostic_message_variant_t variant) : variant(std::move(variant)) {}
}
