BINDINGS_DIR = lib-ruby-parser-cpp-bindings


ifndef BUILD_ENV
	BUILD_ENV = debug
endif

ifeq ($(BUILD_ENV), debug)
	RUST_ENV = debug
	CARGOFLAGS +=
else
	RUST_ENV = release
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
	# CXXFLAGS += /Wall
	CXXFLAGS += /std:c++17
	CXXOBJFLAGS += /c /Fo
	# LINK_FLAGS = advapi32.lib ws2_32.lib userenv.lib msvcrt.lib
	ifeq ($(BUILD_ENV), debug)
		CXXFLAGS += /Od
	else
		CXXFLAGS += /O2
	endif
	OBJ_FILE_EXT = .obj
else
	CXXFLAGS += -Wall -Wextra -std=c++17
	CXXOBJFLAGS += -fPIC -c
	LINK_FLAGS = -lpthread -ldl
	ifeq ($(BUILD_ENV), debug)
		CXXFLAGS += -g -O0
	else
		CXXFLAGS += -O2
	endif
	OBJ_FILE_EXT = .o
endif

print-env:
	@echo "BUILD_ENV = $(BUILD_ENV)"
	@echo "CXXFLAGS = $(CXXFLAGS)"
	@echo "RUST_ENV = $(RUST_ENV)"
	@echo "CARGOFLAGS = $(CARGOFLAGS)"
	@echo "DETECTED_OS = $(DETECTED_OS)"
	@echo "LIST_DEPS = $(LIST_DEPS)"

RUST_OBJ = lib-ruby-parser-rust-static$(OBJ_FILE_EXT)
$(RUST_OBJ):
	cd $(BINDINGS_DIR) && cargo build $(CARGOFLAGS)
	ls -l $(BINDINGS_DIR)/$(RUST_TARGET_DIR)/$(RUST_ENV)/
	cp $(BINDINGS_DIR)/$(RUST_TARGET_DIR)/$(RUST_ENV)/$(RUST_OBJ_FILE) $(RUST_OBJ)

gen-headers: $(RUST_OBJ)

# objects
OBJECTS =

byte_ptr$(OBJ_FILE_EXT): byte_ptr.h byte_ptr.cpp
	$(CXX) byte_ptr.cpp $(CXXFLAGS) $(CXXOBJFLAGS)
OBJECTS += byte_ptr$(OBJ_FILE_EXT)

bytes$(OBJ_FILE_EXT): bytes.h bytes.cpp
	$(CXX) bytes.cpp $(CXXFLAGS) $(CXXOBJFLAGS)
OBJECTS += bytes$(OBJ_FILE_EXT)

comment$(OBJ_FILE_EXT): comment.h comment.cpp
	$(CXX) comment.cpp $(CXXFLAGS) $(CXXOBJFLAGS)
OBJECTS += comment$(OBJ_FILE_EXT)

custom_decoder$(OBJ_FILE_EXT): custom_decoder.h custom_decoder.cpp
	$(CXX) custom_decoder.cpp $(CXXFLAGS) $(CXXOBJFLAGS)
OBJECTS += custom_decoder$(OBJ_FILE_EXT)

diagnostic$(OBJ_FILE_EXT): diagnostic.h diagnostic.cpp
	$(CXX) diagnostic.cpp $(CXXFLAGS) $(CXXOBJFLAGS)
OBJECTS += diagnostic$(OBJ_FILE_EXT)

helpers$(OBJ_FILE_EXT): helpers.h helpers.cpp
	$(CXX) helpers.cpp $(CXXFLAGS) $(CXXOBJFLAGS)
OBJECTS += helpers$(OBJ_FILE_EXT)

low_level$(OBJ_FILE_EXT): low_level.h low_level.cpp
	$(CXX) low_level.cpp $(CXXFLAGS) $(CXXOBJFLAGS)
OBJECTS += low_level$(OBJ_FILE_EXT)

node$(OBJ_FILE_EXT): node.h node.cpp
	$(CXX) node.cpp $(CXXFLAGS) $(CXXOBJFLAGS)
OBJECTS += node$(OBJ_FILE_EXT)

magic_comment$(OBJ_FILE_EXT): magic_comment.h magic_comment.cpp
	$(CXX) magic_comment.cpp $(CXXFLAGS) $(CXXOBJFLAGS)
OBJECTS += magic_comment$(OBJ_FILE_EXT)

make_node$(OBJ_FILE_EXT): make_node.h make_node.cpp
	$(CXX) make_node.cpp $(CXXFLAGS) $(CXXOBJFLAGS)
OBJECTS += make_node$(OBJ_FILE_EXT)

parser_options$(OBJ_FILE_EXT): parser_options.h parser_options.cpp
	$(CXX) parser_options.cpp $(CXXFLAGS) $(CXXOBJFLAGS)
OBJECTS += parser_options$(OBJ_FILE_EXT)

parser_result$(OBJ_FILE_EXT): parser_result.h parser_result.cpp
	$(CXX) parser_result.cpp $(CXXFLAGS) $(CXXOBJFLAGS)
OBJECTS += parser_result$(OBJ_FILE_EXT)

range$(OBJ_FILE_EXT): range.h range.cpp
	$(CXX) range.cpp $(CXXFLAGS) $(CXXOBJFLAGS)
OBJECTS += range$(OBJ_FILE_EXT)

token_rewriter$(OBJ_FILE_EXT): token_rewriter.h token_rewriter.cpp
	$(CXX) token_rewriter.cpp $(CXXFLAGS) $(CXXOBJFLAGS)
OBJECTS += token_rewriter$(OBJ_FILE_EXT)

token$(OBJ_FILE_EXT): token.h token.cpp
	$(CXX) token.cpp $(CXXFLAGS) $(CXXOBJFLAGS)
OBJECTS += token$(OBJ_FILE_EXT)

HEADERS = lib-ruby-parser.h comment_type.h error_level.h magic_comment_kind.h

LIB_RUBY_PARSER_O = lib-ruby-parser$(OBJ_FILE_EXT)
ifeq ($(DETECTED_OS), Windows)
	MOVE_LIB_RUBY_PARSER_O = ls -l
	LDFLAGS += advapi32.lib ws2_32.lib userenv.lib msvcrt.lib /OUT:$(LIB_RUBY_PARSER_O)
else
	MOVE_LIB_RUBY_PARSER_O =
	LDFLAGS += -r -o $(LIB_RUBY_PARSER_O)
endif

# $(LIB_RUBY_PARSER_O): $(RUST_OBJ) $(OBJECTS)
# 	$(LD) $(LDFLAGS) $(RUST_OBJ) $(OBJECTS)
# 	bash -c "$(MOVE_LIB_RUBY_PARSER_O)"

TEST_O = test$(OBJ_FILE_EXT)
$(TEST_O): test.cpp
	$(CXX) test.cpp $(CXXFLAGS) $(CXXOBJFLAGS)

# // files

DEPS = $(LIB_RUBY_PARSER_O) $(HEADERS)

ifeq ($(DETECTED_OS), Windows)
	STATIC_LIB_EXT = .lib
else
	STATIC_LIB_EXT = .a
endif

LIB_RUBY_PARSER_STATIC = lib-ruby-parser$(STATIC_LIB_EXT)
$(LIB_RUBY_PARSER_STATIC): $(RUST_OBJ) $(OBJECTS)
	$(LD) $(LDFLAGS) $(RUST_OBJ) $(OBJECTS)

test-runner: $(LIB_RUBY_PARSER_STATIC) $(TEST_O)
	# $(CXX) /NODEFAULTLIB:libcmt.lib $(LIB_RUBY_PARSER_O) test.cpp $(CXXFLAGS) $(LINK_FLAGS)
	# ls -l
	link.exe /OUT:test-runner $(LIB_RUBY_PARSER_STATIC) $(TEST_O)

test: test-runner
	./test-runner

test-asan: $(DEPS) $(LIB_RUBY_PARSER_H)
	$(CXX) $(LIB_RUBY_PARSER_O) test.cpp -fsanitize=address $(CXXFLAGS) $(LINK_FLAGS) -o test-asan-runner
	./test-asan-runner

test-valgrind: test-runner
	valgrind --leak-check=full --error-exitcode=1 --num-callers=20 test-runner

test-all: test test-valgrind test-asan

clean:
	rm -f *.o
	rm -f test-runner
	rm -f test-asan-runner
	rm -f $(LIB_RUBY_PARSER_H)

test-cov:
	$(CXX) test.cpp $(RUST_OBJ) $(CXXFLAGS) $(LINK_FLAGS) -fprofile-instr-generate -fcoverage-mapping -o test
	LLVM_PROFILE_FILE="test.profraw" test
	llvm-profdata merge -sparse test.profraw -o test.profdata
	llvm-cov report test-runner -instr-profile=test.profdata
	# llvm-cov show test-runner -instr-profile=test.profdata

# // releases

LIB_RUBY_PARSER_TMP_H = lib-ruby-parser-tmp.h
LIB_RUBY_PARSER_H = lib-ruby-parser.h
$(LIB_RUBY_PARSER_H):
	cat byte_ptr.h > $(LIB_RUBY_PARSER_TMP_H)
	cat comment_type.h >> $(LIB_RUBY_PARSER_TMP_H)
	cat error_level.h >> $(LIB_RUBY_PARSER_TMP_H)
	cat magic_comment_kind.h >> $(LIB_RUBY_PARSER_TMP_H)

	cat bytes.h >> $(LIB_RUBY_PARSER_TMP_H)
	cat range.h >> $(LIB_RUBY_PARSER_TMP_H)
	cat token.h >> $(LIB_RUBY_PARSER_TMP_H)

	cat node.h >> $(LIB_RUBY_PARSER_TMP_H)
	cat make_node.h >> $(LIB_RUBY_PARSER_TMP_H)

	cat comment.h >> $(LIB_RUBY_PARSER_TMP_H)
	cat custom_decoder.h >> $(LIB_RUBY_PARSER_TMP_H)
	cat diagnostic.h >> $(LIB_RUBY_PARSER_TMP_H)
	cat helpers.h >> $(LIB_RUBY_PARSER_TMP_H)
	cat magic_comment.h >> $(LIB_RUBY_PARSER_TMP_H)
	cat token_rewriter.h >> $(LIB_RUBY_PARSER_TMP_H)

	cat parser_options.h >> $(LIB_RUBY_PARSER_TMP_H)
	cat parser_result.h >> $(LIB_RUBY_PARSER_TMP_H)

	echo "#ifndef LIB_RUBY_PARSER_H" > $(LIB_RUBY_PARSER_H)
	echo "#define LIB_RUBY_PARSER_H" >> $(LIB_RUBY_PARSER_H)

	cat $(LIB_RUBY_PARSER_TMP_H) | \
		grep -v "#include \"" | \
		grep -v "#ifndef LIB_RUBY_PARSER_" | \
		grep -v "#define LIB_RUBY_PARSER_" | \
		grep -v "#endif // LIB_RUBY_PARSER_" \
		>> $(LIB_RUBY_PARSER_H)
	echo "#endif // LIB_RUBY_PARSER_H" >> $(LIB_RUBY_PARSER_H)
	rm $(LIB_RUBY_PARSER_TMP_H)

DYNAMIC_LIB = lib-ruby-parser.dynamic
STATIC_LIB = lib-ruby-parser.static

$(DYNAMIC_LIB): $(DEPS) $(LIB_RUBY_PARSER_H)
	$(CXX) -fPIC -O2 -shared $(LIB_RUBY_PARSER_O) -o $(DYNAMIC_LIB)
	# test
	$(CXX) $(CXXFLAGS) $(LINK_FLAGS) test.cpp $(DYNAMIC_LIB) -o dynamic-test-runner
	$(LIST_DEPS) dynamic-test-runner
	./dynamic-test-runner

$(STATIC_LIB): $(DEPS) $(LIB_RUBY_PARSER_H)
	ar -rv $(STATIC_LIB) $(LIB_RUBY_PARSER_O)
	# test
	$(CXX) $(CXXFLAGS) $(LINK_FLAGS) test.cpp $(STATIC_LIB) -o static-test-runner
	$(LIST_DEPS) static-test-runner
	./static-test-runner

build-dynamic: $(DYNAMIC_LIB)
build-static: $(STATIC_LIB)
