// include the benchmark suite(s) you want to use
laraImport("lara.benchmark.RosettaBenchmarkSet");
laraImport("weaver.WeaverJps");

function main() {
	//create a BenchmarkSet object
	const benches = new RosettaBenchmarkSet();

	//choose the individual benchmark within the set
	benches.setBenchmarks(["3d-rendering", "digit-recognition", "face-detection"]);

	//choose the input size(s) to be used during execution
	benches.setInputSizes(["N"]);

	//go through each benchmark (objects of type BenchmarkInstance)
	for (var bench of benches) {
		// loads the benchmark into Clava's AST
		bench.load();

		// now everything is ready for you to do your analysis and transformations
		// in this example, we're just printing the name of every function
		var funNames = [];
		for (var elem of WeaverJps.search("function")) {
			if (elem.isImplementation) {
				funNames.push(elem.name);
			}
		}
		println(funNames.join(","));

		// now, we prepare for compilation
		// if you are on Windows, you may wish to choose MinGW instead of the default (MSVC), but
		// this is entirely dependent on your system. Check Clava's CMake docs for more info
		bench.getCMaker().setGenerator("MinGW Makefiles");

		// now we compile the benchmark
		bench.compile();

		// and finally, we execute it
		bench.execute();
	}
}

main()