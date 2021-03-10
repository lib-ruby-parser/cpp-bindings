include scripts/setup.mk

# Rust
include lib-ruby-parser-cpp-bindings/build.mk

# headers
include header/build.mk

# C
include src/build.mk

STATIC_LIB = $(TARGET_DIR)/lib-ruby-parser.$(STATIC_LIB_EXT)

ifeq ($(DETECTED_OS), Windows)
	BUILD_STATIC = lib.exe ws2_32.lib advapi32.lib userenv.lib $(RUST_OBJ) $(OBJECTS) /OUT:$(STATIC_LIB)
else
	LIB_RUBY_PARSER_O = $(TARGET_DIR)/lib-ruby-parser.$(OBJ_FILE_EXT)
	BUILD_STATIC = $(LD) -r $(RUST_OBJ) $(OBJECTS) -o $(LIB_RUBY_PARSER_O) && \
		ar -rv $(STATIC_LIB) $(LIB_RUBY_PARSER_O)
endif

$(STATIC_LIB): $(RUST_OBJ) $(OBJECTS)
	$(BUILD_STATIC)
build-static: $(STATIC_LIB)

# tests
include test/build.mk

clean:
	rm -rf target
	mkdir -p $(TARGET_DIR)
	mkdir -p $(TARGET_DIR)/gen/nodes
	mkdir -p $(TARGET_DIR)/gen/messages
