BINDINGS_DIR = lib-ruby-parser-cpp-bindings

LINK_FLAGS = -lpthread -ldl
CXXFLAGS += -std=c++17 -Wall -Wextra

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

print-env:
	echo "BUILD_ENV = $(BUILD_ENV)"
	echo "CXXFLAGS = $(CXXFLAGS)"
	echo "RUST_ENV = $(RUST_ENV)"

setup:
	mkdir -p target/debug
	mkdir -p target/release

RUST_OBJ = $(TARGET_DIR)/lib-ruby-parser-rust-static
$(RUST_OBJ):
	cd $(BINDINGS_DIR) && cargo build $(CARGOFLAGS)
	ls -l $(BINDINGS_DIR)/target/$(RUST_ENV)/
	cp $(BINDINGS_DIR)/target/$(RUST_ENV)/liblib_ruby_parser_cpp_bindings.a $(RUST_OBJ)

gen-headers: $(RUST_OBJ)

# objects
OBJECTS =

$(TARGET_DIR)/byte_ptr.o: src/byte_ptr.h src/byte_ptr.cpp
	$(CXX) src/byte_ptr.cpp $(CXXFLAGS) -fPIC -c -o $(TARGET_DIR)/byte_ptr.o
OBJECTS += $(TARGET_DIR)/byte_ptr.o

$(TARGET_DIR)/bytes.o: src/bytes.h src/bytes.cpp
	$(CXX) src/bytes.cpp $(CXXFLAGS) -fPIC -c -o $(TARGET_DIR)/bytes.o
OBJECTS += $(TARGET_DIR)/bytes.o

$(TARGET_DIR)/comment.o: src/comment.h src/comment.cpp
	$(CXX) src/comment.cpp $(CXXFLAGS) -fPIC -c -o $(TARGET_DIR)/comment.o
OBJECTS += $(TARGET_DIR)/comment.o

$(TARGET_DIR)/custom_decoder.o: src/custom_decoder.h src/custom_decoder.cpp
	$(CXX) src/custom_decoder.cpp $(CXXFLAGS) -fPIC -c -o $(TARGET_DIR)/custom_decoder.o
OBJECTS += $(TARGET_DIR)/custom_decoder.o

$(TARGET_DIR)/diagnostic.o: src/diagnostic.h src/diagnostic.cpp
	$(CXX) src/diagnostic.cpp $(CXXFLAGS) -fPIC -c -o $(TARGET_DIR)/diagnostic.o
OBJECTS += $(TARGET_DIR)/diagnostic.o

$(TARGET_DIR)/helpers.o: src/helpers.h src/helpers.cpp
	$(CXX) src/helpers.cpp $(CXXFLAGS) -fPIC -c -o $(TARGET_DIR)/helpers.o
OBJECTS += $(TARGET_DIR)/helpers.o

$(TARGET_DIR)/low_level.o: src/low_level.h src/low_level.cpp
	$(CXX) src/low_level.cpp $(CXXFLAGS) -fPIC -c -o $(TARGET_DIR)/low_level.o
OBJECTS += $(TARGET_DIR)/low_level.o

$(TARGET_DIR)/node.o: src/node.h src/node.cpp
	$(CXX) src/node.cpp $(CXXFLAGS) -fPIC -c -o $(TARGET_DIR)/node.o
OBJECTS += $(TARGET_DIR)/node.o

$(TARGET_DIR)/magic_comment.o: src/magic_comment.h src/magic_comment.cpp
	$(CXX) src/magic_comment.cpp $(CXXFLAGS) -fPIC -c -o $(TARGET_DIR)/magic_comment.o
OBJECTS += $(TARGET_DIR)/magic_comment.o

$(TARGET_DIR)/make_node.o: src/make_node.h src/make_node.cpp
	$(CXX) src/make_node.cpp $(CXXFLAGS) -fPIC -c -o $(TARGET_DIR)/make_node.o
OBJECTS += $(TARGET_DIR)/make_node.o

$(TARGET_DIR)/parser_options.o: src/parser_options.h src/parser_options.cpp
	$(CXX) src/parser_options.cpp $(CXXFLAGS) -fPIC -c -o $(TARGET_DIR)/parser_options.o
OBJECTS += $(TARGET_DIR)/parser_options.o

$(TARGET_DIR)/parser_result.o: src/parser_result.h src/parser_result.cpp
	$(CXX) src/parser_result.cpp $(CXXFLAGS) -fPIC -c -o $(TARGET_DIR)/parser_result.o
OBJECTS += $(TARGET_DIR)/parser_result.o

$(TARGET_DIR)/range.o: src/range.h src/range.cpp
	$(CXX) src/range.cpp $(CXXFLAGS) -fPIC -c -o $(TARGET_DIR)/range.o
OBJECTS += $(TARGET_DIR)/range.o

$(TARGET_DIR)/token_rewriter.o: src/token_rewriter.h src/token_rewriter.cpp
	$(CXX) src/token_rewriter.cpp $(CXXFLAGS) -fPIC -c -o $(TARGET_DIR)/token_rewriter.o
OBJECTS += $(TARGET_DIR)/token_rewriter.o

$(TARGET_DIR)/token.o: src/token.h src/token.cpp
	$(CXX) src/token.cpp $(CXXFLAGS) -fPIC -c -o $(TARGET_DIR)/token.o
OBJECTS += $(TARGET_DIR)/token.o

HEADERS = src/lib-ruby-parser.h \
	src/comment_type.h \
	src/error_level.h \
	src/magic_comment_kind.h

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
	cat src/byte_ptr.h > $(LIB_RUBY_PARSER_TMP_H)
	cat src/comment_type.h >> $(LIB_RUBY_PARSER_TMP_H)
	cat src/error_level.h >> $(LIB_RUBY_PARSER_TMP_H)
	cat src/magic_comment_kind.h >> $(LIB_RUBY_PARSER_TMP_H)

	cat src/bytes.h >> $(LIB_RUBY_PARSER_TMP_H)
	cat src/range.h >> $(LIB_RUBY_PARSER_TMP_H)
	cat src/token.h >> $(LIB_RUBY_PARSER_TMP_H)

	cat src/node.h >> $(LIB_RUBY_PARSER_TMP_H)
	cat src/make_node.h >> $(LIB_RUBY_PARSER_TMP_H)

	cat src/comment.h >> $(LIB_RUBY_PARSER_TMP_H)
	cat src/custom_decoder.h >> $(LIB_RUBY_PARSER_TMP_H)
	cat src/diagnostic.h >> $(LIB_RUBY_PARSER_TMP_H)
	cat src/helpers.h >> $(LIB_RUBY_PARSER_TMP_H)
	cat src/magic_comment.h >> $(LIB_RUBY_PARSER_TMP_H)
	cat src/token_rewriter.h >> $(LIB_RUBY_PARSER_TMP_H)

	cat src/parser_options.h >> $(LIB_RUBY_PARSER_TMP_H)
	cat src/parser_result.h >> $(LIB_RUBY_PARSER_TMP_H)

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

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	LIST_DEPS = ldd
endif
ifeq ($(UNAME_S),Darwin)
	LIST_DEPS = otool -L
endif

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
