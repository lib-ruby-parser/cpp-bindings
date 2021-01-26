#[cfg(feature = "generate-bindings")]
extern crate bindgen;
#[cfg(feature = "generate-bindings")]
extern crate lib_ruby_parser_nodes;

use std::path::Path;

#[cfg(feature = "generate-bindings")]
mod gen;
#[cfg(feature = "generate-bindings")]
use gen::{CppFile, RustFile};

#[allow(dead_code)]
fn relative_path(path: &str) -> String {
    Path::new(file!())
        .parent()
        .unwrap()
        .join(path)
        .to_str()
        .unwrap()
        .to_owned()
}

#[cfg(feature = "generate-bindings")]
fn build_cpp_files() {
    let nodes = lib_ruby_parser_nodes::nodes().unwrap();
    let cpp_file = CppFile::new(&nodes);

    std::fs::write(&relative_path("../node.h"), cpp_file.node_h()).unwrap();
    std::fs::write(&relative_path("../node.cpp"), cpp_file.node_cpp()).unwrap();

    std::fs::write(&relative_path("../make_node.h"), cpp_file.make_node_h()).unwrap();

    std::fs::write(&relative_path("../make_node.cpp"), cpp_file.make_node_cpp()).unwrap();
}

#[cfg(feature = "generate-bindings")]
fn build_bindings() {
    println!("cargo:rerun-if-changed=../low_level.h");
    println!("cargo:rerun-if-changed=../comment_type.h");
    println!("cargo:rerun-if-changed=../error_level.h");
    println!("cargo:rerun-if-changed=../magic_comment_kind.h");
    println!("cargo:rerun-if-changed=../byte_ptr.h");

    let bindings_h = relative_path("../low_level.h");

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

#[cfg(feature = "generate-bindings")]
fn build_rust_files() {
    let cpp_from_rust_gen_rs = relative_path("src/cpp_from_rust_gen.rs");
    let nodes = lib_ruby_parser_nodes::nodes().unwrap();

    std::fs::write(&cpp_from_rust_gen_rs, RustFile::new(nodes).code()).unwrap();
}

#[cfg(feature = "generate-bindings")]
fn main() {
    build_cpp_files();
    build_bindings();
    build_rust_files();
}

#[cfg(not(feature = "generate-bindings"))]
fn main() {
    println!(
        "Running on Windows, so bindgen doesn't work. All files are expected to be pre-generated"
    );
}
