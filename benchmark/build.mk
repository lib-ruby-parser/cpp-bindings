benchmark/cpp-parser: $(STATIC_LIB)
	$(call build_cxx_exe,benchmark/benchmark.cpp $(STATIC_LIB),benchmark/cpp-parser)

define download_latest_bench_asset
ASSET_NAME=$(1) SAVE_AS=$(2) ruby benchmark/download_asset.rb
endef

benchmark/download:
	@echo "Downloading repos.zip..."
	$(call download_latest_bench_asset,repos.zip,benchmark/repos.zip)
	@echo "Unpacking repos.zip..."
	unzip --help
	ls -l benchmark/repos.zip
	unzip -q benchmark/repos.zip -d benchmark

	@echo "Downloading Rust parser..."
	$(call download_latest_bench_asset,$(BENCHMARK_RUNNER_ASSET_NAME),benchmark/rust-parser)
	chmod +x benchmark/rust-parser

	@echo "Downloading Ruby parser..."
	$(call download_latest_bench_asset,ruby-parser.rb,benchmark/ruby-parser.rb)

BENCHMARK_ASSETS = \
	benchmark/repos \
	benchmark/cpp-parser \
	benchmark/filelist \
	benchmark/repos.zip \
	benchmark/ruby-parser.rb \
	benchmark/rust-parser \
	benchmark/stats

benchmark/clear:
	rm -rf $(BENCHMARK_ASSETS)

define run_benchmark
cd benchmark && FILELIST_PATH=filelist $(1)
endef

benchmark/compare: benchmark/cpp-parser
	$(call run_benchmark, ./rust-parser)
	$(call run_benchmark, ruby ruby-parser.rb)
	$(call run_benchmark, ./cpp-parser)

BENCHMARK_RECORDING = $(TARGET).benchmark-out
benchmark/record: benchmark/cpp-parser
	echo "Rust:" > $(BENCHMARK_RECORDING)
	$(call run_benchmark, ./rust-parser >> ../$(BENCHMARK_RECORDING))
	echo "Ruby:" >> $(BENCHMARK_RECORDING)
	$(call run_benchmark, ruby ruby-parser.rb >> ../$(BENCHMARK_RECORDING))
	echo "C++:" >> $(BENCHMARK_RECORDING)
	$(call run_benchmark, ./cpp-parser >> ../$(BENCHMARK_RECORDING))
