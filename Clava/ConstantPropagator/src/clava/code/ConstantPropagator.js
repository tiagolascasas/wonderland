"use strict";

laraImport("weaver.Query");

class ConstantPropagator {
    constructor() { }

    doPassesUntilStop(maxPasses = 99) {
    }

    doPass() {
        println("Propagating");
        return false;
    }
}