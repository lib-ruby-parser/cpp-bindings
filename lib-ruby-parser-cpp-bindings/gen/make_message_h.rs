use super::message_h::CppField;

pub(crate) struct MakeMessageH {
    messages: Vec<lib_ruby_parser_nodes::Message>,
}

impl MakeMessageH {
    pub(crate) fn new(registry: &lib_ruby_parser_nodes::Messages) -> Self {
        let messages = registry
            .sections
            .iter()
            .flat_map(|s| s.messages.to_owned())
            .collect();
        Self { messages }
    }

    pub(crate) fn write(&self) {
        std::fs::write("../src/make_message.h", self.contents()).unwrap()
    }

    fn contents(&self) -> String {
        format!(
            "#ifndef LIB_RUBY_PARSER_MAKE_MESSAGE_H
#define LIB_RUBY_PARSER_MAKE_MESSAGE_H

#include \"error_level.h\"
#include \"byte_ptr.h\"

namespace lib_ruby_parser {{

class Diagnostic;
class Loc;

extern \"C\" {{

{make_fns}

}}

}}

#endif // LIB_RUBY_PARSER_MAKE_MESSAGE_H
",
            make_fns = self.make_fns().join("\n")
        )
    }

    fn make_fns(&self) -> Vec<String> {
        self.messages
            .iter()
            .map(|m| {
                let args = m
                    .fields
                    .iter()
                    .map(|f| CppField::new(f).to_c_string())
                    .collect::<Vec<_>>();
                format!(
                    "Diagnostic *make_{lower}({args});",
                    lower = camel_case_to_underscored(&m.name).to_lowercase(),
                    args = [vec![String::from("ErrorLevel level, Loc *loc")], args]
                        .concat()
                        .join(", ")
                )
            })
            .collect()
    }
}

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
