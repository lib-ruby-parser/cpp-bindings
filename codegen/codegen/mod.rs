use lib_ruby_parser_nodes::LiquidTemplate;

fn render(template_path: &str, output_path: &str) {
    let rendered = LiquidTemplate::new(template_path).render();
    std::fs::write(output_path, rendered).unwrap();
}

pub(crate) fn codegen() {
    render("codegen/messages.hpp.liquid", "../messages.hpp");
    render("codegen/messages.cpp.liquid", "../messages.cpp");

    render("codegen/nodes.hpp.liquid", "../nodes.hpp");
    render("codegen/nodes.cpp.liquid", "../nodes.cpp");

    render(
        "codegen/message.rs.liquid",
        "../ruby-parser-cpp/src/message.rs",
    );
    render("codegen/node.rs.liquid", "../ruby-parser-cpp/src/node.rs");
}
