"use strict";

laraImport("weaver.Query");

class AstDumper {
    constructor() { }

    dump() {
        var start = null;
        for (const jp of Query.search("function")) {
            if (jp.name == "main")
                start = jp.parent;
        }

        println(start.joinPointType);
        for (const child of start.children) {
            this.#dumpJoinPoint(child, 1);
        }
    }

    #dumpJoinPoint(jp, indent) {
        print(' '.repeat(indent) + jp.joinPointType);
        if (jp.joinPointType == "param") {
            print(" " + jp.type);
        }
        if (jp.joinPointType == "unaryOp") {
            print(" " + jp.kind);
        }
        println("");

        if (jp.children.length > 20) {
            var allLits = true;
            for (const child of jp.children) {
                if (child.joinPointType != "intLiteral") {
                    allLits = false;
                }
            }
            if (allLits) {
                println(' '.repeat(indent + 2) + jp.joinPointType + " (" + jp.children.length + "x)");
                return;
            }
        }
        for (const child of jp.children) {
            this.#dumpJoinPoint(child, indent + 2);
        }
    }
}