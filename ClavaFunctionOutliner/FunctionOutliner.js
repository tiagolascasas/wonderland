"use strict";

laraImport("weaver.Query");

class FunctionOutliner {
    #verbose;

    constructor() {
        this.#verbose = true;
    }

    setVerbosity(verbose) {
        this.#verbose = verbose;
    }

    outline(begin, end) {
        if (!this.checkIfOutlinable(begin, end)) {
            this.printMsg("Provided code region is not outlinable! Aborting...");
        }

        const scope = begin.parent;
        const stmts = this.getStatements(scope, begin, end);

    }

    getStatements(scope, begin, end) {
        const stmts = [];

        var inRegion = false;
        for (const child of scope.children) {
            if (!inRegion) {
                if (child.astId == begin.astId) {
                    stmts.push(child);   // might want to give the option of including begin/end in the region or not
                    inRegion = true;
                }
            }
            else {
                stmts.push(child);
                if (child.astId == end.astId) {
                    inRegion = false;   // for correctness?
                    break;
                }
            }
        }
        this.printMsg("Found " + stmts.length + " statements for the outline region");
        return stmts;
    }

    checkIfOutlinable(begin, end) {
        if (begin.parent.astId != end.parent.astId) {
            this.printMsg("Requirement not met: begin and end joinpoints are not at the same scope level");
            println(begin.parent);
            println(end.parent);
            return false;
        }
        else {
            this.printMsg("Requirement met: begin and end joinpoints are at the same scope level");
        }
        return true;
    }

    printMsg(msg) {
        if (this.#verbose)
            println("[FunctionOutliner] " + msg);
    }
}