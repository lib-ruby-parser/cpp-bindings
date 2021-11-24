$(info Compiling x86_64-unknown-linux-gnu target)

O = o
A = a

STATIC_LIB_FILE = libruby_parser_cpp.$(A)
LIST_DEPS = ldd

CXXFLAGS += -std=c++17 -Wall -Wextra -g -target $(TARGET)

ifeq ($(BUILD_ENV), debug)
CXXFLAGS += -O0 -DTEST_ENV
else
CXXFLAGS += -O3
endif

define add_to_lib
$(AR) r $(1) $(2)
endef

define build_cxx_obj
$(CXX) $(1) $(CXXFLAGS) -c -o $(2)
endef

define build_cxx_exe
$(CXX) $(1) $(CXXFLAGS) -lpthread -ldl -lm -o $(2)
endef

BENCHMARK_RUNNER_ASSET_NAME = rust-parser-x86_64-unknown-linux-gnu
