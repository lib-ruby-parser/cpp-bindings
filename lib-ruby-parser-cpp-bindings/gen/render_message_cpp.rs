use std::ops::Deref;

use super::helpers::{
    all_messages, camel_case_to_underscored, map_message_fields, map_messages, MessageCppField,
};

pub(crate) struct RenderMessageCpp {
    messages: Vec<lib_ruby_parser_nodes::Message>,
}

impl RenderMessageCpp {
    pub(crate) fn new(registry: &lib_ruby_parser_nodes::Messages) -> Self {
        Self {
            messages: all_messages(registry),
        }
    }

    pub(crate) fn write(&self) {
        std::fs::write("../src/render_message.cpp", self.contents()).unwrap()
    }

    fn contents(&self) -> String {
        format!(
            "#include \"render_message.h\"
#include \"diagnostic.h\"

namespace lib_ruby_parser {{

extern \"C\" {{

BytePtr render_message_diagnostic(Diagnostic *diagnostic)
{{
    return std::visit([diagnostic](auto &&message) {{
        using MessageT = std::decay_t<decltype(message)>;

        {render_message_if_constexp_branches}
    }}, diagnostic->message);
}}

BytePtr render_diagnostic(Diagnostic *diagnostic, BytePtr input)
{{
    return std::visit([diagnostic, input](auto &&message) {{
        using MessageT = std::decay_t<decltype(message)>;

        {render_if_constexp_branches}
    }}, diagnostic->message);
}}

}}

}}
",
            render_message_if_constexp_branches = self
                .render_message_if_constexp_branches()
                .join("\n        "),
            render_if_constexp_branches = self.render_if_constexp_branches().join("\n        ")
        )
    }

    fn render_message_if_constexp_branches(&self) -> Vec<String> {
        self.map_fields_to_call("render_message_", &[])
    }

    fn render_if_constexp_branches(&self) -> Vec<String> {
        self.map_fields_to_call("render_", &["input"])
    }

    fn map_fields_to_call(&self, prefix: &str, extra_args: &[&str]) -> Vec<String> {
        let extra_args = extra_args
            .iter()
            .map(|s| s.deref().to_owned())
            .collect::<Vec<_>>();

        map_messages(&self.messages, |m| {
            let args = map_message_fields(&m.fields, |f| {
                let field_name = MessageCppField::new(f).field_name;
                match f.field_type {
                    lib_ruby_parser_nodes::MessageFieldType::Str => format!(
                        "make_byte_ptr(message->{f}.c_str(), message->{f}.length())",
                        f = field_name
                    ),
                    lib_ruby_parser_nodes::MessageFieldType::Byte => {
                        format!("message->{}", field_name)
                    }
                }
            });

            format!(
                "if constexpr (std::is_same_v<MessageT, std::unique_ptr<{class_name}>>) {{
            return {prefix}{lower}({args});
        }}",
                class_name = m.name,
                prefix = prefix,
                lower = camel_case_to_underscored(&m.name).to_lowercase(),
                args = [
                    vec![String::from("diagnostic->level, diagnostic->loc.get()")],
                    args,
                    extra_args.clone()
                ]
                .concat()
                .join(", ")
            )
        })
    }
}
