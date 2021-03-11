use crate::gen::helpers::camel_case_to_underscored;
use crate::gen::helpers::MessageCppField;
use crate::gen::helpers::{all_messages, map_message_fields, map_messages};

pub(crate) struct RenderH {
    messages: Vec<lib_ruby_parser_nodes::Message>,
}

impl RenderH {
    pub(crate) fn new(registry: &lib_ruby_parser_nodes::Messages) -> Self {
        Self {
            messages: all_messages(registry),
        }
    }

    pub(crate) fn write(&self) {
        std::fs::write("../src/gen/messages/render.h", self.contents()).unwrap()
    }

    fn contents(&self) -> String {
        format!(
            "#ifndef LIB_RUBY_PARSER_GEN_MESSAGES_RENDER_H
#define LIB_RUBY_PARSER_GEN_MESSAGES_RENDER_H

#include \"../../error_level.h\"
#include \"../../byte_ptr.h\"

namespace lib_ruby_parser {{

class Diagnostic;
class Loc;

extern \"C\" {{

{render_message_fns}

{render_fns}

BytePtr render_message_diagnostic(const Diagnostic *diagnostic);
BytePtr render_diagnostic(const Diagnostic *diagnostic, BytePtr input);

}}

}}

#endif // LIB_RUBY_PARSER_GEN_MESSAGES_RENDER_H
",
            render_message_fns = self.render_message_fns().join("\n"),
            render_fns = self.render_fns().join("\n")
        )
    }

    fn render_message_fns(&self) -> Vec<String> {
        map_messages(&self.messages, |m| {
            let args = map_message_fields(&m.fields, |f| MessageCppField::new(f).to_c_string());
            format!(
                "BytePtr render_message_{lower}({args});",
                lower = camel_case_to_underscored(&m.name).to_lowercase(),
                args = [vec![String::from("ErrorLevel level, Loc *loc")], args]
                    .concat()
                    .join(", ")
            )
        })
    }

    fn render_fns(&self) -> Vec<String> {
        map_messages(&self.messages, |m| {
            let args = map_message_fields(&m.fields, |f| MessageCppField::new(f).to_c_string());
            format!(
                "BytePtr render_{lower}({args});",
                lower = camel_case_to_underscored(&m.name).to_lowercase(),
                args = [
                    vec![String::from("ErrorLevel level, Loc *loc")],
                    args,
                    vec![String::from("BytePtr input")]
                ]
                .concat()
                .join(", ")
            )
        })
    }
}
