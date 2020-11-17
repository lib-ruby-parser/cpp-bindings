use super::CppField;
use lib_ruby_parser_nodes::Node;

pub struct CppClass<'a> {
    node: &'a Node,
    cpp_fields: Vec<CppField<'a>>,
}

impl<'a> CppClass<'a> {
    pub fn new(node: &'a Node) -> Self {
        let cpp_fields = node
            .fields
            .iter()
            .map(|f| CppField::new(f))
            .collect::<Vec<_>>();
        Self { node, cpp_fields }
    }

    pub fn class_name(&self) -> String {
        self.node.struct_name.to_owned()
    }

    pub fn code(&self) -> String {
        format!(
            "class {class_name} : InnerNode
{{
public:
{fields}
{constructor}
    {class_name}({class_name} &&) = default;
    {class_name}(const {class_name} &) = delete;
}};
",
            class_name = self.class_name(),
            fields = self.fields_declaration(),
            constructor = self.constructor()
        )
    }

    fn fields_declaration(&self) -> String {
        self.cpp_fields
            .iter()
            .map(CppField::declaration)
            .collect::<Vec<_>>()
            .join("\n")
    }

    fn constructor(&self) -> String {
        let constructor_args = self
            .cpp_fields
            .iter()
            .map(|f| format!("        {}", f.constructor_arg()))
            .collect::<Vec<_>>()
            .join(",\n");

        let initializer_list = self
            .cpp_fields
            .iter()
            .map(CppField::initializer)
            .collect::<Vec<_>>()
            .join(", ");

        format!(
            "    {constructor_name}(
{constructor_args}) : {initializer_list} {{}}",
            constructor_name = self.class_name(),
            constructor_args = constructor_args,
            initializer_list = initializer_list,
        )
    }
}
