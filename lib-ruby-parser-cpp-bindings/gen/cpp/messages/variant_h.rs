use crate::gen::helpers::{all_messages, map_messages};

pub(crate) struct VariantH {
    messages: Vec<lib_ruby_parser_nodes::Message>,
}

impl VariantH {
    pub(crate) fn new(registry: &lib_ruby_parser_nodes::Messages) -> Self {
        Self {
            messages: all_messages(registry),
        }
    }

    pub(crate) fn write(&self) {
        std::fs::write("../src/gen/messages/variant.h", self.contents()).unwrap()
    }

    fn contents(&self) -> String {
        format!(
            "#ifndef LIB_RUBY_PARSER_MESSAGE_VARIANT_H
#define LIB_RUBY_PARSER_MESSAGE_VARIANT_H

#include <string>
#include <variant>
#include <memory>
#include \"classes.h\"

namespace lib_ruby_parser {{

using diagnostic_message_variant_t = std::variant<
    {variants}
>;

}}

#endif // LIB_RUBY_PARSER_MESSAGE_VARIANT_H
",
            variants = self.variants().join(",\n    "),
            // forwards = self.forwards().join("\n")
        )
    }

    fn variants(&self) -> Vec<String> {
        map_messages(&self.messages, |m| format!("std::unique_ptr<{}>", m.name))
    }
}
