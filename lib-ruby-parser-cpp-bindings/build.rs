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

    std::fs::write(&relative_path("../includes/node.h"), cpp_file.node_h()).unwrap();
    std::fs::write(&relative_path("../includes/node.cpp"), cpp_file.node_cpp()).unwrap();

    std::fs::write(
        &relative_path("../includes/make_node.h"),
        cpp_file.make_node_h(),
    )
    .unwrap();

    std::fs::write(
        &relative_path("../includes/make_node.cpp"),
        cpp_file.make_node_cpp(),
    )
    .unwrap();
}

fn build_bindings() {
    println!("cargo:rerun-if-changed=../includes/low_level.h");
    println!("cargo:rerun-if-changed=../includes/comment_type.h");
    println!("cargo:rerun-if-changed=../includes/error_level.h");
    println!("cargo:rerun-if-changed=../includes/magic_comment_kind.h");

    let bindings_h = relative_path("../includes/low_level.h");

    let bindings = bindgen::Builder::default()
        .header(bindings_h)
        .clang_args(&["-v", "-x", "c++", "-std=c++17"])
        .disable_name_namespacing()
        .opaque_type("std::.*")
        .whitelist_function("lib_ruby_parser::.*")
        .whitelist_type("lib_ruby_parser::.*")
        .whitelist_var("lib_ruby_parser::.*")
        .derive_copy(true)
        .rustified_enum("lib_ruby_parser::CommentType")
        .rustified_enum("lib_ruby_parser::MagicCommentKind")
        .rustified_enum("lib_ruby_parser::ErrorLevel")
        .rustified_enum("lib_ruby_parser::low_level::token_rewriter::RawRewriteAction")
        .rustified_enum("lib_ruby_parser::low_level::token_rewriter::RawLexStateAction")
        .layout_tests(false)
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
