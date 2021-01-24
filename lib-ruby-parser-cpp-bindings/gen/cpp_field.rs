use super::CppFieldType;
use lib_ruby_parser_nodes::Field;

pub(crate) struct CppField<'a> {
    field: &'a Field,
    cpp_field_type: CppFieldType<'a>,
}

impl<'a> CppField<'a> {
    pub(crate) fn new(field: &'a Field) -> Self {
        let cpp_field_type = CppFieldType::new(&field.field_type);
        Self {
            field,
            cpp_field_type,
        }
    }

    pub(crate) fn field_name(&self) -> String {
        let result = self.field.field_name.to_owned();
        match &result[..] {
            "default" => "default_",
            "operator" => "operator_",
            other => other,
        }
        .to_owned()
    }

    pub(crate) fn declaration(&self) -> String {
        format!(
            "    {field_type} {field_name};",
            field_type = self.cpp_field_type.as_cpp_ptr(),
            field_name = self.field_name()
        )
    }
    pub(crate) fn constructor_arg(&self) -> String {
        format!(
            "{field_type} {field_name}",
            field_type = self.cpp_field_type.as_cpp_ptr(),
            field_name = self.field_name()
        )
    }

    pub(crate) fn constructor_code(&self) -> String {
        let mut arg_value = self.field_name();

        if self.cpp_field_type.must_be_moved() {
            arg_value = format!("std::move({})", arg_value)
        }

        format!(
            "this->{field_name} = {arg_value};",
            field_name = self.field_name(),
            arg_value = arg_value
        )
    }

    pub(crate) fn raw_constructor_arg(&self) -> String {
        format!(
            "{ptr_type} {ptr_name}",
            ptr_type = self.cpp_field_type.as_raw_ptr(),
            ptr_name = self.field_name()
        )
    }

    pub(crate) fn c_to_cpp(&self) -> String {
        match self.field.field_type {
            lib_ruby_parser_nodes::FieldType::Node
            | lib_ruby_parser_nodes::FieldType::MaybeNode
            | lib_ruby_parser_nodes::FieldType::RegexOptions => {
                format!("std::unique_ptr<Node>({})", self.field_name())
            }

            lib_ruby_parser_nodes::FieldType::Nodes => {
                format!("nodes_vec_to_cpp_vec({name})", name = self.field_name())
            }
            lib_ruby_parser_nodes::FieldType::Range
            | lib_ruby_parser_nodes::FieldType::MaybeRange => {
                format!("std::unique_ptr<Range>({})", self.field_name())
            }

            lib_ruby_parser_nodes::FieldType::U8 | lib_ruby_parser_nodes::FieldType::Usize => {
                self.field_name()
            }

            lib_ruby_parser_nodes::FieldType::Str
            | lib_ruby_parser_nodes::FieldType::MaybeStr
            | lib_ruby_parser_nodes::FieldType::Chars
            | lib_ruby_parser_nodes::FieldType::RawString => {
                format!("byte_ptr_to_owned_string({})", self.field_name())
            }
            lib_ruby_parser_nodes::FieldType::StringValue => {
                format!("Bytes({})", self.field_name())
            }
        }
    }
}
