use super::CppFieldType;
use lib_ruby_parser_nodes::Field;

pub struct CppField<'a> {
    field: &'a Field,
    cpp_field_type: CppFieldType<'a>,
}

impl<'a> CppField<'a> {
    pub fn new(field: &'a Field) -> Self {
        let cpp_field_type = CppFieldType::new(&field.field_type);
        Self {
            field,
            cpp_field_type,
        }
    }

    pub fn field_name(&self) -> String {
        let result = self.field.field_name.to_owned();
        match &result[..] {
            "default" => "default_",
            "operator" => "operator_",
            other => other,
        }
        .to_owned()
    }

    pub fn declaration(&self) -> String {
        format!(
            "    {field_type} {field_name};",
            field_type = self.cpp_field_type.as_cpp_ptr(),
            field_name = self.field_name()
        )
    }
    pub fn constructor_arg(&self) -> String {
        format!(
            "{field_type} {field_name}",
            field_type = self.cpp_field_type.as_cpp_ptr(),
            field_name = self.field_name()
        )
    }

    pub fn raw_constructor_arg(&self) -> String {
        let mut result = format!(
            "{ptr_type} {ptr_name}",
            ptr_type = self.cpp_field_type.as_raw_ptr(),
            ptr_name = self.field_name()
        );

        if self.cpp_field_type.needs_len() {
            result.push_str(&format!(", size_t {}_len", self.field_name()));
        }
        result
    }

    pub fn raw_field_names(&self) -> Vec<String> {
        let mut result = vec![self.field_name()];
        if self.cpp_field_type.needs_len() {
            result.push(format!("{}_len", self.field_name()));
        }
        result
    }

    pub fn initializer(&self) -> String {
        let arg_value = if self.cpp_field_type.must_be_moved() {
            format!("std::move({})", self.field_name())
        } else {
            self.field_name()
        };
        format!(
            "{field_name}({arg_value})",
            field_name = self.field_name(),
            arg_value = arg_value
        )
    }

    pub fn raw_initializer(&self) -> String {
        let construct = match self.field.field_type {
            lib_ruby_parser_nodes::FieldType::Node
            | lib_ruby_parser_nodes::FieldType::MaybeNode
            | lib_ruby_parser_nodes::FieldType::RegexOptions => {
                format!("std::unique_ptr<Node>({})", self.field_name())
            }
            lib_ruby_parser_nodes::FieldType::Nodes => format!(
                "node_ptr_to_vec({name}, {name}_len)",
                name = self.field_name()
            ),
            lib_ruby_parser_nodes::FieldType::Range
            | lib_ruby_parser_nodes::FieldType::MaybeRange => {
                format!("std::unique_ptr<Range>({})", self.field_name())
            }
            lib_ruby_parser_nodes::FieldType::Str
            | lib_ruby_parser_nodes::FieldType::MaybeStr
            | lib_ruby_parser_nodes::FieldType::Chars
            | lib_ruby_parser_nodes::FieldType::StringValue
            | lib_ruby_parser_nodes::FieldType::RawString => format!(
                "char_ptr_to_string({name}, {name}_len)",
                name = self.field_name()
            ),

            lib_ruby_parser_nodes::FieldType::U8 | lib_ruby_parser_nodes::FieldType::Usize => {
                format!("{}", self.field_name())
            }
        };

        format!(
            "{field_name}({construct})",
            field_name = self.field_name(),
            construct = construct
        )
    }
}
