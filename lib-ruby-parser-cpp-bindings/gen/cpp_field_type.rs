use lib_ruby_parser_nodes::FieldType;

pub(crate) struct CppFieldType<'a> {
    field_type: &'a FieldType,
}

impl<'a> CppFieldType<'a> {
    pub(crate) fn new(field_type: &'a FieldType) -> Self {
        Self { field_type }
    }

    pub(crate) fn as_cpp_ptr(&self) -> String {
        match &self.field_type {
            FieldType::Node => "std::unique_ptr<Node>",
            FieldType::Nodes => "std::vector<Node>",
            FieldType::MaybeNode => "std::unique_ptr<Node>",
            FieldType::Range => "std::unique_ptr<Range>",
            FieldType::MaybeRange => "std::unique_ptr<Range>",
            FieldType::Str => "std::string",
            FieldType::MaybeStr => "std::string",
            FieldType::Chars => "std::string",
            FieldType::StringValue => "Bytes",
            FieldType::U8 => "uint32_t",
            FieldType::Usize => "uint32_t",
            FieldType::RawString => "std::string",
            FieldType::RegexOptions => "std::unique_ptr<Node>",
        }
        .to_owned()
    }

    pub(crate) fn must_be_moved(&self) -> bool {
        match &self.field_type {
            FieldType::Node
            | FieldType::MaybeNode
            | FieldType::Range
            | FieldType::Nodes
            | FieldType::MaybeRange
            | FieldType::RegexOptions
            | FieldType::Str
            | FieldType::MaybeStr
            | FieldType::Chars
            | FieldType::StringValue
            | FieldType::RawString => true,

            FieldType::U8 | FieldType::Usize => false,
        }
    }

    pub(crate) fn as_raw_ptr(&self) -> String {
        match &self.field_type {
            FieldType::Node => "Node *",
            FieldType::Nodes => "NodeVec",
            FieldType::MaybeNode => "Node *",
            FieldType::Range => "Range *",
            FieldType::MaybeRange => "Range *",
            FieldType::Str => "BytePtr",
            FieldType::MaybeStr => "BytePtr",
            FieldType::Chars => "BytePtr",
            FieldType::StringValue => "BytePtr",
            FieldType::U8 => "uint32_t ",
            FieldType::Usize => "uint32_t ",
            FieldType::RawString => "BytePtr",
            FieldType::RegexOptions => "Node *",
        }
        .to_owned()
    }
}
