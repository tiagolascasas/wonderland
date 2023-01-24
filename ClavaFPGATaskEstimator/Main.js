"use strict";

laraImport("clava.ClavaJoinPoints");
laraImport("weaver.WeaverJps");
laraImport("weaver.Query");
laraImport("lara.vitishls.VitisHls");

function vitisIndividualFuns(funs, period, platform) {
    var results = "Function,execTime,latency,fmax,ff,lut,bram,dsp\n";

    for (const fun of funs) {
        println(fun);

        const vitis = new VitisHls(fun, period, platform);
        vitis.setFlowTarget("vitis");
        const success = vitis.synthesize();

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

const zcu102 = "xcvu5p-flva2104-1-e";
const period = 5;
const V0 = [

];
const V0CE = [
    "edge_detect_localdata",
    "rgbToGrayscale",
    "convolve2d_smooth",
    "convolve2d_vertical",
    "convolve2d_horizontal",
    "combthreshold"
];

vitisIndividualFuns(V0CE, period, zcu102);