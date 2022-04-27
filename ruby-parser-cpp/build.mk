RUST_SRCS = $(wildcard ruby-parser-cpp/src/*.rs)
RUST_SRCS += ruby-parser-cpp/src/node.rs
RUST_SRCS += ruby-parser-cpp/src/message.rs

ruby-parser-cpp/lib_ruby_parser_cpp.$(A): $(RUST_SRCS) ruby-parser-cpp/src/message.rs ruby-parser-cpp/src/node.rs
	RUSTFLAGS="$(RUSTFLAGS)" cargo build $(CARGOFLAGS) --manifest-path ruby-parser-cpp/Cargo.toml
	ls -l ruby-parser-cpp/target/$(TARGET)
	ls -l ruby-parser-cpp/target/$(TARGET)/$(RUST_ENV)
	cp ruby-parser-cpp/target/$(TARGET)/$(RUST_ENV)/$(STATIC_LIB_FILE) ruby-parser-cpp/lib_ruby_parser_cpp.$(A)

CLEAN += ruby-parser-cpp/lib_ruby_parser_cpp.$(A)
CLEAN += ruby-parser-cpp/target/$(TARGET)
