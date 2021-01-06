TARGET_DIR = target
DEBUG_RUST_OBJ = $(TARGET_DIR)/lib-ruby-parser-static-debug
RELEASE_RUST_OBJ = $(TARGET_DIR)/lib-ruby-parser-static-release
CC_DEFAULT_FLAGS = -std=c++17 -lpthread -ldl -Wall
CC_DEBUG_FLAGS = $(CC_DEFAULT_FLAGS) -g -O0
CC_RELEASE_FLAGS = $(CC_DEFAULT_FLAGS) -O2

main: build-main
	./$(TARGET_DIR)/main

test: build-test
	./$(TARGET_DIR)/test

cargo-build-debug: target-dir
	cd lib-ruby-parser-cpp-bindings && cargo build
	cp lib-ruby-parser-cpp-bindings/target/debug/liblib_ruby_parser_cpp_bindings.a $(DEBUG_RUST_OBJ)

cargo-build-release: target-dir
	cd lib-ruby-parser-cpp-bindings && cargo build --release
	cp lib-ruby-parser-cpp-bindings/target/release/liblib_ruby_parser_cpp_bindings.a $(RELEASE_RUST_OBJ)

build-main: cargo-build-debug target-dir
	$(CXX) main.cpp $(DEBUG_RUST_OBJ) $(CC_DEBUG_FLAGS) -o $(TARGET_DIR)/main

build-test: cargo-build-debug target-dir
	$(CXX) test.cpp $(DEBUG_RUST_OBJ) $(CC_DEBUG_FLAGS) -o $(TARGET_DIR)/test

build-release: cargo-build-release target-dir
	$(CXX) main.cpp ${RELEASE_RUST_OBJ} $(CC_RELEASE_FLAGS) -o $(TARGET_DIR)/main-release

test-valgrind: build-test
	valgrind --leak-check=full --error-exitcode=1 ./$(TARGET_DIR)/test

test-asan: cargo-build-debug target-dir
	$(CXX) test.cpp $(DEBUG_RUST_OBJ) -fsanitize=address $(CC_DEBUG_FLAGS) -o $(TARGET_DIR)/test
	./$(TARGET_DIR)/test

test-all: test test-valgrind test-asan

target-dir:
	mkdir -p $(TARGET_DIR)

clean:
	rm -rf $(TARGET_DIR)
	rm includes/gen.h
	rm lib-ruby-parser-cpp-bindings/src/bindings.rs
	rm lib-ruby-parser-cpp-bindings/src/cpp_from_rust_gen.rs

test-cov: target-dir
	$(CXX) test.cpp $(DEBUG_RUST_OBJ) $(CC_DEBUG_FLAGS) -fprofile-instr-generate -fcoverage-mapping -o $(TARGET_DIR)/test
	LLVM_PROFILE_FILE="$(TARGET_DIR)/test.profraw" $(TARGET_DIR)/test
	llvm-profdata merge -sparse $(TARGET_DIR)/test.profraw -o $(TARGET_DIR)/test.profdata
	llvm-cov report ./$(TARGET_DIR)/test -instr-profile=$(TARGET_DIR)/test.profdata
	# llvm-cov show ./$(TARGET_DIR)/test -instr-profile=$(TARGET_DIR)/test.profdata
