$(info Compiling x86_64-pc-windows-msvc target)

O = obj
A = lib

STATIC_LIB_FILE = ruby_parser_cpp.$(A)
LIST_DEPS = dumpbin /dependents

# /nologo
CXXFLAGS += /std:c++17 /bigobj /MT /Zi

ifeq ($(BUILD_ENV), debug)
CXXFLAGS += /Od /DEBUG /DTEST_ENV
else
CXXFLAGS += /O2
endif

define add_to_lib
lib.exe $(1) $(2) /OUT:$(1)
endef

define build_cxx_obj
$(CXX) $(1) $(CXXFLAGS) /c /Fo
endef

define build_cxx_exe
$(CXX) ws2_32.lib advapi32.lib userenv.lib $(1) $(CXXFLAGS) /link /OUT:$(2)
endef

BENCHMARK_RUNNER_ASSET_NAME = rust-parser-x86_64-pc-windows-msvc.exe
