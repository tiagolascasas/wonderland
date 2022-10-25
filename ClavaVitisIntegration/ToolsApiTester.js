"use strict";

laraImport("weaver.WeaverJps");
laraImport("weaver.Query");
laraImport("tools.cmake.CMaker");
laraImport("tools.vitishls.VitisHls");

function testCMaker() {
    println("Testing CMaker integration");

    var cmaker = new CMaker("example");
    cmaker.addCurrentAst();
    cmaker.setGenerator("MinGW Makefiles");
    cmaker.build();
    println(cmaker.getMakeOutput());

    println("Finished testing CMaker");
}

function testVitisHls() {
    println("Testing Vitis HLS integration");

    var vitis = new VitisHls();
    vitis.setTopFunction("maddv");
    vitis.setPlatform("xcvu5p-flva2104-1-e");
    vitis.setClock(10);

    var success = vitis.synthesize();
    if (success) {
        println("Synthesis successful!");
        var report = vitis.getSynthesisReport();
        vitis.prettyPrintReport(report);
    }

    println("Finished testing Vitis HLS");
}

function main() {
    println("-----------------------------------");
    testCMaker();
    println("-----------------------------------");
    testVitisHls();
    println("-----------------------------------");
}

main();