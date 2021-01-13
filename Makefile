TARGET_DIR = target
BINDINGS_DIR = lib-ruby-parser-cpp-bindings
RUST_OBJ = $(TARGET_DIR)/lib-ruby-parser-rust-static

$(RUST_OBJ):
	cd $(BINDINGS_DIR) && cargo build $(CARGOFLAGS)
	cp $(BINDINGS_DIR)/target/debug/liblib_ruby_parser_cpp_bindings.a $(RUST_OBJ)

LINK_FLAGS = -lpthread -ldl
CXXFLAGS += -std=c++17 -Wall -Wextra

# files
OBJECTS =

$(TARGET_DIR)/bytes.o: includes/bytes.h includes/bytes.cpp
	$(CXX) includes/bytes.cpp $(CXXFLAGS) -c -o $(TARGET_DIR)/bytes.o
OBJECTS += $(TARGET_DIR)/bytes.o

$(TARGET_DIR)/comment.o: includes/comment.h includes/comment.cpp
	$(CXX) includes/comment.cpp $(CXXFLAGS) -c -o $(TARGET_DIR)/comment.o
OBJECTS += $(TARGET_DIR)/comment.o

$(TARGET_DIR)/custom_decoder.o: includes/custom_decoder.h includes/custom_decoder.cpp
	$(CXX) includes/custom_decoder.cpp $(CXXFLAGS) -c -o $(TARGET_DIR)/custom_decoder.o
OBJECTS += $(TARGET_DIR)/custom_decoder.o

$(TARGET_DIR)/diagnostic.o: includes/diagnostic.h includes/diagnostic.cpp
	$(CXX) includes/diagnostic.cpp $(CXXFLAGS) -c -o $(TARGET_DIR)/diagnostic.o
OBJECTS += $(TARGET_DIR)/diagnostic.o

$(TARGET_DIR)/helpers.o: includes/helpers.h includes/helpers.cpp
	$(CXX) includes/helpers.cpp $(CXXFLAGS) -c -o $(TARGET_DIR)/helpers.o
OBJECTS += $(TARGET_DIR)/helpers.o

$(TARGET_DIR)/low_level.o: includes/low_level.h includes/low_level.cpp
	$(CXX) includes/low_level.cpp $(CXXFLAGS) -c -o $(TARGET_DIR)/low_level.o
OBJECTS += $(TARGET_DIR)/low_level.o

$(TARGET_DIR)/node.o: includes/node.h includes/node.cpp
	$(CXX) includes/node.cpp $(CXXFLAGS) -c -o $(TARGET_DIR)/node.o
OBJECTS += $(TARGET_DIR)/node.o

$(TARGET_DIR)/magic_comment.o: includes/magic_comment.h includes/magic_comment.cpp
	$(CXX) includes/magic_comment.cpp $(CXXFLAGS) -c -o $(TARGET_DIR)/magic_comment.o
OBJECTS += $(TARGET_DIR)/magic_comment.o

$(TARGET_DIR)/make_node.o: includes/make_node.h includes/make_node.cpp
	$(CXX) includes/make_node.cpp $(CXXFLAGS) -c -o $(TARGET_DIR)/make_node.o
OBJECTS += $(TARGET_DIR)/make_node.o

$(TARGET_DIR)/parser_options.o: includes/parser_options.h includes/parser_options.cpp
	$(CXX) includes/parser_options.cpp $(CXXFLAGS) -c -o $(TARGET_DIR)/parser_options.o
OBJECTS += $(TARGET_DIR)/parser_options.o

$(TARGET_DIR)/parser_result.o: includes/parser_result.h includes/parser_result.cpp
	$(CXX) includes/parser_result.cpp $(CXXFLAGS) -c -o $(TARGET_DIR)/parser_result.o
OBJECTS += $(TARGET_DIR)/parser_result.o

$(TARGET_DIR)/range.o: includes/range.h includes/range.cpp
	$(CXX) includes/range.cpp $(CXXFLAGS) -c -o $(TARGET_DIR)/range.o
OBJECTS += $(TARGET_DIR)/range.o

$(TARGET_DIR)/token_rewriter.o: includes/token_rewriter.h includes/token_rewriter.cpp
	$(CXX) includes/token_rewriter.cpp $(CXXFLAGS) -c -o $(TARGET_DIR)/token_rewriter.o
OBJECTS += $(TARGET_DIR)/token_rewriter.o

$(TARGET_DIR)/token.o: includes/token.h includes/token.cpp
	$(CXX) includes/token.cpp $(CXXFLAGS) -c -o $(TARGET_DIR)/token.o
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

$(TARGET_DIR)/test-runner: $(DEPS) make-clean-includes
	$(CXX) $(LIB_RUBY_PARSER_O) test.cpp $(CXXFLAGS) -o $(TARGET_DIR)/test-runner

test: $(TARGET_DIR)/test-runner
	$(TARGET_DIR)/test-runner

test-asan: $(DEPS)
	$(CXX) $(LIB_RUBY_PARSER_O) test.cpp -fsanitize=address $(CXXFLAGS) -o $(TARGET_DIR)/test-asan-runner
	$(TARGET_DIR)/test-asan-runner

test-valgrind: $(TARGET_DIR)/test-runner
	valgrind --leak-check=full --error-exitcode=1 $(TARGET_DIR)/test-runner

test-all: test test-valgrind test-asan

clean:
	rm -f includes/node.h
	rm -f includes/node.cpp
	rm -f includes/make_node.h
	rm -f includes/make_node.cpp
	rm -f $(BINDINGS_DIR)/src/bindings.rs
	rm -f $(BINDINGS_DIR)/src/cpp_from_rust_gen.rs
	rm -f target/*.o || false
	rm -f target/*.dylib || false
	rm -f target/*.a || false
	rm -f target/test-runner
	rm -f target/dl-test-runner

test-cov:
	$(CXX) test.cpp $(RUST_OBJ) $(CXXFLAGS) -fprofile-instr-generate -fcoverage-mapping -o $(TARGET_DIR)/test
	LLVM_PROFILE_FILE="$(TARGET_DIR)/test.profraw" $(TARGET_DIR)/test
	llvm-profdata merge -sparse $(TARGET_DIR)/test.profraw -o $(TARGET_DIR)/test.profdata
	llvm-cov report $(TARGET_DIR)/test-runner -instr-profile=$(TARGET_DIR)/test.profdata
	# llvm-cov show $(TARGET_DIR)/test-runner -instr-profile=$(TARGET_DIR)/test.profdata

# // releases

make-clean-includes:
	cat includes/comment_type.h > target/lib-ruby-parser-all.h
	cat includes/error_level.h >> target/lib-ruby-parser-all.h
	cat includes/magic_comment_kind.h >> target/lib-ruby-parser-all.h

	cat includes/bytes.h >> target/lib-ruby-parser-all.h
	cat includes/range.h >> target/lib-ruby-parser-all.h
	cat includes/token.h >> target/lib-ruby-parser-all.h

	cat includes/node.h >> target/lib-ruby-parser-all.h
	cat includes/make_node.h >> target/lib-ruby-parser-all.h

	cat includes/comment.h >> target/lib-ruby-parser-all.h
	cat includes/custom_decoder.h >> target/lib-ruby-parser-all.h
	cat includes/diagnostic.h >> target/lib-ruby-parser-all.h
	cat includes/helpers.h >> target/lib-ruby-parser-all.h
	cat includes/magic_comment.h >> target/lib-ruby-parser-all.h
	cat includes/token_rewriter.h >> target/lib-ruby-parser-all.h

	cat includes/parser_options.h >> target/lib-ruby-parser-all.h
	cat includes/parser_result.h >> target/lib-ruby-parser-all.h

	echo "#ifndef LIB_RUBY_PARSER_H" > target/lib-ruby-parser.h
	echo "#define LIB_RUBY_PARSER_H" >> target/lib-ruby-parser.h

	cat target/lib-ruby-parser-all.h | \
		grep -v "#include \"" | \
		grep -v "#ifndef LIB_RUBY_PARSER_" | \
		grep -v "#define LIB_RUBY_PARSER_" | \
		grep -v "#endif // LIB_RUBY_PARSER_" \
		>> target/lib-ruby-parser.h
	echo "#endif // LIB_RUBY_PARSER_H" >> target/lib-ruby-parser.h


mac-release-dynamic: $(DEPS)
	$(CXX) -fPIC -O2 -shared target/lib-ruby-parser.o -o target/lib-ruby-parser.dylib

mac-release-static: $(DEPS)
	ar -rv lib-ruby-parser.a target/lib-ruby-parser.o

mac-test-dynamic: mac-release-dynamic
	$(CXX) $(CXXFLAGS) test.cpp $(TARGET_DIR)/lib-ruby-parser.dylib -lpthread -ldl -o $(TARGET_DIR)/dl-test-runner
	otool -L $(TARGET_DIR)/dl-test-runner
	$(TARGET_DIR)/dl-test-runner
