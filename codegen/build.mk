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
messages.c: $(CODEGEN_DEPS)
	$(DO_CODEGEN)
CLEAN += messages.c

messages.h: $(CODEGEN_DEPS)
	$(DO_CODEGEN)
CLEAN += messages.h

nodes.c: $(CODEGEN_DEPS)
	$(DO_CODEGEN)
CLEAN += nodes.c

nodes.h: $(CODEGEN_DEPS)
	$(DO_CODEGEN)
CLEAN += nodes.h

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
# update-depend: lib-ruby-parser.hpp
# FIXME

# manual codegen task
do-codegen:
	$(DO_CODEGEN)
