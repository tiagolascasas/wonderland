"use strict";

laraImport("weaver.Query");
laraImport("lara.code.Timer");

class CPUTaskEstimator {
    constructor(progName) {
        this.filename = progName + ".csv";
    }

    fromTaskGraph(taskGraph) {
        //TODO: find all calls from task graph,
        // and insert timer() around each call
    }

    fromTaskList(taskList) {
        const timer = new Timer("MICROSECONDS", this.filename);

        for (call in taskList) {
            timer.time($call, `${call.name},`, undefined);
        }
    }
}