use super::message_h::CppField;

pub(crate) struct MessageCpp {
    messages: Vec<lib_ruby_parser_nodes::Message>,
}

impl MessageCpp {
    pub(crate) fn new(registry: &lib_ruby_parser_nodes::Messages) -> Self {
        let messages = registry
            .sections
            .iter()
            .flat_map(|s| s.messages.to_owned())
            .collect();
        Self { messages }
    }

    pub(crate) fn write(&self) {
        std::fs::write("../src/message.cpp", self.contents()).unwrap()
    }

    fn contents(&self) -> String {
        format!(
            "#include \"message.h\"
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
        self.messages
            .iter()
            .map(|m| MessageConstructor::new(m).code())
            .collect()
    }

    fn comparisons(&self) -> Vec<String> {
        self.messages
            .iter()
            .map(|m| {
                let mut compare_fields = m
                    .fields
                    .iter()
                    .map(|f| format!("{f} == other.{f}", f = CppField::new(f).field_name))
                    .collect::<Vec<_>>();
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
            .collect()
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
        self.message
            .fields
            .iter()
            .map(|f| CppField::new(f).to_cpp_string())
            .collect()
    }

    fn statements(&self) -> Vec<String> {
        self.message
            .fields
            .iter()
            .map(|f| {
                format!(
                    "this->{field_name} = {field_name};",
                    field_name = CppField::new(f).field_name
                )
            })
            .collect()
    }
}
