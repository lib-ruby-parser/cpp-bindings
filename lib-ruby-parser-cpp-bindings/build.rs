#[cfg(feature = "generate-bindings")]
extern crate bindgen;
#[cfg(feature = "generate-bindings")]
extern crate lib_ruby_parser_nodes;

#[cfg(feature = "generate-bindings")]
mod gen;

#[cfg(feature = "generate-bindings")]
fn build_cpp_files() {
    let nodes = lib_ruby_parser_nodes::nodes();

    gen::NodeH::new(&nodes).write();
    gen::NodeCpp::new(&nodes).write();

    gen::MakeNodeH::new(&nodes).write();
    gen::MakeNodeCpp::new(&nodes).write();

    let messages = lib_ruby_parser_nodes::messages();

    gen::MessageH::new(&messages).write();
    gen::MessageCpp::new(&messages).write();

    gen::MakeMessageH::new(&messages).write();
    gen::MakeMessageCpp::new(&messages).write();

    gen::RenderMessageH::new(&messages).write();
    gen::RenderMessageCpp::new(&messages).write();
}

#[cfg(feature = "generate-bindings")]
fn build_bindings() {
    println!("cargo:rerun-if-changed=../src/low_level.h");
    println!("cargo:rerun-if-changed=../src/comment_type.h");
    println!("cargo:rerun-if-changed=../src/error_level.h");
    println!("cargo:rerun-if-changed=../src/magic_comment_kind.h");
    println!("cargo:rerun-if-changed=../src/byte_ptr.h");

    let bindings = bindgen::Builder::default()
        .header("../src/low_level.h")
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

    bindings
        .write_to_file("src/bindings.rs")
        .expect("Couldn't write bindings!");
}

#[cfg(feature = "generate-bindings")]
fn build_rust_files() {
    let nodes = lib_ruby_parser_nodes::nodes();

    gen::CppFromRustGen::new(&nodes).write();

    let messages = lib_ruby_parser_nodes::messages();
    gen::MessageGenRs::new(&messages).write();
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
        "Running with disabled 'generate-bindings' feature, so bindgen is disabled too. All files are expected to be pre-generated"
    );
}
