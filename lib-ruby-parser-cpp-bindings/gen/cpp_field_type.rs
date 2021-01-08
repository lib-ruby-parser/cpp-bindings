use lib_ruby_parser_nodes::FieldType;

pub struct CppFieldType<'a> {
    field_type: &'a FieldType,
}

impl<'a> CppFieldType<'a> {
    pub fn new(field_type: &'a FieldType) -> Self {
        Self { field_type }
    }

    pub fn as_cpp_ptr(&self) -> String {
        match &self.field_type {
            FieldType::Node => "std::unique_ptr<Node>",
            FieldType::Nodes => "std::vector<Node>",
            FieldType::MaybeNode => "std::unique_ptr<Node>",
            FieldType::Range => "std::unique_ptr<Range>",
            FieldType::MaybeRange => "std::unique_ptr<Range>",
            FieldType::Str => "std::string",
            FieldType::MaybeStr => "std::string",
            FieldType::Chars => "std::string",
            FieldType::StringValue => "std::string",
            FieldType::U8 => "size_t",
            FieldType::Usize => "size_t",
            FieldType::RawString => "std::string",
            FieldType::RegexOptions => "std::unique_ptr<Node>",
        }
        .to_owned()
    }

    pub fn must_be_moved(&self) -> bool {
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

    pub fn as_raw_ptr(&self) -> String {
        match &self.field_type {
            FieldType::Node => "Node *",
            FieldType::Nodes => "Node **",
            FieldType::MaybeNode => "Node *",
            FieldType::Range => "Range *",
            FieldType::MaybeRange => "Range *",
            FieldType::Str => "char *",
            FieldType::MaybeStr => "char *",
            FieldType::Chars => "char *",
            FieldType::StringValue => "char *",
            FieldType::U8 => "size_t ",
            FieldType::Usize => "size_t ",
            FieldType::RawString => "char *",
            FieldType::RegexOptions => "Node *",
        }
        .to_owned()
    }

    pub fn needs_len(&self) -> bool {
        match &self.field_type {
            // uses Node **
            FieldType::Nodes => true,

            // uses char *
            FieldType::Str
            | FieldType::MaybeStr
            | FieldType::Chars
            | FieldType::StringValue
            | FieldType::RawString => false,

            // uses Node *
            FieldType::Node | FieldType::MaybeNode | FieldType::RegexOptions => false,

            // uses Range *
            FieldType::Range | FieldType::MaybeRange => false,

            // uses size_t
            FieldType::U8 | FieldType::Usize => false,
        }
    }
}
