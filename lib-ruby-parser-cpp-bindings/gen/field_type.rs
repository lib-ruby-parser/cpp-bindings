pub(crate) struct FieldType<'a> {
    field_type: &'a lib_ruby_parser_nodes::FieldType,
}

impl<'a> FieldType<'a> {
    pub(crate) fn new(field_type: &'a lib_ruby_parser_nodes::FieldType) -> Self {
        Self { field_type }
    }

    pub(crate) fn cpp_type(&self) -> &str {
        match &self.field_type {
            lib_ruby_parser_nodes::FieldType::Node
            | lib_ruby_parser_nodes::FieldType::MaybeNode
            | lib_ruby_parser_nodes::FieldType::RegexOptions => "std::unique_ptr<Node>",

            lib_ruby_parser_nodes::FieldType::Nodes => "std::vector<Node>",

            lib_ruby_parser_nodes::FieldType::Loc | lib_ruby_parser_nodes::FieldType::MaybeLoc => {
                "std::unique_ptr<Loc>"
            }

            lib_ruby_parser_nodes::FieldType::Str
            | lib_ruby_parser_nodes::FieldType::MaybeStr
            | lib_ruby_parser_nodes::FieldType::Chars
            | lib_ruby_parser_nodes::FieldType::RawString => "std::string",

            lib_ruby_parser_nodes::FieldType::StringValue => "Bytes",

            lib_ruby_parser_nodes::FieldType::U8 | lib_ruby_parser_nodes::FieldType::Usize => {
                "uint32_t"
            }
        }
    }

    pub(crate) fn needs_move(&self) -> bool {
        match &self.field_type {
            lib_ruby_parser_nodes::FieldType::Node
            | lib_ruby_parser_nodes::FieldType::MaybeNode
            | lib_ruby_parser_nodes::FieldType::Loc
            | lib_ruby_parser_nodes::FieldType::Nodes
            | lib_ruby_parser_nodes::FieldType::MaybeLoc
            | lib_ruby_parser_nodes::FieldType::RegexOptions
            | lib_ruby_parser_nodes::FieldType::Str
            | lib_ruby_parser_nodes::FieldType::MaybeStr
            | lib_ruby_parser_nodes::FieldType::Chars
            | lib_ruby_parser_nodes::FieldType::StringValue
            | lib_ruby_parser_nodes::FieldType::RawString => true,

            lib_ruby_parser_nodes::FieldType::U8 | lib_ruby_parser_nodes::FieldType::Usize => false,
        }
    }

    pub(crate) fn c_ptr(&self) -> &str {
        match &self.field_type {
            lib_ruby_parser_nodes::FieldType::Node
            | lib_ruby_parser_nodes::FieldType::MaybeNode
            | lib_ruby_parser_nodes::FieldType::RegexOptions => "Node *",

            lib_ruby_parser_nodes::FieldType::Nodes => "NodeVec",

            lib_ruby_parser_nodes::FieldType::Loc | lib_ruby_parser_nodes::FieldType::MaybeLoc => {
                "Loc *"
            }

            lib_ruby_parser_nodes::FieldType::Str
            | lib_ruby_parser_nodes::FieldType::MaybeStr
            | lib_ruby_parser_nodes::FieldType::Chars
            | lib_ruby_parser_nodes::FieldType::StringValue
            | lib_ruby_parser_nodes::FieldType::RawString => "BytePtr",

            lib_ruby_parser_nodes::FieldType::U8 | lib_ruby_parser_nodes::FieldType::Usize => {
                "uint32_t "
            }
        }
    }
}
