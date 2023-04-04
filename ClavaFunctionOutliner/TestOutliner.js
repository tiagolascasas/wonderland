"use strict";

laraImport("clava.ClavaJoinPoints");
laraImport("weaver.WeaverJps");
laraImport("weaver.Query");
laraImport("FunctionOutliner")

function main() {
    var begin = null;
    var end = null;

    // We want the wrapper statement around the pragma, not the pragma itself
    // as the wrapper statements both share the same parent (i.e., are on the same scope)
    for (const pragma of Query.search("pragma")) {
        if (pragma.content === "begin_outline")
            begin = pragma.parent;
        if (pragma.content == "end_outline")
            end = pragma.parent;
    }

    if (begin == null || end == null) {
        println("Could not find the region for outlining!")
        println("Begin: " + begin);
        println("End : " + end);
        return;
    }

    println("Beginning the outline process...");
    const outliner = new FunctionOutliner();
    outliner.outline(begin, end);
    println("Outlining finished!");
}

main();