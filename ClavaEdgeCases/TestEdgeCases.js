"use strict";

laraImport("weaver.Query");

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

//structComparison();
defaultArguments();