define download_file
URL="$(1)" SAVE_AS="$(2)" ruby scripts/download_file.rb
endef

CODEGEN_EXE = codegen/codegen$(EXE)
$(CODEGEN_EXE):
	$(call download_file, https://github.com/lib-ruby-parser/lib-ruby-parser/releases/download/v4.0.2+ruby-3.1.1/codegen-$(TARGET)$(EXE), $@)
	chmod +x $(CODEGEN_EXE)
CLEAN += $(CODEGEN_EXE)

# Codegen deps
tests/messages_test.cpp: codegen/messages_test.cpp.liquid $(CODEGEN_EXE)
	$(CODEGEN_EXE) --template $< --write-to $@
CLEAN += tests/messages_test.cpp
CODEGEN_FILES += tests/messages_test.cpp

messages.hpp: codegen/messages.hpp.liquid $(CODEGEN_EXE)
	$(CODEGEN_EXE) --template $< --write-to $@
CLEAN += messages.hpp
CODEGEN_FILES += messages.hpp

messages.cpp: codegen/messages.cpp.liquid $(CODEGEN_EXE)
	$(CODEGEN_EXE) --template $< --write-to $@
CLEAN += messages.cpp
CODEGEN_FILES += messages.cpp

tests/nodes_test.cpp: codegen/nodes_test.cpp.liquid $(CODEGEN_EXE)
	$(CODEGEN_EXE) --template $< --write-to $@
CLEAN += tests/nodes_test.cpp
CODEGEN_FILES += tests/nodes_test.cpp

nodes.hpp: codegen/nodes.hpp.liquid $(CODEGEN_EXE)
	$(CODEGEN_EXE) --template $< --write-to $@
CLEAN += nodes.hpp
CODEGEN_FILES += nodes.hpp

nodes.cpp: codegen/nodes.cpp.liquid $(CODEGEN_EXE)
	$(CODEGEN_EXE) --template $< --write-to $@
CLEAN += nodes.cpp
CODEGEN_FILES += nodes.cpp

ruby-parser-cpp/src/node.rs: codegen/nodes.rs.liquid $(CODEGEN_EXE)
	$(CODEGEN_EXE) --template $< --write-to $@
CLEAN += ruby-parser-cpp/src/node.rs
CODEGEN_FILES += ruby-parser-cpp/src/node.rs

ruby-parser-cpp/src/message.rs: codegen/messages.rs.liquid $(CODEGEN_EXE)
	$(CODEGEN_EXE) --template $< --write-to $@
CLEAN += ruby-parser-cpp/src/message.rs
CODEGEN_FILES += ruby-parser-cpp/src/message.rs

token_ids.hpp: codegen/token_ids.hpp.liquid $(CODEGEN_EXE)
	$(CODEGEN_EXE) --template $< --write-to $@
CLEAN += token_ids.hpp
CODEGEN_FILES += token_ids.hpp

codegen/merge-headers:
	wget -q https://github.com/iliabylich/merge_headers/releases/download/v1.0.0/merge-headers-$(TARGET) -O codegen/merge-headers
	chmod +x codegen/merge-headers
CLEAN += codegen/merge-headers

empty :=
space := $(empty) $(empty)

# Joins elements of the list in arg 2 with the given separator.
#   1. Element separator.
#   2. The list.
join-with = $(subst $(space),$1,$(strip $2))

# lib-ruby-parser.hpp codegen
lib-ruby-parser.hpp: codegen/merge-headers $(HPP_FILES)
	./codegen/merge-headers \
		--cc $(CXX) \
		--headers "$(call join-with,;,$(HPP_FILES))" \
		--write-to lib-ruby-parser.hpp \
		--include-guard-prefix LIB_RUBY_PARSER_ \
		--output-guard LIB_RUBY_PARSER_H

CLEAN += lib-ruby-parser.hpp
update-depend: lib-ruby-parser.hpp

do-codegen: $(CODEGEN_FILES)

.PHONY: do-codegen
