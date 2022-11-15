"use strict";

laraImport("weaver.WeaverJps");
laraImport("weaver.Query");
laraImport("lara.benchmark.CHStoneBenchmarkSet");
laraImport("lara.vitishls.VitisHls");

function testVitisHls() {
    println("Testing Vitis HLS integration");

    var vitis = new VitisHls("maddv", 5);
    //vitis.setTopFunction("maddv");
    //vitis.setPlatform("xcvu5p-flva2104-1-e");
    //vitis.setClock(10);

    //vitis.addSource("example.c");
    //vitis.addSource("example1.c");

    var success = vitis.synthesize();
    if (success) {
        var report = vitis.getSynthesisReport();
        vitis.prettyPrintReport(report);
    }
    println("Finished testing Vitis HLS");
}

function testVitisWithBenchmarks() {
    const benches = new CHStoneBenchmarkSet();
    const benchNames = [/*"adpcm", "aes", "blowfish",*/ "mips"];
    benches.setBenchmarks(benchNames);
    benches.setInputSizes(["N"]);

    const topFuns = {
        "adpcm": "quantl",
        "aes": "decrypt",
        "blowfish": "blowfish_main",
        "mips": "mips"
    };
    const reports = {};

    for (var bench of benches) {
        bench.load();
        const benchName = bench._benchmarkName;
        const topFun = topFuns[benchName];

        const vitis = new VitisHls();
        vitis.setTopFunction(topFun);
        vitis.setPlatform("xcvu5p-flva2104-1-e");
        vitis.setClock(10);

        const success = vitis.synthesize();
        if (success) {
            const report = vitis.getSynthesisReport();
            reports[benchName] = report;
        }
    }

    println("---------------------------------------------------------");
    for (const bench of benchNames) {
        const report = reports[bench];
        println("Benchmark " + bench + ": topFun = " + report["topFun"] + ", latency = " + report["latency"]);
    };
    println("---------------------------------------------------------");
    println("Finished testing Vitis HLS using CHStone");
}

function main() {
    testVitisHls();
    println("-----------------------------------");
    //testVitisWithBenchmarks();
}

main();