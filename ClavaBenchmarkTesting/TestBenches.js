// include the benchmark suite(s) you want to use
laraImport("lara.benchmark.RosettaBenchmarkSet");
laraImport("weaver.WeaverJps");
laraImport("clava.graphs.StaticCallGraph");

function main() {
    //create a BenchmarkSet object
    const benches = new RosettaBenchmarkSet();

    //choose the individual benchmark within the set
    benches.setBenchmarks(["spam-filter"]);
    benches.setInputSizes(["N"]);

    for (var bench of benches) {
        bench.load();
        const main = Query.search("function", { name: "main" }).first();

        const callGraph = StaticCallGraph.build(main);
        const callGraphDot = callGraph.toDot("LR");
        console.log(callGraphDot);
    }
}
main()