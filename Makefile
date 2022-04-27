include scripts/detect_build_env.mk
include scripts/setup_target.mk
include scripts/setup_rustflags.mk

SOURCES = \
	alloc \
	api \
	bytes \
	comment \
	decoded_input \
	decoder \
	diagnostic \
	loc \
	magic_comment \
	messages \
	nodes \
	parser_options \
	parser_result \
	shared_byte_list \
	source_line \
	string \
	token \
	token_rewriter

ifeq ($(BUILD_ENV), debug)
SOURCES += test_helper
endif

CPP_FILES = $(foreach source,$(SOURCES),$(source).cpp)
HPP_FILES = $(foreach source,$(SOURCES),$(source).hpp)
O_FILES = $(foreach source,$(SOURCES),$(source).$(O))
STATIC_LIB = libruby_parser_cpp.$(A)

# Codegen
include codegen/build.mk

# *.o
%.$(O): %.cpp %.hpp
	$(call build_cxx_obj,$<,$@)
objects: $(O_FILES)

# Rust
include ruby-parser-cpp/build.mk

$(STATIC_LIB): ruby-parser-cpp/lib_ruby_parser_cpp.$(A) $(O_FILES)
	cp ruby-parser-cpp/lib_ruby_parser_cpp.$(A) ./$(STATIC_LIB)
	$(call add_to_lib,$(STATIC_LIB),$(O_FILES))

# tests
include tests/build.mk

# benchmark
include benchmark/build.mk

# deps
update-depend: $(CPP_FILES) $(HPP_FILES)
	CC=$(CC) ./scripts/update-depend.sh
include .depend

# clean
clean:
	rm -rf $(CLEAN)
	rm -f *.$(O)
	rm -f *.$(A)
	rm -rf *.dSYM

check:
	CC=$(CC) ruby assert_defs.rb bindings.hpp bindings.cpp bindings_messages.cpp bindings_nodes.cpp
