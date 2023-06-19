"use strict";

laraImport("clava.code.ConstantPropagator");
laraImport("weaver.Query");

function main() {
    const constProp = new ConstantPropagator();

    for (const fun of Query.search("function")) {
        constProp.propagate(fun);
    }
}

main();