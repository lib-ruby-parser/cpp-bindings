TARGET_DIR = target
BINDINGS_DIR = lib-ruby-parser-cpp-bindings
DEBUG_RUST_OBJ = $(TARGET_DIR)/lib-ruby-parser-static-debug
RELEASE_RUST_OBJ = $(TARGET_DIR)/lib-ruby-parser-static-release

build-debug-rust-obj:
	cd $(BINDINGS_DIR) && cargo build

$(DEBUG_RUST_OBJ): build-debug-rust-obj
	cp $(BINDINGS_DIR)/target/debug/liblib_ruby_parser_cpp_bindings.a $(DEBUG_RUST_OBJ)

$(RELEASE_RUST_OBJ):
	cd $(BINDINGS_DIR) && cargo build --release
	cp $(BINDINGS_DIR)/target/release/liblib_ruby_parser_cpp_bindings.a $(RELEASE_RUST_OBJ)

LINK_FLAGS = -lpthread -ldl
CC_DEFAULT_FLAGS = -std=c++17 -Wall -Wextra
CC_DEBUG_FLAGS = $(CC_DEFAULT_FLAGS) $(LINK_FLAGS) -g -O0
CC_RELEASE_FLAGS = $(CC_DEFAULT_FLAGS) $(LINK_FLAGS) -O2

# files
OBJECTS =

$(TARGET_DIR)/bytes.o: includes/bytes.h includes/bytes.cpp
	$(CXX) includes/bytes.cpp $(CC_DEFAULT_FLAGS) -c -o $(TARGET_DIR)/bytes.o
OBJECTS += $(TARGET_DIR)/bytes.o

$(TARGET_DIR)/comment.o: includes/comment.h includes/comment.cpp
	$(CXX) includes/comment.cpp $(CC_DEFAULT_FLAGS) -c -o $(TARGET_DIR)/comment.o
OBJECTS += $(TARGET_DIR)/comment.o

$(TARGET_DIR)/custom_decoder.o: includes/custom_decoder.h includes/custom_decoder.cpp
	$(CXX) includes/custom_decoder.cpp $(CC_DEFAULT_FLAGS) -c -o $(TARGET_DIR)/custom_decoder.o
OBJECTS += $(TARGET_DIR)/custom_decoder.o

$(TARGET_DIR)/diagnostic.o: includes/diagnostic.h includes/diagnostic.cpp
	$(CXX) includes/diagnostic.cpp $(CC_DEFAULT_FLAGS) -c -o $(TARGET_DIR)/diagnostic.o
OBJECTS += $(TARGET_DIR)/diagnostic.o

$(TARGET_DIR)/helpers.o: includes/helpers.h includes/helpers.cpp
	$(CXX) includes/helpers.cpp $(CC_DEFAULT_FLAGS) -c -o $(TARGET_DIR)/helpers.o
OBJECTS += $(TARGET_DIR)/helpers.o

$(TARGET_DIR)/low_level.o: includes/low_level.h includes/low_level.cpp
	$(CXX) includes/low_level.cpp $(CC_DEFAULT_FLAGS) -c -o $(TARGET_DIR)/low_level.o
OBJECTS += $(TARGET_DIR)/low_level.o

$(TARGET_DIR)/node.o: includes/node.h includes/node.cpp
	$(CXX) includes/node.cpp $(CC_DEFAULT_FLAGS) -c -o $(TARGET_DIR)/node.o
OBJECTS += $(TARGET_DIR)/node.o

$(TARGET_DIR)/magic_comment.o: includes/magic_comment.h includes/magic_comment.cpp
	$(CXX) includes/magic_comment.cpp $(CC_DEFAULT_FLAGS) -c -o $(TARGET_DIR)/magic_comment.o
OBJECTS += $(TARGET_DIR)/magic_comment.o

$(TARGET_DIR)/make_node.o: includes/make_node.h includes/make_node.cpp
	$(CXX) includes/make_node.cpp $(CC_DEFAULT_FLAGS) -c -o $(TARGET_DIR)/make_node.o
OBJECTS += $(TARGET_DIR)/make_node.o

$(TARGET_DIR)/parser_options.o: includes/parser_options.h includes/parser_options.cpp
	$(CXX) includes/parser_options.cpp $(CC_DEFAULT_FLAGS) -c -o $(TARGET_DIR)/parser_options.o
OBJECTS += $(TARGET_DIR)/parser_options.o

$(TARGET_DIR)/parser_result.o: includes/parser_result.h includes/parser_result.cpp
	$(CXX) includes/parser_result.cpp $(CC_DEFAULT_FLAGS) -c -o $(TARGET_DIR)/parser_result.o
OBJECTS += $(TARGET_DIR)/parser_result.o

$(TARGET_DIR)/range.o: includes/range.h includes/range.cpp
	$(CXX) includes/range.cpp $(CC_DEFAULT_FLAGS) -c -o $(TARGET_DIR)/range.o
OBJECTS += $(TARGET_DIR)/range.o

$(TARGET_DIR)/token_rewriter.o: includes/token_rewriter.h includes/token_rewriter.cpp
	$(CXX) includes/token_rewriter.cpp $(CC_DEFAULT_FLAGS) -c -o $(TARGET_DIR)/token_rewriter.o
OBJECTS += $(TARGET_DIR)/token_rewriter.o

$(TARGET_DIR)/token.o: includes/token.h includes/token.cpp
	$(CXX) includes/token.cpp $(CC_DEFAULT_FLAGS) -c -o $(TARGET_DIR)/token.o
OBJECTS += $(TARGET_DIR)/token.o

HEADERS = includes/lib-ruby-parser.h \
	includes/comment_type.h \
	includes/error_level.h \
	includes/magic_comment_kind.h

LIB_RUBY_PARSER_O = $(TARGET_DIR)/lib-ruby-parser.o
$(LIB_RUBY_PARSER_O): $(DEBUG_RUST_OBJ) $(OBJECTS)
	$(LD) -r $(DEBUG_RUST_OBJ) $(OBJECTS) -o $(LIB_RUBY_PARSER_O)

# // files

DEPS = $(LIB_RUBY_PARSER_O) $(HEADERS)

$(TARGET_DIR)/test-runner: $(DEPS)
	$(CXX) $(LIB_RUBY_PARSER_O) test.cpp $(CC_DEBUG_FLAGS) -o $(TARGET_DIR)/test-runner

test: $(TARGET_DIR)/test-runner
	$(TARGET_DIR)/test-runner

test-asan: $(DEPS)
	$(CXX) $(LIB_RUBY_PARSER_O) test.cpp -fsanitize=address $(CC_DEBUG_FLAGS) -o $(TARGET_DIR)/test-asan-runner
	$(TARGET_DIR)/test-asan-runner

test-valgrind: $(TARGET_DIR)/test-runner
	valgrind --leak-check=full --error-exitcode=1 $(TARGET_DIR)/test-runner

test-all: test test-valgrind test-asan

clean:
	rm includes/node.h
	rm includes/node.cpp
	rm includes/make_node.h
	rm includes/make_node.cpp
	rm $(BINDINGS_DIR)/src/bindings.rs
	rm $(BINDINGS_DIR)/src/cpp_from_rust_gen.rs

test-cov:
	$(CXX) test.cpp $(DEBUG_RUST_OBJ) $(CC_DEBUG_FLAGS) -fprofile-instr-generate -fcoverage-mapping -o $(TARGET_DIR)/test
	LLVM_PROFILE_FILE="$(TARGET_DIR)/test.profraw" $(TARGET_DIR)/test
	llvm-profdata merge -sparse $(TARGET_DIR)/test.profraw -o $(TARGET_DIR)/test.profdata
	llvm-cov report $(TARGET_DIR)/test-runner -instr-profile=$(TARGET_DIR)/test.profdata
	# llvm-cov show $(TARGET_DIR)/test-runner -instr-profile=$(TARGET_DIR)/test.profdata
