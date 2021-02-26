use crate::gen::helpers::MessageCppField;
use crate::gen::helpers::{
    all_messages, camel_case_to_underscored, map_message_fields, map_messages,
};

pub(crate) struct MakeH {
    messages: Vec<lib_ruby_parser_nodes::Message>,
}

impl MakeH {
    pub(crate) fn new(registry: &lib_ruby_parser_nodes::Messages) -> Self {
        Self {
            messages: all_messages(registry),
        }
    }

    pub(crate) fn write(&self) {
        std::fs::write("../src/gen/messages/make.h", self.contents()).unwrap()
    }

    fn contents(&self) -> String {
        format!(
            "#ifndef LIB_RUBY_PARSER_MAKE_MESSAGE_H
#define LIB_RUBY_PARSER_MAKE_MESSAGE_H

#include \"../../error_level.h\"
#include \"../../byte_ptr.h\"

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
        map_messages(&self.messages, |m| {
            let args = map_message_fields(&m.fields, |f| MessageCppField::new(f).to_c_string());
            format!(
                "Diagnostic *make_{lower}({args});",
                lower = camel_case_to_underscored(&m.name).to_lowercase(),
                args = [vec![String::from("ErrorLevel level, Loc *loc")], args]
                    .concat()
                    .join(", ")
            )
        })
    }
}
