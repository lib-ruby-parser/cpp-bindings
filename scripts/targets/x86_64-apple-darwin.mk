$(info Compiling x86_64-apple-darwin target)

O = o
A = a
EXE =

STATIC_LIB_FILE = libruby_parser_cpp.$(A)
LIST_DEPS = otool -L

CXXFLAGS += -std=c++17 -Wall -Wextra -Wpedantic -Weverything -g
# but disable -Wpadded, we inherit Rust layouts
CXXFLAGS += -Wno-padded
# ignore documentation, it has examples of syntax errors on purpose
CXXFLAGS += -Wno-documentation-unknown-command
# ignore C++98 compatibility
CXXFLAGS += -Wno-c++98-compat -Wno-c++98-compat-pedantic
# ignore __ in function/macro names
CXXFLAGS += -Wno-reserved-macro-identifier -Wno-reserved-identifier

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
$(CXX) $(1) $(CXXFLAGS) -o $(2)
endef

BENCHMARK_RUNNER_ASSET_NAME = rust-parser-x86_64-apple-darwin
