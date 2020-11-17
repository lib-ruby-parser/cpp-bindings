extern crate bindgen;
extern crate lib_ruby_parser_nodes;

use std::path::Path;

mod gen;
use gen::CppFile;

fn relative_path(path: &str) -> String {
    Path::new(file!())
        .parent()
        .unwrap()
        .join(path)
        .to_str()
        .unwrap()
        .to_owned()
}

fn build_cpp_files() {
    let nodes = lib_ruby_parser_nodes::nodes().unwrap();
    let cpp_file = CppFile::new(&nodes);

    std::fs::write(&relative_path("../includes/gen.h"), cpp_file.classes_code()).unwrap();
    std::fs::write(
        &relative_path("../includes/make_node.h"),
        cpp_file.make_node_code(),
    )
    .unwrap();
}

fn main() {
    build_cpp_files();
}
