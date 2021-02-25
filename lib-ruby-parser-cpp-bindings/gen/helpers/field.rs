pub(crate) struct Field<'a> {
    field: &'a lib_ruby_parser_nodes::Field,
}

impl<'a> Field<'a> {
    pub(crate) fn new(field: &'a lib_ruby_parser_nodes::Field) -> Self {
        Self { field }
    }

    pub(crate) fn cpp_name(&self) -> String {
        let result = self.field.field_name.to_owned();
        match &result[..] {
            "default" => "default_",
            "operator" => "operator_",
            other => other,
        }
        .to_owned()
    }
}
