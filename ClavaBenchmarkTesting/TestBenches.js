// include the benchmark suite(s) you want to use
laraImport("lara.benchmark.AxBenchBenchmarkSet");
laraImport("weaver.WeaverJps");
laraImport("clava.graphs.StaticCallGraph");

function main() {
    //create a BenchmarkSet object
    const benches = new AxBenchBenchmarkSet();

    //choose the individual benchmark within the set
    benches.setBenchmarks([
        //"blackscholes",
        //"fft",
        //"inversek2j",
        //"jmeint",
        "jpeg",
        //"kmeans",
        //"sobel"
    ]);
    benches.setInputSizes(["N"]);
    let success = [];

    for (var bench of benches) {
        try {
            bench.load();
            const main = Query.search("function", { name: "main" }).first();

            const callGraph = StaticCallGraph.build(main);
            const callGraphDot = callGraph.toDot("LR");
            console.log(callGraphDot);
            success.push(bench.getName());
        } catch (e) {
            console.error("Error in benchmark " + bench.getName() + ": " + e);
        }
    }
    print("Success: " + success);
}
main()