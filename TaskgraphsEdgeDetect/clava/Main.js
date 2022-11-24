"use strict";

laraImport("clava.ClavaJoinPoints");
laraImport("weaver.WeaverJps");
laraImport("weaver.Query");
laraImport("lara.vitishls.VitisHls");

function vitisIndividualFuns() {
	const files = {
		"edge_detect_tasks_v0.c": ["rgbToGrayscale", "convolve2d", "combthreshold"],
		"edge_detect_tasks_v0c.c": ["rgbToGrayscale", "convolve2d_smooth", "convolve2d_vert", "convolve2d_horiz", "combthreshold"],
		"edge_detect_tasks_v1.c": ["rgbToGrayscale", "convolve2d", "horizontal_and_vertical_filtering_task", "combthreshold"],
		"edge_detect_tasks_v1c.c": ["rgbToGrayscale", "convolve2d_smooth", "horizontal_and_vertical_filtering_task", "combthreshold"],
		"edge_detect_tasks_v2.c": ["rgbToGrayscale", "convolve2d_smooth", "convolve2d_parallel", "combthreshold"],
		"edge_detect_tasks_v2c.c": ["rgbToGrayscale", "convolve2d_smooth", "convolve2d_vert_horiz", "combthreshold"]
	}
	
	var results = "";
	
	for (const file in files) {
		println(file);
		const funs = files[file];
	
		for (const fun of funs) {
			println(fun);
	
			var vitis = new VitisHls(fun, 5, "xcvc1902-vsvd1760-2MP-e-S");
			vitis.addSource("common.c");
			vitis.addSource("common.h");
			vitis.addSource("config.h");
			vitis.addSource(file);
			vitis.setFlowTarget("vitis");
			var success = vitis.synthesize();
			
			if (success) {
			   var report = vitis.getSynthesisReport();
			   vitis.prettyPrintReport(report);
			   results += `${file},${fun},${report["execTimeWorst"]},${report["latencyWorst"]},${report["fmax"]},`;
			   results += `${report["perFF"]},${report["perLUT"]},${report["perBRAM"]},${report["perDSP"]}\n`;
			}
			println(results);
		}
		results += "\n";
	}
}

function vitisEdgeDetect() {
		const files = {
		//"edge_detect_tasks_v0.c": "v0",
		//"edge_detect_tasks_v0c.c": "v0c",
		"edge_detect_tasks_v0ce.c": "v0ce",
		"edge_detect_tasks_v0e.c": "v0e",
		//"edge_detect_tasks_v1.c": "v1",
		//"edge_detect_tasks_v1c.c": "v1c",
		"edge_detect_tasks_v1ce.c": "v1ce",
		"edge_detect_tasks_v1e.c": "v1e",
		//"edge_detect_tasks_v2.c": "v2",
		//"edge_detect_tasks_v2c.c": "v2c",
		"edge_detect_tasks_v2ce.c": "v2ce",
		"edge_detect_tasks_v2e.c": "v2e"
		}
	
	var results = "";
	
	for (const file in files) {
		var name = files[file];
		println(name);
	
		var vitis = new VitisHls("edge_detect", 5, "xcvc1902-vsvd1760-2MP-e-S");
		vitis.addSource("common.c");
		vitis.addSource("common.h");
		vitis.addSource("config.h");
		vitis.addSource(file);
		vitis.setFlowTarget("vitis");
		var success = vitis.synthesize();
		
		if (success) {
		   var report = vitis.getSynthesisReport();
		   vitis.prettyPrintReport(report);
		   results += `${name},${report["execTimeWorst"]},${report["latencyWorst"]},${report["fmax"]},`;
		   results += `${report["perFF"]},${report["perLUT"]},${report["perBRAM"]},${report["perDSP"]}`
		}
		
		println(results);
		results += "\n";
	}
}

function callGraphs() {
	var callGraph = {}
	
	for (const $function of Query.search("function")) {
	    for (const $call of Query.searchFrom($function, "call")) {
	        if (!($function.signature in callGraph)) {
	            callGraph[$function.signature] = {};
	        }
	        if (!($call.signature in callGraph[$function.signature])) {
	            callGraph[$function.signature][$call.signature] = 0;
	        }
	        callGraph[$function.signature][$call.signature]++;
	    }
	}
	
	println('digraph static_call_graph {\n');
	for (f in callGraph) {
		for (c in callGraph[f]) {
			println('\t"' + f + '"->"' + c + '" [label="' + callGraph[f][c] + '"];');
		}
	}
	println('}');
}

//vitisEdgeDetect();
callGraphs();