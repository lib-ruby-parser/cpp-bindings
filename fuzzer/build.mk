target/fuzzer: $(STATIC_LIB) $(HEADER) fuzzer/parse.cpp
	$(CXX) fuzzer/parse.cpp -fsanitize=fuzzer,address $(STATIC_LIB) $(CXXFLAGS) $(CXXEXECFLAGS) $(CXX_SET_OUT_FILE)target/fuzzer

fuzz: target/fuzzer
	./target/fuzzer -max_len=50 -timeout=10
