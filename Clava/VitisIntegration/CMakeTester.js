"use strict";

laraImport("weaver.WeaverJps");
laraImport("weaver.Query");
laraImport("lara.cmake.CMaker");

function testCMaker() {
    println("Testing CMaker integration");

    var cmaker = new CMaker("example");
    cmaker.addCurrentAst();
    cmaker.setGenerator("MinGW Makefiles");
    cmaker.build();
    println(cmaker.getMakeOutput());

    println("Finished testing CMaker");
}

function main() {
    testCMaker();
}

main();