ifeq ($(DETECTED_OS), Windows)
	CXX_SET_OUT_FILE = /link /OUT:
	LIST_DEPS = dumpbin /dependents
endif

ifeq ($(DETECTED_OS), Linux)
	CXX_SET_OUT_FILE = -o #
	LIST_DEPS = ldd
	CXXEXECFLAGS = -lpthread -ldl
endif

ifeq ($(DETECTED_OS), Darwin)
	CXX_SET_OUT_FILE = -o #
	LIST_DEPS = otool -L
	CXXEXECFLAGS = -lpthread -ldl
endif

TEST_O = $(TARGET_DIR)/test.$(OBJ_FILE_EXT)
$(TEST_O): test/test.cpp $(HEADER)
	$(CXX) test/test.cpp $(CXXFLAGS) $(CXXOBJFLAGS)
	mv test.$(OBJ_FILE_EXT) $(TEST_O)

$(TARGET_DIR)/test-runner: $(STATIC_LIB) $(TEST_O)
	$(CXX) $(TEST_O) $(STATIC_LIB) $(CXXFLAGS) $(CXXEXECFLAGS) $(CXX_SET_OUT_FILE)$(TARGET_DIR)/test-runner
	$(LIST_DEPS) $(TARGET_DIR)/test-runner

test: $(TARGET_DIR)/test-runner
	$(TARGET_DIR)/test-runner

test-valgrind: $(TARGET_DIR)/test-runner
	valgrind --leak-check=full --error-exitcode=1 --num-callers=20 $(TARGET_DIR)/test-runner

test-cov:
	$(CXX) test/test.cpp $(RUST_OBJ) $(CXXFLAGS) $(CXXEXECFLAGS) -fprofile-instr-generate -fcoverage-mapping -o $(TARGET_DIR)/test
	LLVM_PROFILE_FILE="$(TARGET_DIR)/test.profraw" $(TARGET_DIR)/test
	llvm-profdata merge -sparse $(TARGET_DIR)/test.profraw -o $(TARGET_DIR)/test.profdata
	llvm-cov report $(TARGET_DIR)/test-runner -instr-profile=$(TARGET_DIR)/test.profdata
	# llvm-cov show $(TARGET_DIR)/test-runner -instr-profile=$(TARGET_DIR)/test.profdata
