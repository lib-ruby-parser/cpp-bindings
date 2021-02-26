use crate::gen::helpers::camel_case_to_underscored;
use crate::gen::helpers::{all_messages, map_message_fields, map_messages};

pub(crate) struct Messages {
    messages: Vec<lib_ruby_parser_nodes::Message>,
}

impl Messages {
    pub(crate) fn new(registry: &lib_ruby_parser_nodes::Messages) -> Self {
        Self {
            messages: all_messages(registry),
        }
    }

    pub(crate) fn write(&self) {
        std::fs::write("src/gen/messages.rs", self.contents()).unwrap()
    }

    fn contents(&self) -> String {
        format!(
            "use crate::bindings;
use crate::Ptr;
use crate::BytePtr;

impl From<lib_ruby_parser::Diagnostic> for Ptr<bindings::Diagnostic> {{
    fn from(diagnostic: lib_ruby_parser::Diagnostic) -> Self {{
        let lib_ruby_parser::Diagnostic {{ message, level, loc }} = diagnostic;
        let level = bindings::ErrorLevel::from(&level);
        let loc = Ptr::<bindings::Loc>::from(loc).unwrap();

        let ptr = match message {{
            {match_branches}
        }};

        Ptr::new(ptr)
    }}
}}",
            match_branches = self.match_branches().join(",\n            ")
        )
    }

    fn match_branches(&self) -> Vec<String> {
        map_messages(&self.messages, |m| MatchBranch::new(m).code())
    }
}

struct MatchBranch<'a> {
    message: &'a lib_ruby_parser_nodes::Message,
}

impl<'a> MatchBranch<'a> {
    fn new(message: &'a lib_ruby_parser_nodes::Message) -> Self {
        Self { message }
    }

    fn code(&self) -> String {
        format!(
            "lib_ruby_parser::DiagnosticMessage::{name} {{ {deconstruct_fields} }} => {{
                {stmts}
            }}",
            name = self.message.name,
            deconstruct_fields = self.deconstruct_fields().join(", "),
            stmts = self.stmts().join("\n                "),
        )
    }

    fn deconstruct_fields(&self) -> Vec<String> {
        map_message_fields(&self.message.fields, |f| f.name.to_owned())
    }

    fn stmts(&self) -> Vec<String> {
        [
            self.map_fields(),
            vec![format!(
                "unsafe {{ bindings::make_{lower}(level, loc, {args}) }}",
                lower = camel_case_to_underscored(&self.message.name).to_lowercase(),
                args = self.args().join(", ")
            )],
        ]
        .concat()
    }

    fn map_fields(&self) -> Vec<String> {
        map_message_fields(&self.message.fields, |f| match f.field_type {
            lib_ruby_parser_nodes::MessageFieldType::Byte => {
                format!("let {name} = {name} as i8;", name = f.name)
            }
            lib_ruby_parser_nodes::MessageFieldType::Str => {
                format!("let {name} = BytePtr::from({name});", name = f.name)
            }
        })
    }

    fn args(&self) -> Vec<String> {
        map_message_fields(&self.message.fields, |f| f.name.to_owned())
    }
}
