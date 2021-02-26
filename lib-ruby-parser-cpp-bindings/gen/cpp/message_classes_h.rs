use crate::gen::helpers::MessageCppField;
use crate::gen::helpers::{all_messages, map_message_fields, map_messages};

pub(crate) struct MessageClassesH {
    messages: Vec<lib_ruby_parser_nodes::Message>,
}

impl MessageClassesH {
    pub(crate) fn new(registry: &lib_ruby_parser_nodes::Messages) -> Self {
        Self {
            messages: all_messages(registry),
        }
    }

    pub(crate) fn write(&self) {
        std::fs::write("../src/message_classes.h", self.contents()).unwrap()
    }

    fn contents(&self) -> String {
        format!(
            "#ifndef LIB_RUBY_PARSER_MESSAGE_CLASSES_H
#define LIB_RUBY_PARSER_MESSAGE_CLASSES_H

#include <string>
#include <variant>
#include <memory>
#include \"bytes.h\"

namespace lib_ruby_parser {{

class BaseDiagnosticMessage
{{
public:
    std::string render_message();
    std::string render(const Bytes &input);
}};

{message_classes}

}}

#endif // LIB_RUBY_PARSER_MESSAGE_CLASSES_H
",
            message_classes = self.message_classes().join("\n"),
        )
    }

    fn message_classes(&self) -> Vec<String> {
        map_messages(&self.messages, |m| MessageClass::new(m).code())
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
            "class {class_name}: public BaseDiagnosticMessage {{
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
