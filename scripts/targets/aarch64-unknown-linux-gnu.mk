$(info Compiling aarch64-unknown-linux-gnu target)

O = o
A = a
EXE =

STATIC_LIB_FILE = libruby_parser_cpp.$(A)
LIST_DEPS = ldd

CXXFLAGS += -std=c++17 -Wall -Wextra -g -fPIC

ifeq ($(BUILD_ENV), debug)
CXXFLAGS += -O0
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

BENCHMARK_RUNNER_ASSET_NAME = rust-parser-aarch64-unknown-linux-gnu
