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
}
