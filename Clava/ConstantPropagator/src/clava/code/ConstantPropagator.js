"use strict";

laraImport("weaver.Query");

class ConstantPropagator {
    constructor() { }

    doPassesUntilStop(maxPasses = 99) {
        let passes = 1;
        let hasChanged = this.doPass();

        while (hasChanged && passes < maxPasses) {
            hasChanged = this.doPass();
            passes++;
        }
        return passes;
    }

    doPass() {
        println("Propagating");

        for (const fun of Query.search("function")) {
            this.#propagateInFunction(fun);
        }

        return false;
    }

    #propagateInFunction(fun) {
        const allDecls = Query.searchFrom(fun, "vardecl").chain();
        const allParams = Query.searchFrom(fun, "param").chain();
        const allDefs = [...allDecls, ...allParams];

        for (const def of allDefs) {
            const refChain = this.#findRefChain(def, fun);
            this.#propagateChain(refChain);
        }
    }

    #findRefChain(def, fun) {
        return [];
    }

    #propagateChain(refChain) {
        println(refChain.length);
    }
}