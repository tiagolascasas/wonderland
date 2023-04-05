"use strict";

laraImport("weaver.Query");
laraImport("clava.ClavaJoinPoints");

class FunctionOutliner {
    #verbose;

    constructor() {
        this.#verbose = true;
    }

    setVerbosity(verbose) {
        this.#verbose = verbose;
    }

    outline(begin, end, functionName = "default") {
        if (!this.checkIfOutlinable(begin, end)) {
            this.printMsg("Provided code region is not outlinable! Aborting...");
        }

        const scope = begin.parent;
        const split = this.splitRegions(scope, begin, end);
        const prologue = split[0];
        var region = split[1];
        const epilogue = split[2];

        const outlineName = functionName == "default" ? this.generateName() : functionName;
        const callPlaceholder = ClavaJoinPoints.stmtLiteral("//placeholder for the call to " + outlineName);
        begin.insertBefore(callPlaceholder);
        this.printMsg("Created a placeholder call to the new function");

        const declareBefore = this.findDeclsWithDependency(region, epilogue);
        region = region.filter((stmt) => !declareBefore.includes(stmt));
        for (var i = declareBefore.length - 1; i >= 0; i--) {
            const decl = declareBefore[i];
            decl.detach();
            begin.insertBefore(decl);
        }
        this.printMsg("Moved declarations from outline region to immediately before the region");

        //this.createFunction(region);
    }

    findDeclsWithDependency(region, epilogue) {
        const regionDecls = [];
        const regionDeclsNames = [];
        for (const stmt of region) {
            if (stmt.joinPointType == "declStmt") {
                regionDecls.push(stmt);
                regionDeclsNames.push(stmt.children[0].name);
            }
        }

        const epilogueVarrefsNames = [];
        for (const stmt of epilogue) {
            // also gets function names... could it cause an issue?
            for (const varref of Query.searchFrom(stmt, "varref")) {
                epilogueVarrefsNames.push(varref.name);
            }
        }

        const declsWithDependency = [];
        for (var i = 0; i < regionDecls.length; i++) {
            const varName = regionDeclsNames[i];
            if (epilogueVarrefsNames.includes(varName)) {
                declsWithDependency.push(regionDecls[i]);
            }
        }
        this.printMsg("Found " + declsWithDependency.length + " declaration(s) referenced after the outline region");
        return declsWithDependency;
    }

    createFunction(region) {
        for (const stmt of region) {
            stmt.detach();
        }
    }

    splitRegions(scope, begin, end) {
        const prologue = []
        const region = [];
        const epilogue = [];

        var inPrologue = true;
        var inRegion = false;
        for (const child of scope.children) {
            if (inPrologue) {
                if (child.astId == begin.astId) {
                    region.push(child);   // might want to give the option of including begin/end in the region or not
                    inPrologue = false;
                    inRegion = true;
                }
                else {
                    prologue.push(child);
                }
            }
            if (inRegion) {
                region.push(child);
                if (child.astId == end.astId) {
                    inRegion = false;
                }
            }
            if (!inPrologue && !inRegion) {
                epilogue.push(child);
            }
        }
        this.printMsg("Found " + region.length + " statements for the outline region");
        this.printMsg("Prologue has " + prologue.length + " statements, and epilogue has " + epilogue.length);
        return [prologue, region, epilogue];
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

    generateName() {
        return "__outlined_fun_A";
    }
}