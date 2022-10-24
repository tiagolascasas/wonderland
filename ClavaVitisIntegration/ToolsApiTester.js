"use strict";

laraImport("weaver.WeaverJps");
laraImport("weaver.Query");
laraImport("tools.cmake.CMaker");

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