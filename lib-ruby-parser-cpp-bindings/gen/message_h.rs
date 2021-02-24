pub(crate) struct MessageH {
    messages: Vec<lib_ruby_parser_nodes::Message>,
}

impl MessageH {
    pub(crate) fn new(registry: &lib_ruby_parser_nodes::Messages) -> Self {
        let messages = registry
            .sections
            .iter()
            .flat_map(|s| s.messages.to_owned())
            .collect();
        Self { messages }
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
        self.messages
            .iter()
            .map(|m| MessageClass::new(m).code())
            .collect()
    }

    fn variants(&self) -> Vec<String> {
        self.messages
            .iter()
            .map(|m| format!("std::unique_ptr<{}>", m.name))
            .collect()
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
        self.message
            .fields
            .iter()
            .map(|f| format!("{};", CppField::new(f).to_cpp_string()))
            .collect()
    }

    fn args(&self) -> Vec<String> {
        self.message
            .fields
            .iter()
            .map(|f| CppField::new(f).to_cpp_string())
            .collect()
    }
}

pub(crate) struct CppField {
    pub(crate) cpp_field_type: String,
    pub(crate) c_field_type: String,
    pub(crate) field_name: String,
}

impl CppField {
    pub(crate) fn new(field: &lib_ruby_parser_nodes::MessageField) -> Self {
        let cpp_field_type = match &field.field_type {
            lib_ruby_parser_nodes::MessageFieldType::Str => "std::string",
            lib_ruby_parser_nodes::MessageFieldType::Byte => "char",
        }
        .to_owned();

        let c_field_type = match &field.field_type {
            lib_ruby_parser_nodes::MessageFieldType::Str => "BytePtr",
            lib_ruby_parser_nodes::MessageFieldType::Byte => "char",
        }
        .to_owned();

        let field_name = match &field.name[..] {
            "operator" => "operator_",
            other => other,
        }
        .to_owned();

        Self {
            cpp_field_type,
            c_field_type,
            field_name,
        }
    }

    pub(crate) fn to_cpp_string(&self) -> String {
        format!("{} {}", self.cpp_field_type, self.field_name)
    }

    pub(crate) fn to_c_string(&self) -> String {
        format!("{} {}", self.c_field_type, self.field_name)
    }
}

// pub(crate) fn message_ctor_args(message: &lib_ruby_parser_nodes::Message) -> Vec<String> {
//     message
//             .fields
//             .iter()
//             .map(|f| {
//                 format!(
//                     "{} {}",
//                     cpp_message_field_type(&f.field_type),
//                     cpp_message_field_name(&f.name)
//                 )
//             })
//             .collect()
// }

// pub(crate) fn cpp_message_field_type(field_type: &lib_ruby_parser_nodes::MessageFieldType) -> &str {
//     match field_type {
//         lib_ruby_parser_nodes::MessageFieldType::Str => "std::string",
//         lib_ruby_parser_nodes::MessageFieldType::Byte => "char",
//     }
// }

// pub(crate) fn cpp_message_field_name(name: &str) -> String {
//     match name {
//         "operator" => "operator_",
//         other => other,
//     }
//     .to_owned()
// }
