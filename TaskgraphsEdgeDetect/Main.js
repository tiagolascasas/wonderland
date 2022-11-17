"use strict";

laraImport("clava.ClavaJoinPoints");
laraImport("weaver.WeaverJps");
laraImport("lara.vitishls.VitisHls");

const files = {
	"edge_detect_tasks_V0.c": ["rgbToGrayscale", "convolve2d", "combthreshold"],/*
	"edge_detect_tasks_V0_const.c": ["rgbToGrayscale", "convolve2d_smooth", "convolve2d_vert", "convolve2d_horiz", "combthreshold"],
	"edge_detect_tasks_V1.c": ["rgbToGrayscale", "convolve2d", "horizontal_and_vertical_filtering_task", "combthreshold"],
	"edge_detect_tasks_V1_const.c": ["rgbToGrayscale", "convolve2d_smooth", "horizontal_and_vertical_filtering_task", "combthreshold"],
	"edge_detect_tasks_V2.c": ["rgbToGrayscale", "convolve2d_smooth", "convolve2d_parallel", "combthreshold"],
	"edge_detect_tasks_V2_const.c": ["rgbToGrayscale", "convolve2d_smooth", "convolve2d_vert_horiz", "combthreshold"]*/
}

var results = "";

for (const file in files) {
	println(file);
	const funs = files[file];

	for (const fun of funs) {
		println(fun);

		var vitis = new VitisHls(fun, 5, "xcvc1902-vsvd1760-2MP-e-S");
		vitis.addSource(file);
		vitis.setFlowTarget("vitis");
		var success = vitis.synthesize();
		
		if (success) {
		   var report = vitis.getSynthesisReport();
		   vitis.prettyPrintReport(report);
		   results += `${file},${fun},${report["execTimeWorst"]},${report["latencyWorst"]},${report["fmax"]}\n`;
		}
		println(results);
	}
	results += "\n";
}


