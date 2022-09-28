"use strict";

laraImport("weaver.WeaverJps");

const funs = [];
for (var elem of WeaverJps.search("function")) {
    if (elem.isImplementation) {
        funs.push(elem);
    }
}

println(funs);