mod field;
pub(crate) use field::Field;

mod field_type;
pub(crate) use field_type::FieldType;

pub(crate) fn camel_case_to_underscored(s: &str) -> String {
    let mut words = vec![];
    let mut word = String::from("");

    for c in s.chars() {
        if c.is_uppercase() {
            // flush
            words.push(word);
            word = String::from("");
        }
        word.push(c);
    }

    words.push(word);

    words
        .into_iter()
        .filter(|w| !w.is_empty())
        .collect::<Vec<_>>()
        .join("_")
}

pub(crate) struct MessageCppField {
    pub(crate) cpp_field_type: String,
    pub(crate) c_field_type: String,
    pub(crate) field_name: String,
}

impl MessageCppField {
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

pub(crate) fn map_nodes<F: Fn(&lib_ruby_parser_nodes::Node) -> String>(
    nodes: &[lib_ruby_parser_nodes::Node],
    f: F,
) -> Vec<String> {
    nodes.iter().map(|m| f(m)).collect()
}

pub(crate) fn map_node_fields<F: Fn(&lib_ruby_parser_nodes::Field) -> String>(
    fields: &[lib_ruby_parser_nodes::Field],
    f: F,
) -> Vec<String> {
    fields.iter().map(|m| f(m)).collect()
}

pub(crate) fn map_messages<F: Fn(&lib_ruby_parser_nodes::Message) -> String>(
    messages: &[lib_ruby_parser_nodes::Message],
    f: F,
) -> Vec<String> {
    messages.iter().map(|m| f(m)).collect()
}

pub(crate) fn map_message_fields<F: Fn(&lib_ruby_parser_nodes::MessageField) -> String>(
    fields: &[lib_ruby_parser_nodes::MessageField],
    f: F,
) -> Vec<String> {
    fields.iter().map(|m| f(m)).collect()
}

pub(crate) fn all_messages(
    registry: &lib_ruby_parser_nodes::Messages,
) -> Vec<lib_ruby_parser_nodes::Message> {
    registry
        .sections
        .iter()
        .flat_map(|s| s.messages.to_owned())
        .collect()
}
