ifeq ($(CARGO_BUILD_TARGET),)
	# default target
	RUST_TARGET_DIR = target
else
	CARGOFLAGS += --target $(CARGO_BUILD_TARGET)
	RUST_TARGET_DIR = target/$(CARGO_BUILD_TARGET)
endif

BINDINGS_DIR = lib-ruby-parser-cpp-bindings

ifeq ($(BUILD_ENV), debug)
	RUST_ENV = debug
	CARGOFLAGS +=
else
	RUST_ENV = release
	CARGOFLAGS += --release
endif

ifeq ($(DETECTED_OS), Windows)
	STATIC_LIB_EXT = lib
	RUST_OBJ_FILE = lib_ruby_parser_cpp_bindings.lib
endif

ifeq ($(DETECTED_OS), Linux)
	STATIC_LIB_EXT = a
	RUST_OBJ_FILE = liblib_ruby_parser_cpp_bindings.a
endif

ifeq ($(DETECTED_OS), Darwin)
	STATIC_LIB_EXT = a
	RUST_OBJ_FILE = liblib_ruby_parser_cpp_bindings.a
endif

RUST_OBJ = $(TARGET_DIR)/lib-ruby-parser-rust-static.$(STATIC_LIB_EXT)
$(RUST_OBJ):
	cd $(BINDINGS_DIR) && cargo build $(CARGOFLAGS)
	ls -l $(BINDINGS_DIR)/$(RUST_TARGET_DIR)/$(RUST_ENV)/
	cp $(BINDINGS_DIR)/$(RUST_TARGET_DIR)/$(RUST_ENV)/$(RUST_OBJ_FILE) $(RUST_OBJ)
