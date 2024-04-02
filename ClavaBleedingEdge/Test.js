laraImport("lara.benchmark.RosettaBenchmarkSet");
laraImport("weaver.WeaverJps");
laraImport("clava.graphs.StaticCallGraph");

function testDotGeneration() {
    const main = Query.search("function", { name: "main" }).first();

    const callGraph = StaticCallGraph.build(main);
    const callGraphDot = callGraph.toDot("LR");
    console.log(callGraphDot);
}

function main() {
    const benches = new RosettaBenchmarkSet();
    benches.setBenchmarks(["spam-filter"]);
    benches.setInputSizes(["N"]);

    for (var bench of benches) {
        bench.load();

        testDotGeneration();
    }
}
main()