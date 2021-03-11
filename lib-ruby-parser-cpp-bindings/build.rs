#[cfg(feature = "generate-bindings")]
extern crate bindgen;
#[cfg(feature = "generate-bindings")]
extern crate lib_ruby_parser_nodes;

#[cfg(feature = "generate-bindings")]
mod gen;

#[cfg(feature = "generate-bindings")]
fn build_cpp_files() {
    let nodes = lib_ruby_parser_nodes::nodes();

    gen::cpp::nodes::ClassesH::new(&nodes).write();
    gen::cpp::nodes::ClassesCpp::new(&nodes).write();

    gen::cpp::nodes::VariantH::new(&nodes).write();

    gen::cpp::nodes::MakeH::new(&nodes).write();
    gen::cpp::nodes::MakeCpp::new(&nodes).write();

    let messages = lib_ruby_parser_nodes::messages();

    gen::cpp::messages::ClassesH::new(&messages).write();
    gen::cpp::messages::ClassesCpp::new(&messages).write();

    gen::cpp::messages::VariantH::new(&messages).write();

    gen::cpp::messages::MakeH::new(&messages).write();
    gen::cpp::messages::MakeCpp::new(&messages).write();

    gen::cpp::messages::RenderH::new(&messages).write();
    gen::cpp::messages::RenderCpp::new(&messages).write();
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
        .whitelist_recursively(false)
        // low_level namespace
        .whitelist_function("lib_ruby_parser::low_level::.*")
        .whitelist_type("lib_ruby_parser::low_level::.*")
        .whitelist_var("lib_ruby_parser::low_level::.*")
        .blacklist_function("lib_ruby_parser::low_level::custom_decoder::CustomDecoderResult.*")
        // make_node and make_message functions
        .whitelist_function("lib_ruby_parser::make_.*")
        // extern "C" types
        .whitelist_type("lib_ruby_parser::BytePtr")
        .whitelist_type("lib_ruby_parser::NodeVec")
        // C++ class Node
        .whitelist_type("lib_ruby_parser::Node")
        .opaque_type("lib_ruby_parser::Node")
        .blacklist_function("lib_ruby_parser::Node::.*")
        .blacklist_function("lib_ruby_parser::Node_Node")
        // C++ class Loc
        .whitelist_type("lib_ruby_parser::Loc")
        .opaque_type("lib_ruby_parser::Loc")
        .blacklist_function("lib_ruby_parser::Loc.*")
        // C++ class Input
        .whitelist_type("lib_ruby_parser::Input")
        .opaque_type("lib_ruby_parser::Input")
        .blacklist_function("lib_ruby_parser::Input.*")
        // C++ class Bytes
        .whitelist_type("lib_ruby_parser::Bytes")
        .opaque_type("lib_ruby_parser::Bytes")
        .blacklist_function("lib_ruby_parser::Bytes.*")
        // C++ class Diagnostic
        .whitelist_type("lib_ruby_parser::Diagnostic")
        .opaque_type("lib_ruby_parser::Diagnostic")
        .blacklist_function("lib_ruby_parser::Diagnostic.*")
        // C++ class Token
        .whitelist_type("lib_ruby_parser::Token")
        .opaque_type("lib_ruby_parser::Token")
        .blacklist_function("lib_ruby_parser::Token.*")
        // C++ class Comment
        .whitelist_type("lib_ruby_parser::Comment")
        .opaque_type("lib_ruby_parser::Comment")
        .blacklist_function("lib_ruby_parser::Comment.*")
        // C++ class MagicComment
        .whitelist_type("lib_ruby_parser::MagicComment")
        .opaque_type("lib_ruby_parser::MagicComment")
        .blacklist_function("lib_ruby_parser::MagicComment.*")
        // C++ class CustomDecoder
        .whitelist_type("lib_ruby_parser::CustomDecoder")
        .opaque_type("lib_ruby_parser::CustomDecoder")
        .blacklist_function("lib_ruby_parser::CustomDecoder.*")
        // C++ class TokenRewriter
        .whitelist_type("lib_ruby_parser::TokenRewriter")
        .opaque_type("lib_ruby_parser::TokenRewriter")
        .blacklist_function("lib_ruby_parser::TokenRewriter.*")
        // C++ class ParserOptions
        .whitelist_type("lib_ruby_parser::ParserOptions")
        .opaque_type("lib_ruby_parser::ParserOptions")
        .blacklist_function("lib_ruby_parser::ParserOptions.*")
        // C++ class ParserResult
        .whitelist_type("lib_ruby_parser::ParserResult")
        .opaque_type("lib_ruby_parser::ParserResult")
        .blacklist_function("lib_ruby_parser::ParserResult.*")
        // C++ enum ErrorLevel
        .whitelist_type("lib_ruby_parser::ErrorLevel")
        .rustified_enum("lib_ruby_parser::ErrorLevel")
        // C++ enum CommentType
        .whitelist_type("lib_ruby_parser::CommentType")
        .rustified_enum("lib_ruby_parser::CommentType")
        // C++ enum MagicCommentKind
        .whitelist_type("lib_ruby_parser::MagicCommentKind")
        .rustified_enum("lib_ruby_parser::MagicCommentKind")
        .derive_copy(true)
        .derive_debug(true)
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

    gen::rust::Nodes::new(&nodes).write();

    let messages = lib_ruby_parser_nodes::messages();
    gen::rust::Messages::new(&messages).write();
    gen::rust::RenderMessage::new(&messages).write();
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
