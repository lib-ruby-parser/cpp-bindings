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
            "class {class_name}
{{
public:
{fields}
{constructor}
    {class_name}() = delete;
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

    fn raw_constructor_args(&self) -> String {
        self.cpp_fields
            .iter()
            .map(|f| format!("        {}", f.raw_constructor_arg()))
            .collect::<Vec<_>>()
            .join(",\n")
    }

    //     fn raw_constructor(&self) -> String {
    //         let raw_initializer_list = self
    //             .cpp_fields
    //             .iter()
    //             .map(CppField::raw_initializer)
    //             .collect::<Vec<_>>()
    //             .join(", ");

    //         format!(
    //             "    explicit {constructor_name}(
    // {raw_constructor_args}) : {raw_initializer_list} {{}}",
    //             constructor_name = self.class_name(),
    //             raw_constructor_args = self.raw_constructor_args(),
    //             raw_initializer_list = raw_initializer_list,
    //         )
    //     }

    pub fn make_fn(&self) -> String {
        let args = self
            .cpp_fields
            .iter()
            .map(CppField::c_to_cpp)
            .collect::<Vec<_>>()
            .join(", ");
        format!(
            "Node *make_{fn_name}(
{arglist}) {{
    node_variant_t inner = std::make_unique<{class_name}>({args});
    return new Node(std::move(inner));
}}",
            class_name = self.class_name(),
            fn_name = self.node.filename,
            arglist = self.raw_constructor_args(),
            args = args
        )
    }

    pub fn forward_decl(&self) -> String {
        format!("class {};", self.class_name())
    }
}
