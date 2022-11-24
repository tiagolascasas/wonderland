laraImport("weaver.Query");
laraImport("lara.vitishls.VitisHls");

function main() {
	const graph = buildGraph();
	addDuplicatedFunctions(graph);

	const info = getNodeInfo(graph);
	printGraph(graph, info);
}


function buildGraph() {
	// Utility object that counts tuples
	const callGraph = {}
	const blacklist = ["abs", "floor", "output_dsp", "printf", "checksum", "input_dsp"];
	
	// Collect information
	for (const fun of Query.search("function")) 
	{
		for (const cl of Query.searchFrom(fun, "call")) 
		{
			if (!blacklist.contains(cl.name)) {
				// Test 1st key
				if (!(fun.name in callGraph)) 
				{
					callGraph[fun.name] = {};
				}
			
				// Test 2nd key
				if (!(cl.name in callGraph[fun.name])) 
				{
					callGraph[fun.name][cl.name] = {"count": 0, "sig": getArgsFromSig(cl.signature)};
				}
			
				// Increment
				callGraph[fun.name][cl.name]["count"]++;
			}
		}
	}
	return callGraph;
}

function addDuplicatedFunctions(callGraph) {
	// Add duplicated funs
	const toAdd = {};
	
	for (f in callGraph) {
		for (c in callGraph[f]) {
			if (callGraph[f][c]["count"] > 1) {
				toAdd[f] = {};
				for (var i = 1; i < callGraph[f][c]["count"]; i++) {
					var newName = c + "(" + i + ")";
					toAdd[f][newName] = callGraph[f][c];
				}
				callGraph[f][c]["count"] = 1;
			}
		}
	}

	for (f in toAdd) {
	    for (c in toAdd[f]) {
	        callGraph[f][c] = toAdd[f][c];
	    }
	}
}

function getArgsFromSig(sig) {
	const regExp = /\(([^)]+)\)/;
	const matches = regExp.exec(sig);
	return matches[1];
}

function getNodeInfo(callGraph) {
	const funs = new Set();

	for (f in callGraph) {
		funs.add(f);
		for (c in callGraph[f]) {
		
		  funs.add(c);
		}
	}

	const info = {};
	const cache = {};
	
	for (const fun of funs) {
		if (fun != "main") {
			const actualFun = fun.split("(")[0];
			if (actualFun in cache) {
				info[fun] = cache[actualFun];
				println("cache hit");
			}
			else {
				info[fun] = getVitisMetrics(actualFun);
				cache[fun] = info[fun];
			}
		}
	}
	return info;
}

function getVitisMetrics(fun) {
	//return {"execTime": 0.000012312, "FF": 0.0123123, "LUT": 0.0132123, "BRAM": 0.064564, "DSP": 0.064564};
	var vitis = new VitisHls(fun, 5, "xcvc1902-vsvd1760-2MP-e-S");
	vitis.setFlowTarget("vitis");
	var success = vitis.synthesize();
	
	if (success) {
	   var report = vitis.getSynthesisReport();
	   vitis.prettyPrintReport(report);
	   var res = {"execTime": report["execTimeWorst"], 
	   			"FF": report["perFF"], 
	   			"LUT": report["perLUT"], 
	   			"BRAM": report["perBRAM"], 
	   			"DSP": report["perDSP"]
	   };
	   return res;
	}
	else return {"execTime": 0, "FF": 0.0, "LUT": 0.0, "BRAM": 0, "DSP": 0.0};
}

function toFixed(value, precision) {
    var power = Math.pow(10, precision || 0);
    return String(Math.round(value * power) / power);
}

function printGraph(callGraph, nodeInfo) {
	// prologue
	const options = `
digraph static_call_graph {
	rankdir=LR;
	node [shape=rectangle]
`;
	println(options);
	
	// nodes
	for (n in nodeInfo) {
		const execTime = toFixed(nodeInfo[n]["execTime"], 7);
		const ff = toFixed(nodeInfo[n]["FF"] * 100, 2);
		const lut = toFixed(nodeInfo[n]["LUT"] * 100, 2);
		const bram = toFixed(nodeInfo[n]["BRAM"] * 100, 2);
		const dsp = toFixed(nodeInfo[n]["DSP"] * 100, 2);
		println(`\t"${n}" [label="${n}\\nExecTime: ${execTime}\\nFF: ${ff}%\\nLUT: ${lut}%\\nBRAM: ${ff }%\\nDSP: ${dsp}%"]`);
	}

	// edges
	println("");
	for (f in callGraph) {
	    for (c in callGraph[f]) {
	        println('\t"' + f + '"->"' + c + '" [label="' + callGraph[f][c]["sig"] + '"];');
	    }
	}

	// epilogue
	println('}');
}

main();