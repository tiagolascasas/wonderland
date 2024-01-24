// include the benchmark suite(s) you want to use
laraImport("lara.benchmark.MachSuiteBenchmarkSet");
laraImport("weaver.WeaverJps");

function main() {
	const benches = new MachSuiteBenchmarkSet();
	benches.print();
	benches.setBenchmarks([
	    "aes",
	    "backprop",
	    "bfs-bulk",
	    "bfs-queue",
	    "fft-strided",
	    "fft-transpose",
	    "gemm-blocked",
	    "gemm-ncubed",
	    "kmp",
	    "md-grid",
	    "md-knn",
	    "nw",
	    "sort-merge",
	    "sort-radix",
	    "spmv-crs",
	    "spmv-ellpack",
	    "stencil-2d",
	    "stencil-3d",
	    "viterbi"
	]);
	benches.setInputSizes(["D"]);

	let res = "";
	for (const bench of benches) {
		bench.load();

		const funNames = [];
		for (const elem of WeaverJps.search("function")) {
			if (elem.isImplementation) {
				funNames.push(elem.name);
			}
		}
		res += bench.getName() + " -> " + funNames.join(",") + "\n\n";

		// change accordingly
		bench.getCMaker().setGenerator("MinGW Makefiles");
		bench.compile();
		bench.execute();
	}
	println(res);
}
main()