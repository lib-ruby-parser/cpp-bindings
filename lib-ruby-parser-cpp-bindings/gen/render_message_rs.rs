use super::helpers::camel_case_to_underscored;
use super::helpers::{all_messages, map_message_fields, map_messages};

pub(crate) struct RenderMessageRs {
    messages: Vec<lib_ruby_parser_nodes::Message>,
}

impl RenderMessageRs {
    pub(crate) fn new(registry: &lib_ruby_parser_nodes::Messages) -> Self {
        Self {
            messages: all_messages(registry),
        }
    }

    pub(crate) fn write(&self) {
        std::fs::write("src/render_message.rs", self.contents()).unwrap()
    }

    fn contents(&self) -> String {
        format!(
            "use crate::bindings;
use crate::Ptr;
use crate::BytePtr;

{render_message_fns}


{render_fns}
",
            render_message_fns = self.render_message_fns().join("\n\n"),
            render_fns = self.render_fns().join("\n\n")
        )
    }

    fn render_message_fns(&self) -> Vec<String> {
        map_messages(&self.messages, |m| {
            let args = map_message_fields(&m.fields, |f| {
                let field_type = match f.field_type {
                    lib_ruby_parser_nodes::MessageFieldType::Str => "BytePtr",
                    lib_ruby_parser_nodes::MessageFieldType::Byte => "*mut i8",
                };
                format!("{}: {}", f.name, field_type)
            });

            format!(
                "#[no_mangle]
pub extern \"C\" fn render_message_{lower}({args}) -> BytePtr {{
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    {map_args}
    let message = lib_ruby_parser::DiagnosticMessage::{variant} {{ {fields_construct} }};
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}}",
                lower = camel_case_to_underscored(&m.name).to_lowercase(),
                args = [
                    vec![String::from(
                        "level: bindings::ErrorLevel, loc: *mut bindings::Loc"
                    )],
                    args
                ]
                .concat()
                .join(", "),
                map_args = self.map_args(m).join("\n    "),
                variant = m.name,
                fields_construct = map_message_fields(&m.fields, |f| f.name.to_owned()).join(", ")
            )
        })
    }

    fn render_fns(&self) -> Vec<String> {
        map_messages(&self.messages, |m| {
            let args = map_message_fields(&m.fields, |f| {
                let field_type = match f.field_type {
                    lib_ruby_parser_nodes::MessageFieldType::Str => "BytePtr",
                    lib_ruby_parser_nodes::MessageFieldType::Byte => "*mut i8",
                };
                format!("{}: {}", f.name, field_type)
            });

            format!(
                "#[no_mangle]
pub extern \"C\" fn render_{lower}({args}) -> BytePtr {{
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    {map_args}
    let message = lib_ruby_parser::DiagnosticMessage::{variant} {{ {fields_construct} }};
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}}",
                lower = camel_case_to_underscored(&m.name).to_lowercase(),
                args = [
                    vec![String::from(
                        "level: bindings::ErrorLevel, loc: *mut bindings::Loc"
                    )],
                    args,
                    vec![String::from("input: BytePtr")]
                ]
                .concat()
                .join(", "),
                map_args = self.map_args(m).join("\n    "),
                variant = m.name,
                fields_construct = map_message_fields(&m.fields, |f| f.name.to_owned()).join(", ")
            )
        })
    }

    fn map_args(&self, message: &lib_ruby_parser_nodes::Message) -> Vec<String> {
        map_message_fields(&message.fields, |f| match f.field_type {
            lib_ruby_parser_nodes::MessageFieldType::Str => {
                format!("let {name} = {name}.to_string().unwrap();", name = f.name)
            }
            lib_ruby_parser_nodes::MessageFieldType::Byte => {
                format!("let {name} = {name} as u8;", name = f.name)
            }
        })
    }
}
