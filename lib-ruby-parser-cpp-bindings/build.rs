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
}

fn build_bindings() {
    println!("cargo:rerun-if-changed=../includes/diagnostic.h");
    println!("cargo:rerun-if-changed=../includes/comment.h");
    println!("cargo:rerun-if-changed=../includes/helpers.h");
    println!("cargo:rerun-if-changed=../includes/lib-ruby-parser.h");
    println!("cargo:rerun-if-changed=../includes/magic_comment.h");
    println!("cargo:rerun-if-changed=../includes/parser_result.h");
    println!("cargo:rerun-if-changed=../includes/range.h");
    println!("cargo:rerun-if-changed=../includes/token.h");
    println!("cargo:rerun-if-changed=../includes/decoder.h");
    println!("cargo:rerun-if-changed=../includes/token_rewriter.h");
    println!("cargo:rerun-if-changed=../includes/types.h");

    let bindings_h = relative_path("../includes/gen.h");

    let bindings = bindgen::Builder::default()
        .header(bindings_h)
        .clang_args(&["-v", "-x", "c++", "-std=c++17"])
        .disable_name_namespacing()
        .opaque_type("std::.*")
        .whitelist_function("lib_ruby_parser::.*")
        .whitelist_type("lib_ruby_parser::.*")
        .whitelist_var("lib_ruby_parser::.*")
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
