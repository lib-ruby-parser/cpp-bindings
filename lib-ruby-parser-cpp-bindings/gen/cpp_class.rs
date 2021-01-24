use super::CppField;
use lib_ruby_parser_nodes::Node;

pub(crate) struct CppClass<'a> {
    node: &'a Node,
    cpp_fields: Vec<CppField<'a>>,
}

impl<'a> CppClass<'a> {
    pub(crate) fn new(node: &'a Node) -> Self {
        let cpp_fields = node
            .fields
            .iter()
            .map(|f| CppField::new(f))
            .collect::<Vec<_>>();
        Self { node, cpp_fields }
    }

    pub(crate) fn class_name(&self) -> String {
        self.node.struct_name.to_owned()
    }

    pub(crate) fn implementation(&self) -> String {
        let args = self
            .cpp_fields
            .iter()
            .map(CppField::constructor_arg)
            .collect::<Vec<_>>()
            .join(", ");

        let constructor = self
            .cpp_fields
            .iter()
            .map(CppField::constructor_code)
            .collect::<Vec<_>>()
            .join("\n");

        format!(
            "{class_name}::{class_name}({args})
{{
{constructor}
}}
",
            class_name = self.class_name(),
            args = args,
            constructor = constructor
        )
    }

    fn constructor_args(&self) -> Vec<String> {
        self.cpp_fields
            .iter()
            .map(|f| f.constructor_arg())
            .collect::<Vec<_>>()
    }

    fn raw_constructor_args(&self) -> String {
        self.cpp_fields
            .iter()
            .map(|f| format!("{}", f.raw_constructor_arg()))
            .collect::<Vec<_>>()
            .join(", ")
    }

    pub(crate) fn make_fn_decl(&self) -> String {
        format!(
            "Node *make_{fn_name}({arglist});",
            fn_name = self.node.filename,
            arglist = self.raw_constructor_args(),
        )
    }

    pub(crate) fn make_fn(&self) -> String {
        let args = self
            .cpp_fields
            .iter()
            .map(CppField::c_to_cpp)
            .collect::<Vec<_>>()
            .join(", ");
        format!(
            "Node *make_{fn_name}({arglist}) {{
    node_variant_t inner = std::make_unique<{class_name}>({args});
    return new Node(std::move(inner));
}}",
            class_name = self.class_name(),
            fn_name = self.node.filename,
            arglist = self.raw_constructor_args(),
            args = args
        )
    }

    pub(crate) fn definition(&self) -> String {
        let fields = self
            .cpp_fields
            .iter()
            .map(CppField::declaration)
            .collect::<Vec<_>>()
            .join("\n");

        format!(
            "
class {class_name}
{{
public:
{fields}

    {class_name}() = delete;
    {class_name}({class_name} &&) = default;
    {class_name}(const {class_name} &) = delete;
    explicit {class_name}({constructor_args});
}};",
            class_name = self.class_name(),
            fields = fields,
            constructor_args = self.constructor_args().join(", ")
        )
    }
}
