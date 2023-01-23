"use strict";

laraImport("clava.ClavaJoinPoints");
laraImport("weaver.WeaverJps");
laraImport("weaver.Query");
laraImport("lara.vitishls.VitisHls");

function vitisIndividualFuns() {
    var results = "";

   const funs = files[file];

   for (const fun of funs) {
       println(fun);

       var vitis = new VitisHls(fun, 5, "xcvc1902-vsvd1760-2MP-e-S");
       vitis.setFlowTarget("vitis");
       var success = vitis.synthesize();

       if (success) {
           var report = vitis.getSynthesisReport();
           vitis.prettyPrintReport(report);
           results += `${file},${fun},${report["execTimeWorst"]},${report["latencyWorst"]},${report["fmax"]},`;
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

vitisEdgeDetect();
//callGraphs();