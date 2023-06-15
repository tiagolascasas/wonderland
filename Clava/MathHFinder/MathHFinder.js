"use strict";

laraImport("weaver.Query");
laraImport("lara.Io");


function main() {
    const json = {};

    for (const call of Query.search("call")) {
        const fun = call.function;
        const paramTypes = [];

        for (const param of fun.params) {
            paramTypes.push(param.type.code);
        }
        json[fun.name] = paramTypes;
    }
    //const jsonString = JSON.stringify(json, null, 4);
    Io.writeJson("MathHSignatures.json", json);
}

main();