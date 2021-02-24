use super::helpers::MessageCppField;
use super::helpers::{all_messages, camel_case_to_underscored, map_message_fields, map_messages};

pub(crate) struct MakeMessageCpp {
    messages: Vec<lib_ruby_parser_nodes::Message>,
}

impl MakeMessageCpp {
    pub(crate) fn new(registry: &lib_ruby_parser_nodes::Messages) -> Self {
        Self {
            messages: all_messages(registry),
        }
    }

    pub(crate) fn write(&self) {
        std::fs::write("../src/make_message.cpp", self.contents()).unwrap()
    }

    fn contents(&self) -> String {
        format!(
            "#include \"make_message.h\"
#include \"diagnostic.h\"

namespace lib_ruby_parser {{

{make_fns}

}}
",
            make_fns = self.make_fns().join("\n")
        )
    }

    fn make_fns(&self) -> Vec<String> {
        map_messages(&self.messages, |m| MakeFn::new(m).code())
    }
}

struct MakeFn<'a> {
    message: &'a lib_ruby_parser_nodes::Message,
}

impl<'a> MakeFn<'a> {
    fn new(message: &'a lib_ruby_parser_nodes::Message) -> Self {
        Self { message }
    }

    fn code(&self) -> String {
        format!(
            "Diagnostic *make_{lower}({ctor_args})
{{
    diagnostic_message_variant_t message = std::make_unique<{class_name}>({c_message_args_to_cpp});
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}}",
            lower = camel_case_to_underscored(&self.message.name).to_lowercase(),
            ctor_args = [
                vec![String::from("ErrorLevel level, Loc *loc")],
                self.message_ctor_args()
            ]
            .concat()
            .join(", "),
            class_name = self.message.name,
            c_message_args_to_cpp = self.c_message_args_to_cpp().join(", ")
        )
    }

    fn message_ctor_args(&self) -> Vec<String> {
        map_message_fields(&self.message.fields, |f| {
            MessageCppField::new(f).to_c_string()
        })
    }

    fn c_message_args_to_cpp(&self) -> Vec<String> {
        map_message_fields(&self.message.fields, |f| {
            let field_name = MessageCppField::new(f).field_name;
            match f.field_type {
                lib_ruby_parser_nodes::MessageFieldType::Str => {
                    format!("byte_ptr_to_owned_string({})", field_name)
                }
                lib_ruby_parser_nodes::MessageFieldType::Byte => field_name,
            }
        })
    }
}
