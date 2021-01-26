BINDINGS_DIR = lib-ruby-parser-cpp-bindings

LINK_FLAGS = -lpthread -ldl

ifndef BUILD_ENV
	BUILD_ENV = debug
endif

ifeq ($(BUILD_ENV), debug)
	CXXFLAGS += -g -O0
	RUST_ENV = debug
	TARGET_DIR = target/debug
	CARGOFLAGS +=
else
	CXXFLAGS += -O2
	RUST_ENV = release
	TARGET_DIR = target/release
	CARGOFLAGS += --release
endif

ifeq ($(CARGO_BUILD_TARGET),)
	# default target
	RUST_TARGET_DIR = target
else
	CARGOFLAGS += --target $(CARGO_BUILD_TARGET)
	RUST_TARGET_DIR = target/$(CARGO_BUILD_TARGET)
endif

ifeq ($(OS), Windows_NT)
	DETECTED_OS = Windows
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S), Linux)
		DETECTED_OS = Linux
	else
		ifeq ($(UNAME_S), Darwin)
			DETECTED_OS = Darwin
		else
			DETECTED_OS = Unknown
		endif
	endif
endif

ifeq ($(DETECTED_OS), Linux)
	LIST_DEPS = ldd
	RUST_OBJ_FILE = liblib_ruby_parser_cpp_bindings.a
endif
ifeq ($(DETECTED_OS), Darwin)
	LIST_DEPS = otool -L
	RUST_OBJ_FILE = liblib_ruby_parser_cpp_bindings.a
endif
ifeq ($(DETECTED_OS), Windows)
	LIST_DEPS = echo
	RUST_OBJ_FILE = lib_ruby_parser_cpp_bindings.lib
endif

ifeq ($(DETECTED_OS), Windows)
	CXXFLAGS += /Wall /std:c++17
	CXXOBJFLAGS += /c /Fo
else
	CXXFLAGS += -Wall -Wextra -std=c++17
	CXXOBJFLAGS += -fPIC -c -o
endif

print-env:
	@echo "BUILD_ENV = $(BUILD_ENV)"
	@echo "CXXFLAGS = $(CXXFLAGS)"
	@echo "RUST_ENV = $(RUST_ENV)"
	@echo "CARGOFLAGS = $(CARGOFLAGS)"
	@echo "DETECTED_OS = $(DETECTED_OS)"
	@echo "LIST_DEPS = $(LIST_DEPS)"


setup:
	mkdir -p target/debug
	mkdir -p target/release

RUST_OBJ = $(TARGET_DIR)/lib-ruby-parser-rust-static
$(RUST_OBJ):
	cd $(BINDINGS_DIR) && cargo build $(CARGOFLAGS)
	ls -l $(BINDINGS_DIR)/$(RUST_TARGET_DIR)/$(RUST_ENV)/
	cp $(BINDINGS_DIR)/$(RUST_TARGET_DIR)/$(RUST_ENV)/$(RUST_OBJ_FILE) $(RUST_OBJ)

gen-headers: $(RUST_OBJ)

# objects
OBJECTS =

$(TARGET_DIR)/byte_ptr.o: includes/byte_ptr.h includes/byte_ptr.cpp
	$(CXX) includes/byte_ptr.cpp $(CXXFLAGS) $(CXXOBJFLAGS) $(TARGET_DIR)/byte_ptr.o
OBJECTS += $(TARGET_DIR)/byte_ptr.o

$(TARGET_DIR)/bytes.o: includes/bytes.h includes/bytes.cpp
	$(CXX) includes/bytes.cpp $(CXXFLAGS) $(CXXOBJFLAGS) $(TARGET_DIR)/bytes.o
OBJECTS += $(TARGET_DIR)/bytes.o

$(TARGET_DIR)/comment.o: includes/comment.h includes/comment.cpp
	$(CXX) includes/comment.cpp $(CXXFLAGS) $(CXXOBJFLAGS) $(TARGET_DIR)/comment.o
OBJECTS += $(TARGET_DIR)/comment.o

$(TARGET_DIR)/custom_decoder.o: includes/custom_decoder.h includes/custom_decoder.cpp
	$(CXX) includes/custom_decoder.cpp $(CXXFLAGS) $(CXXOBJFLAGS) $(TARGET_DIR)/custom_decoder.o
OBJECTS += $(TARGET_DIR)/custom_decoder.o

$(TARGET_DIR)/diagnostic.o: includes/diagnostic.h includes/diagnostic.cpp
	$(CXX) includes/diagnostic.cpp $(CXXFLAGS) $(CXXOBJFLAGS) $(TARGET_DIR)/diagnostic.o
OBJECTS += $(TARGET_DIR)/diagnostic.o

$(TARGET_DIR)/helpers.o: includes/helpers.h includes/helpers.cpp
	$(CXX) includes/helpers.cpp $(CXXFLAGS) $(CXXOBJFLAGS) $(TARGET_DIR)/helpers.o
OBJECTS += $(TARGET_DIR)/helpers.o

$(TARGET_DIR)/low_level.o: includes/low_level.h includes/low_level.cpp
	$(CXX) includes/low_level.cpp $(CXXFLAGS) $(CXXOBJFLAGS) $(TARGET_DIR)/low_level.o
OBJECTS += $(TARGET_DIR)/low_level.o

$(TARGET_DIR)/node.o: includes/node.h includes/node.cpp
	$(CXX) includes/node.cpp $(CXXFLAGS) $(CXXOBJFLAGS) $(TARGET_DIR)/node.o
OBJECTS += $(TARGET_DIR)/node.o

$(TARGET_DIR)/magic_comment.o: includes/magic_comment.h includes/magic_comment.cpp
	$(CXX) includes/magic_comment.cpp $(CXXFLAGS) $(CXXOBJFLAGS) $(TARGET_DIR)/magic_comment.o
OBJECTS += $(TARGET_DIR)/magic_comment.o

$(TARGET_DIR)/make_node.o: includes/make_node.h includes/make_node.cpp
	$(CXX) includes/make_node.cpp $(CXXFLAGS) $(CXXOBJFLAGS) $(TARGET_DIR)/make_node.o
OBJECTS += $(TARGET_DIR)/make_node.o

$(TARGET_DIR)/parser_options.o: includes/parser_options.h includes/parser_options.cpp
	$(CXX) includes/parser_options.cpp $(CXXFLAGS) $(CXXOBJFLAGS) $(TARGET_DIR)/parser_options.o
OBJECTS += $(TARGET_DIR)/parser_options.o

$(TARGET_DIR)/parser_result.o: includes/parser_result.h includes/parser_result.cpp
	$(CXX) includes/parser_result.cpp $(CXXFLAGS) $(CXXOBJFLAGS) $(TARGET_DIR)/parser_result.o
OBJECTS += $(TARGET_DIR)/parser_result.o

$(TARGET_DIR)/range.o: includes/range.h includes/range.cpp
	$(CXX) includes/range.cpp $(CXXFLAGS) $(CXXOBJFLAGS) $(TARGET_DIR)/range.o
OBJECTS += $(TARGET_DIR)/range.o

$(TARGET_DIR)/token_rewriter.o: includes/token_rewriter.h includes/token_rewriter.cpp
	$(CXX) includes/token_rewriter.cpp $(CXXFLAGS) $(CXXOBJFLAGS) $(TARGET_DIR)/token_rewriter.o
OBJECTS += $(TARGET_DIR)/token_rewriter.o

$(TARGET_DIR)/token.o: includes/token.h includes/token.cpp
	$(CXX) includes/token.cpp $(CXXFLAGS) $(CXXOBJFLAGS) $(TARGET_DIR)/token.o
OBJECTS += $(TARGET_DIR)/token.o

HEADERS = includes/lib-ruby-parser.h \
	includes/comment_type.h \
	includes/error_level.h \
	includes/magic_comment_kind.h

LIB_RUBY_PARSER_O = $(TARGET_DIR)/lib-ruby-parser.o
$(LIB_RUBY_PARSER_O): $(RUST_OBJ) $(OBJECTS)
	$(LD) -r $(RUST_OBJ) $(OBJECTS) -o $(LIB_RUBY_PARSER_O)

# // files

DEPS = $(LIB_RUBY_PARSER_O) $(HEADERS)

$(TARGET_DIR)/test-runner: $(DEPS) clean-includes
	$(CXX) $(LIB_RUBY_PARSER_O) test.cpp $(CXXFLAGS) $(LINK_FLAGS) -o $(TARGET_DIR)/test-runner

test: $(TARGET_DIR)/test-runner
	$(TARGET_DIR)/test-runner

test-asan: $(DEPS) clean-includes
	$(CXX) $(LIB_RUBY_PARSER_O) test.cpp -fsanitize=address $(CXXFLAGS) $(LINK_FLAGS) -o $(TARGET_DIR)/test-asan-runner
	$(TARGET_DIR)/test-asan-runner

test-valgrind: $(TARGET_DIR)/test-runner
	valgrind --leak-check=full --error-exitcode=1 --num-callers=20 $(TARGET_DIR)/test-runner

test-all: test test-valgrind test-asan

clean:
	rm -rf $(TARGET_DIR)
	mkdir -p $(TARGET_DIR)

test-cov:
	$(CXX) test.cpp $(RUST_OBJ) $(CXXFLAGS) $(LINK_FLAGS) -fprofile-instr-generate -fcoverage-mapping -o $(TARGET_DIR)/test
	LLVM_PROFILE_FILE="$(TARGET_DIR)/test.profraw" $(TARGET_DIR)/test
	llvm-profdata merge -sparse $(TARGET_DIR)/test.profraw -o $(TARGET_DIR)/test.profdata
	llvm-cov report $(TARGET_DIR)/test-runner -instr-profile=$(TARGET_DIR)/test.profdata
	# llvm-cov show $(TARGET_DIR)/test-runner -instr-profile=$(TARGET_DIR)/test.profdata

# // releases

LIB_RUBY_PARSER_TMP_H = target/lib-ruby-parser-tmp.h
LIB_RUBY_PARSER_H = target/lib-ruby-parser.h
clean-includes:
	cat includes/byte_ptr.h > $(LIB_RUBY_PARSER_TMP_H)
	cat includes/comment_type.h >> $(LIB_RUBY_PARSER_TMP_H)
	cat includes/error_level.h >> $(LIB_RUBY_PARSER_TMP_H)
	cat includes/magic_comment_kind.h >> $(LIB_RUBY_PARSER_TMP_H)

	cat includes/bytes.h >> $(LIB_RUBY_PARSER_TMP_H)
	cat includes/range.h >> $(LIB_RUBY_PARSER_TMP_H)
	cat includes/token.h >> $(LIB_RUBY_PARSER_TMP_H)

	cat includes/node.h >> $(LIB_RUBY_PARSER_TMP_H)
	cat includes/make_node.h >> $(LIB_RUBY_PARSER_TMP_H)

	cat includes/comment.h >> $(LIB_RUBY_PARSER_TMP_H)
	cat includes/custom_decoder.h >> $(LIB_RUBY_PARSER_TMP_H)
	cat includes/diagnostic.h >> $(LIB_RUBY_PARSER_TMP_H)
	cat includes/helpers.h >> $(LIB_RUBY_PARSER_TMP_H)
	cat includes/magic_comment.h >> $(LIB_RUBY_PARSER_TMP_H)
	cat includes/token_rewriter.h >> $(LIB_RUBY_PARSER_TMP_H)

	cat includes/parser_options.h >> $(LIB_RUBY_PARSER_TMP_H)
	cat includes/parser_result.h >> $(LIB_RUBY_PARSER_TMP_H)

	echo "#ifndef LIB_RUBY_PARSER_H" > $(LIB_RUBY_PARSER_H)
	echo "#define LIB_RUBY_PARSER_H" >> $(LIB_RUBY_PARSER_H)

	cat $(LIB_RUBY_PARSER_TMP_H) | \
		grep -v "#include \"" | \
		grep -v "#ifndef LIB_RUBY_PARSER_" | \
		grep -v "#define LIB_RUBY_PARSER_" | \
		grep -v "#endif // LIB_RUBY_PARSER_" \
		>> $(LIB_RUBY_PARSER_H)
	echo "#endif // LIB_RUBY_PARSER_H" >> $(LIB_RUBY_PARSER_H)

DYNAMIC_LIB = $(TARGET_DIR)/lib-ruby-parser.dynamic
STATIC_LIB = $(TARGET_DIR)/lib-ruby-parser.static

$(DYNAMIC_LIB): $(DEPS) clean-includes
	$(CXX) -fPIC -O2 -shared $(LIB_RUBY_PARSER_O) -o $(DYNAMIC_LIB)
	# test
	$(CXX) $(CXXFLAGS) $(LINK_FLAGS) test.cpp $(DYNAMIC_LIB) -o $(TARGET_DIR)/dynamic-test-runner
	$(LIST_DEPS) $(TARGET_DIR)/dynamic-test-runner
	$(TARGET_DIR)/dynamic-test-runner

$(STATIC_LIB): $(DEPS) clean-includes
	ar -rv $(STATIC_LIB) $(LIB_RUBY_PARSER_O)
	# test
	$(CXX) $(CXXFLAGS) $(LINK_FLAGS) test.cpp $(STATIC_LIB) -o $(TARGET_DIR)/static-test-runner
	$(LIST_DEPS) $(TARGET_DIR)/static-test-runner
	$(TARGET_DIR)/static-test-runner

build-dynamic: $(DYNAMIC_LIB)
build-static: $(STATIC_LIB)
