"use strict";

laraImport("clava.ClavaJoinPoints");
laraImport("weaver.WeaverJps");
laraImport("lara.vitishls.VitisHls");

var fun = null;
var norm = null;
for (var elem of WeaverJps.search("function")) {
	if (elem.isImplementation) {
		if (elem.name == "kNN_PredictAll") {
			fun = elem;
		}
		if (elem.name == "kNN_MinMaxNormalize") {
			norm = elem;
		}
	}
}

const tern = norm.children[norm.numChildren - 1].children[1].children[3].children[3];
tern.replaceWith(ClavaJoinPoints.stmtLiteral("nfeature = (isnan(nfeature) ? 0.0 : (isinf(nfeature) ? 1.0 : nfeature));"));

var results = "";

for (var chunk = 1; chunk <= 100; chunk++) {
	const body = fun.children[fun.numChildren - 1];
	const lit1 = body.children[0].children[0].children[0].children[1];
	const lit2 = body.children[2].children[2].children[0].children[1];
	const pragma = body.children[2].children[3].children[0].children[0];
	const lit3 = body.children[2].children[3].children[1].children[0].children[0].children[1];
	const lit4 = body.children[3].children[3].children[1].children[0].children[0].children[1];
	
	lit1.replaceWith(ClavaJoinPoints.exprLiteral("" + chunk));
	lit2.replaceWith(ClavaJoinPoints.exprLiteral("" + chunk));
	pragma.replaceWith(ClavaJoinPoints.stmtLiteral("#pragma HLS UNROLL factor = " + chunk + " skip_exit_check"));
	lit3.replaceWith(ClavaJoinPoints.exprLiteral("" + chunk));
	lit4.replaceWith(ClavaJoinPoints.exprLiteral("" + chunk));
	
	var vitis = new VitisHls("kNN_PredictAll", 5, "xcvc1902-vsvd1760-2MP-e-S");
	var success = vitis.synthesize();
	
	if (success) {
	    var report = vitis.getSynthesisReport();
	    vitis.prettyPrintReport(report);
	    results += chunk + "," + report["execTime"] + "," + report["latency"] + "," + report["fmax"] + "\n";
	}
	println(results);
}