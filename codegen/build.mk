TAG_TO_SYNC = v3.0.11
BASE_FN_SYNC_URL = https://raw.githubusercontent.com/lib-ruby-parser/lib-ruby-parser/$(TAG_TO_SYNC)

codegen/sync-fns:
	wget -q $(BASE_FN_SYNC_URL)/codegen/fns/shared.rs -O codegen/codegen/fns_shared.rs
	wget -q $(BASE_FN_SYNC_URL)/codegen/fns/c.rs -O codegen/codegen/fns_c.rs

CODEGEN_DEPS = $(wildcard codegen/codegen/*.rs)
CODEGEN_DEPS += codegen/Cargo.toml
CODEGEN_DEPS += codegen/build.rs

DO_CODEGEN = cd codegen && cargo build

# Codegen deps
messages.cpp: $(CODEGEN_DEPS)
	$(DO_CODEGEN)
CLEAN += messages.cpp

messages.hpp: $(CODEGEN_DEPS)
	$(DO_CODEGEN)
CLEAN += messages.hpp

nodes.cpp: $(CODEGEN_DEPS)
	$(DO_CODEGEN)
CLEAN += nodes.cpp

nodes.hpp: $(CODEGEN_DEPS)
	$(DO_CODEGEN)
CLEAN += nodes.hpp

ruby-parser-c/src/node.rs: $(CODEGEN_DEPS)
	$(DO_CODEGEN)
CLEAN += ruby-parser-c/src/node.rs

ruby-parser-c/src/message.rs: $(CODEGEN_DEPS)
	$(DO_CODEGEN)
CLEAN += ruby-parser-c/src/message.rs

# token_id.hpp codegen
DO_CODEGEN_TOKEN_IDS = cargo run --example build_token_ids --manifest-path codegen/Cargo.toml

token_ids.hpp: codegen/examples/build_token_ids.rs
	$(DO_CODEGEN_TOKEN_IDS)
CLEAN += token_ids.hpp
update-depend: token_ids.hpp

# lib-ruby-parser.hpp codegen
lib-ruby-parser.hpp: codegen/examples/merge_headers.rs $(HPP_FILES) token_ids.hpp
	cargo run --example merge_headers --manifest-path codegen/Cargo.toml
CLEAN += lib-ruby-parser.hpp
update-depend: lib-ruby-parser.hpp

# manual codegen task
do-codegen:
	$(DO_CODEGEN)
