extern crate bindgen;
extern crate lib_ruby_parser_nodes;

use std::path::Path;

mod gen;
use gen::{CppFile, RustFile};

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
    std::fs::write(&relative_path("../includes/make.h"), cpp_file.make_code()).unwrap();

    std::fs::write(
        &relative_path("../includes/bindings.h"),
        cpp_file.bindings_code(),
    )
    .unwrap();
}

fn build_bindings() {
    println!("cargo:rerun-if-changed=../includes/bindings.h");

    let bindings_h = relative_path("../includes/bindings.h");

    let bindings = bindgen::Builder::default()
        .header(bindings_h)
        .parse_callbacks(Box::new(bindgen::CargoCallbacks))
        .clang_args(&["-x", "c++"])
        .generate()
        .expect("Unable to generate bindings");

    let out_path = relative_path("src/bindings.rs");
    bindings
        .write_to_file(out_path)
        .expect("Couldn't write bindings!");
}

fn build_rust_files() {
    let cpp_from_rust_gen_rs = relative_path("src/cpp_from_rust_gen.rs");
    let nodes = lib_ruby_parser_nodes::nodes().unwrap();

    std::fs::write(&cpp_from_rust_gen_rs, RustFile::new(nodes).code()).unwrap();
}

fn main() {
    build_cpp_files();
    build_bindings();
    build_rust_files();
}
