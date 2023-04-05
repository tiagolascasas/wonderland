"use strict";

laraImport("clava.ClavaJoinPoints");
laraImport("weaver.WeaverJps");
laraImport("weaver.Query");
laraImport("FunctionOutliner");
laraImport("AstDumper");

function main() {
    const dumper = new AstDumper();
    dumper.dump();

    var beginPragma = null;
    var endPragma = null;

    // We want the wrapper statement around the pragma, not the pragma itself
    // as the wrapper statements both share the same parent (i.e., are on the same scope)
    for (const pragma of Query.search("pragma")) {
        if (pragma.content === "begin_outline")
            beginPragma = pragma.parent;
        if (pragma.content == "end_outline")
            endPragma = pragma.parent;
    }

    if (beginPragma == null || endPragma == null) {
        println("Could not find the region for outlining!")
        println("Begin: " + beginPragma);
        println("End : " + endPragma);
        return;
    }

    const begin = beginPragma.siblingsRight[0];
    const end = endPragma.siblingsLeft[endPragma.siblingsLeft.length - 1];
    beginPragma.detach();
    endPragma.detach();

    println("Beginning the outline process...");
    const outliner = new FunctionOutliner();
    outliner.outline(begin, end);
    println("Outlining finished!");
}

main();