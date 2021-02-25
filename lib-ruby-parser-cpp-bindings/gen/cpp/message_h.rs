use crate::gen::helpers::MessageCppField;
use crate::gen::helpers::{all_messages, map_message_fields, map_messages};

pub(crate) struct MessageH {
    messages: Vec<lib_ruby_parser_nodes::Message>,
}

impl MessageH {
    pub(crate) fn new(registry: &lib_ruby_parser_nodes::Messages) -> Self {
        Self {
            messages: all_messages(registry),
        }
    }

    pub(crate) fn write(&self) {
        std::fs::write("../src/message.h", self.contents()).unwrap()
    }

    fn contents(&self) -> String {
        format!(
            "#ifndef LIB_RUBY_PARSER_MESSAGE_H
#define LIB_RUBY_PARSER_MESSAGE_H

#include <string>
#include <variant>
#include <memory>
#include \"bytes.h\"

namespace lib_ruby_parser {{

class DiagnosticMessage
{{
public:
    std::string render_message();
    std::string render(const Bytes &input);
}};

{message_classes}

using diagnostic_message_variant_t = std::variant<
    {variants}
>;

}}

#endif // LIB_RUBY_PARSER_MESSAGE_H
",
            message_classes = self.message_classes().join("\n"),
            variants = self.variants().join(",\n    ")
        )
    }

    fn message_classes(&self) -> Vec<String> {
        map_messages(&self.messages, |m| MessageClass::new(m).code())
    }

    fn variants(&self) -> Vec<String> {
        map_messages(&self.messages, |m| format!("std::unique_ptr<{}>", m.name))
    }
}

struct MessageClass<'a> {
    message: &'a lib_ruby_parser_nodes::Message,
}

impl<'a> MessageClass<'a> {
    fn new(message: &'a lib_ruby_parser_nodes::Message) -> Self {
        Self { message }
    }

    fn code(&self) -> String {
        format!(
            "class {class_name}: public DiagnosticMessage {{
public:
    {fields_declaration}
    explicit {class_name}({args});
    bool operator==(const {class_name} &other);
}};",
            class_name = self.message.name,
            fields_declaration = self.fields_declaration().join("\n    "),
            args = self.args().join(", ")
        )
    }

    fn fields_declaration(&self) -> Vec<String> {
        map_message_fields(&self.message.fields, |f| {
            format!("{};", MessageCppField::new(f).to_cpp_string())
        })
    }

    fn args(&self) -> Vec<String> {
        map_message_fields(&self.message.fields, |f| {
            MessageCppField::new(f).to_cpp_string()
        })
    }
}
