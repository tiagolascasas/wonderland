"use strict";

laraImport("clava.ClavaJoinPoints");
laraImport("weaver.WeaverJps");
laraImport("weaver.Query");
laraImport("lara.vitishls.VitisHls");

function vitisIndividualFuns(funs) {
    var results = "Task,execTime,latency,fmax,%FF,%LUT,%BRAM,%DSP\n";

    for (const fun of funs) {
        println(fun);

        var vitis = new VitisHls(fun, 5, "xcvc1902-vsvd1760-2MP-e-S");
        vitis.setFlowTarget("vitis");
        vitis.addSource("V0CE/edge_detect.cpp");
        vitis.addSource("V0CE/util.cpp");
        vitis.addSource("V0CE/util.h");
        vitis.addSource("V0CE/config.h");
        var success = vitis.synthesize();

        if (success) {
            var report = vitis.getSynthesisReport();
            vitis.prettyPrintReport(report);
            results += `${fun},${report["execTimeWorst"]},${report["latencyWorst"]},${report["fmax"]},`;
            results += `${report["perFF"]},${report["perLUT"]},${report["perBRAM"]},${report["perDSP"]}\n`;
        }
        println(results);
    }
    results += "\n";
}

function callGraphs() {
    var callGraph = {}

    for (const $function of Query.search("function")) {
        for (const $call of Query.searchFrom($function, "call")) {
            if (!($function.signature in callGraph)) {
                callGraph[$function.signature] = {};
            }
            if (!($call.signature in callGraph[$function.signature])) {
                callGraph[$function.signature][$call.signature] = 0;
            }
            callGraph[$function.signature][$call.signature]++;
        }
    }

    println('digraph static_call_graph {\n');
    for (f in callGraph) {
        for (c in callGraph[f]) {
            println('\t"' + f + '"->"' + c + '" [label="' + callGraph[f][c] + '"];');
        }
    }
    println('}');
}

vitisIndividualFuns(["edge_detect", "rgbToGrayscale", "convolve2d", "combthreshold"]);
//callGraphs();