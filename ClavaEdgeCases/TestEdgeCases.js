"use strict";

laraImport("weaver.Query");
laraImport("clava.code.StatementDecomposer");
laraImport("clava.opt.NormalizeToSubset");

function structComparison() {
    for (const fun of Query.search("function")) {
        println(fun.code);
    }
}

function defaultArguments() {
    for (const call of Query.search("call")) {
        println(call.code);
        for (const arg of call.args) {
            println("    " + arg.joinPointType + " ; " + arg.getValue("isDefaultArgument"));
        }
    }
}

function noDecomposingAutoStatements() {

    for (const fun of Query.search("function")) {
        const body = fun.body;
        //NormalizeToSubset(body, { simplifyLoops: { forToWhile: false } });
    }


    const decomp = new StatementDecomposer();
    for (const stmt of Query.search("statement")) {
        decomp.decomposeAndReplace(stmt);
    }
}

//structComparison();
//defaultArguments();
noDecomposingAutoStatements();