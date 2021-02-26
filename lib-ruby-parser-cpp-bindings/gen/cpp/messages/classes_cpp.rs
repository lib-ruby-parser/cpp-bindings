use crate::gen::helpers::MessageCppField;
use crate::gen::helpers::{all_messages, map_message_fields, map_messages};

pub(crate) struct ClassesCpp {
    messages: Vec<lib_ruby_parser_nodes::Message>,
}

impl ClassesCpp {
    pub(crate) fn new(registry: &lib_ruby_parser_nodes::Messages) -> Self {
        Self {
            messages: all_messages(registry),
        }
    }

    pub(crate) fn write(&self) {
        std::fs::write("../src/gen/messages/classes.cpp", self.contents()).unwrap()
    }

    fn contents(&self) -> String {
        format!(
            "#include \"classes.h\"
#include <iostream>

namespace lib_ruby_parser {{

{constructors}

{comparisons}

}}
",
            constructors = self.constructors().join("\n"),
            comparisons = self.comparisons().join("\n")
        )
    }

    fn constructors(&self) -> Vec<String> {
        map_messages(&self.messages, |m| MessageConstructor::new(m).code())
    }

    fn comparisons(&self) -> Vec<String> {
        map_messages(&self.messages, |m| {
            let mut compare_fields = map_message_fields(&m.fields, |f| {
                format!("{f} == other.{f}", f = MessageCppField::new(f).field_name)
            });
            if compare_fields.is_empty() {
                compare_fields = vec!["true".to_string()];
            }

            format!(
                "bool {class_name}::operator==(const {class_name} &{other})
{{
    return {compare_fields};
}}",
                class_name = m.name,
                other = if m.fields.is_empty() { "" } else { "other" },
                compare_fields = compare_fields.join(" && ")
            )
        })
    }
}

struct MessageConstructor<'a> {
    message: &'a lib_ruby_parser_nodes::Message,
}

impl<'a> MessageConstructor<'a> {
    fn new(message: &'a lib_ruby_parser_nodes::Message) -> Self {
        Self { message }
    }

    fn code(&self) -> String {
        format!(
            "{class_name}::{class_name}({args})
{{
    {statements}
}}",
            class_name = self.message.name,
            args = self.args().join(", "),
            statements = self.statements().join("\n    ")
        )
    }

    fn args(&self) -> Vec<String> {
        map_message_fields(&self.message.fields, |f| {
            MessageCppField::new(f).to_cpp_string()
        })
    }

    fn statements(&self) -> Vec<String> {
        map_message_fields(&self.message.fields, |f| {
            format!(
                "this->{field_name} = {field_name};",
                field_name = MessageCppField::new(f).field_name
            )
        })
    }
}
