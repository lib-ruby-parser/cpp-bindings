tests/runner: $(STATIC_LIB)
	$(call build_cxx_exe,tests/runner.cpp $(STATIC_LIB),tests/runner)
	$(LIST_DEPS) tests/runner
tests/run: tests/runner
	./tests/runner
CLEAN += tests/runner
