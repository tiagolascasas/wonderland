"use strict";

laraImport("weaver.Query");
laraImport("clava.ClavaJoinPoints");
laraImport("clava.ClavaType");

laraImport("Pointerizer");

class FunctionOutliner {
    static GLOBAL_OUTLINE_ID = 1;
    #verbose;

    constructor() {
        this.#verbose = true;
    }

    setVerbosity(verbose) {
        this.#verbose = verbose;
    }

    outline(begin, end) {
        return this.outlineWithName(begin, end, this.generateName())
    }

    outlineWithName(begin, end, functionName) {
        this.printMsg("Attempting of outlining a function with the name \"" + functionName + "\"");

        if (!this.checkIfOutlinable(begin, end)) {
            this.printMsg("Provided code region is not outlinable! Aborting...");
        }

        //------------------------------------------------------------------------------
        const scope = begin.parent;
        const split = this.splitRegions(scope, begin, end);
        const prologue = split[0];
        var region = split[1];
        const epilogue = split[2];

        //------------------------------------------------------------------------------
        const callPlaceholder = ClavaJoinPoints.stmtLiteral("//placeholder for the call to " + functionName);
        begin.insertBefore(callPlaceholder);
        this.printMsg("Created a placeholder call to the new function");

        //------------------------------------------------------------------------------
        const declareBefore = this.findDeclsWithDependency(region, epilogue);
        region = region.filter((stmt) => !declareBefore.includes(stmt));
        for (var i = declareBefore.length - 1; i >= 0; i--) {
            const decl = declareBefore[i];
            decl.detach();
            begin.insertBefore(decl);
        }
        this.printMsg("Moved declarations from outline region to immediately before the region");

        //------------------------------------------------------------------------------
        const referencedInRegion = this.findRefsInRegion(region);
        const funParams = this.createParams(referencedInRegion);
        this.createFunction(functionName, region, funParams);

        //------------------------------------------------------------------------------
        const callArgs = this.createArgs(funParams);
        // create call


        //this.createFunction(region);
    }

    createFunction(name, region, params) {
        var oldFun = region[0];
        while (oldFun.joinPointType != "function") {
            oldFun = oldFun.parent;
        }

        const retType = ClavaType.asType("void");
        const fun = ClavaJoinPoints.functionDecl(name, retType, params);
        oldFun.insertBefore(fun);
        const scope = ClavaJoinPoints.scope();
        fun.setBody(scope);

        for (const stmt of region) {
            stmt.detach();
            scope.insertEnd(stmt);
        }

        // make sure scalar refs are now dereferenced pointers to params
        this.scalarsToPointers(region, params);
    }

    scalarsToPointers(region, params) {
        for (const stmt of region) {
            for (const varref of Query.searchFrom(stmt, "varref")) {
                for (const param of params) {
                    if (param.name === varref.name && varref.type.joinPointType === "builtinType") {
                        const newVarref = ClavaJoinPoints.varRef(param);
                        const op = ClavaJoinPoints.unaryOp("*", newVarref);
                        varref.replaceWith(op);
                    }
                }
            }
        }
        // if refs are to scalars, turn them into dereferenced pointers
        /*
        if (varref.type.joinPointType == "builtinType") {
            //Pointerizer.scalarRefToDereferencedPointer(varref);
            const varrefClone = varref.copy();
            varrefClone.type = ClavaJoinPoints.pointer(varrefClone.type);
            const op = ClavaJoinPoints.unaryOp("*", varrefClone);
            varref.replaceWith(op);
        }*/
    }

    createArgs(params) {
        const args = [];

        //...
        return args;
    }

    createParams(varrefs) {
        const params = [];

        for (const ref of varrefs) {
            const name = ref.name;
            const varType = ref.type;

            if (varType.joinPointType == "arrayType") {
                const param = ClavaJoinPoints.param(name, varType);
                params.push(param);
            }
            if (varType.joinPointType == "builtinType") {
                const newType = ClavaJoinPoints.pointer(varType);
                const param = ClavaJoinPoints.param(name, newType);
                params.push(param);
            }
            // and if varType is a pointer, do the same as the array?
        }

        //...
        return params;
    }

    findRefsInRegion(region) {
        const decls = [];
        const declsNames = [];
        for (const stmt of region) {
            for (const decl of Query.searchFrom(stmt, "decl")) {
                decls.push(decl);
                declsNames.push(decl.name);
            }
        }

        const varrefs = [];
        const varrefsNames = [];
        for (const stmt of region) {
            for (const varref of Query.searchFrom(stmt, "varref")) {
                // may need to filter for other types, like macros, etc
                // select all varrefs with no matching decl in the region
                if (!varrefsNames.includes(varref.name) && !varref.isFunctionCall && !declsNames.contains(varref.name)) {
                    varrefs.push(varref);
                    varrefsNames.push(varref.name);
                }
            }
        }
        this.printMsg("Found " + varrefsNames.length + " external variable references inside outline region");
        return varrefs;
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

    splitRegions(scope, begin, end) {
        const prologue = []
        const region = [];
        const epilogue = [];

        var inPrologue = true;
        var inRegion = false;
        for (const child of scope.children) {
            if (inPrologue) {
                if (child.astId == begin.astId) {
                    region.push(child);
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
        var name = "__outlined_function_" + FunctionOutliner.GLOBAL_OUTLINE_ID;
        FunctionOutliner.GLOBAL_OUTLINE_ID++;
        return name;
    }
}