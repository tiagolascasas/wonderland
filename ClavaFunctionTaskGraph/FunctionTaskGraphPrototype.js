"use strict";

laraImport("weaver.Query");

class FunctionTaskGraphPrototype {
    blacklist = [];
    nodes = {};
    edges = {};

    constructor(blacklist) {
        this.blacklist = blacklist;
        this.#buildGraph();
    }

    #buildGraph() {
        for (const fun of Query.search("function")) {

            for (const cl of Query.searchFrom(fun, "call")) {

                if (!this.blacklist.contains(cl.name)) {

                    if (!(fun.name in this.edges)) {
                        this.edges[fun.name] = {};
                    }

                    if (!(cl.name in this.edges[fun.name])) {
                        this.edges[fun.name][cl.name] = { "count": 0, "in": this.#getArgsFromSig(cl.signature) };
                    }
                    this.edges[fun.name][cl.name]["count"]++;
                }
            }
        }

        this.#addDuplicatedFunctions();

        const funs = new Set();
        for (const fun in this.edges) {
            funs.add(fun);

            for (const cl in this.edges[fun]) {
                funs.add(cl);
            }
        }

        for (const fun of funs) {
            const unique = fun.indexOf("(") > -1;
            this.nodes[fun] = { "unique": unique };
        }
    }

    #addDuplicatedFunctions() {
        const toAdd = {};

        for (const fun in this.edges) {
            for (const cl in this.edges[fun]) {

                if (this.edges[fun][cl]["count"] > 1) {
                    toAdd[fun] = {};

                    for (var i = 1; i < this.edges[fun][cl]["count"]; i++) {
                        var newName = cl + "(" + i + ")";
                        toAdd[fun][newName] = this.edges[fun][cl];
                    }
                    this.edges[fun][cl]["count"] = 1;
                }
            }
        }

        for (const fun in toAdd) {
            for (const cl in toAdd[fun]) {

                this.edges[fun][cl] = toAdd[fun][cl];
            }
        }
    }

    #getArgsFromSig(sig) {
        const regExp = /\(([^)]+)\)/;
        const matches = regExp.exec(sig);
        return matches[1];
    }

    #toFixed(value, precision) {
        var power = Math.pow(10, precision || 0);
        return String(Math.round(value * power) / power);
    }

    toDot(printNodeInfo) {
        var str = "";
        // prologue
        const options = `
digraph static_call_graph {
	rankdir=LR;
	node [shape=rectangle]\n
`;
        str += options;

        // nodes
        if (printNodeInfo) {
            for (const n in this.nodes) {
                const execTime = this.#toFixed(this.nodes[n]["execTime"], 7);
                const ff = this.#toFixed(this.nodes[n]["FF"] * 100, 2);
                const lut = this.#toFixed(this.nodes[n]["LUT"] * 100, 2);
                const bram = this.#toFixed(this.nodes[n]["BRAM"] * 100, 2);
                const dsp = this.#toFixed(this.nodes[n]["DSP"] * 100, 2);
                str += `\t"${n}" [label="${n}\\nExecTime: ${execTime}\\nFF: ${ff}%\\nLUT: ${lut}%\\nBRAM: ${ff}%\\nDSP: ${dsp}%"]\n`;
            }
        }
        str += "\n";

        // edges
        for (const fun in this.edges) {
            for (const cl in this.edges[fun]) {
                str += '\t"' + fun + '"->"' + cl + '" [label="' + this.edges[fun][cl]["in"] + '"];\n';
            }
        }

        // epilogue
        str += "}\n";
        return str;
    }
}

