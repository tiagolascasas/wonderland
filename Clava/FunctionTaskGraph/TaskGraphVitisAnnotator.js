"use strict";

laraImport("lara.vitishls.VitisHls");
laraImport("FunctionTaskGraphPrototype");

class TaskGraphVitisAnnotator {
    static annotate(graph) {
        const cache = {};

        for (const fun in graph.nodes) {
            if (fun != "main") {
                const actualFun = fun.split("(")[0];
                if (actualFun in cache) {
                    graph.nodes[fun] = { ...graph.nodes[fun], ...cache[actualFun] };
                    println("cache hit");
                }
                else {
                    graph.nodes[fun] = this.#getVitisMetrics(actualFun);
                    cache[fun] = graph.nodes[fun];
                }
            }
        }
        return info;
    }

    static #getVitisMetrics(fun) {
        //return { "execTime": 0.000012312, "FF": 0.0123123, "LUT": 0.0132123, "BRAM": 0.064564, "DSP": 0.064564 };
        var vitis = new VitisHls(fun, 5, "xcvc1902-vsvd1760-2MP-e-S");
        vitis.setFlowTarget("vitis");
        var success = vitis.synthesize();

        if (success) {
            var report = vitis.getSynthesisReport();
            vitis.prettyPrintReport(report);
            var res = {
                "execTime": report["execTimeWorst"],
                "FF": report["perFF"],
                "LUT": report["perLUT"],
                "BRAM": report["perBRAM"],
                "DSP": report["perDSP"]
            };
            return res;
        }
        else return { "execTime": 0, "FF": 0.0, "LUT": 0.0, "BRAM": 0, "DSP": 0.0 };
    }
}