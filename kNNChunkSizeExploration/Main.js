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

for (var chunk = 4; chunk <= 4 ; chunk += 4) {
	const body = fun.children[fun.numChildren - 1];
	const loop = body.children[2];
	const t1 = body.children[0].children[0].children[0].children[0];
	const c1 = body.children[0].children[0].children[0].children[1];
	const c2 = loop.children[2].children[0].children[1];
	const stmt = loop.children[3].children[0];
	
	c1.replaceWith(ClavaJoinPoints.exprLiteral("" + chunk));
	c2.replaceWith(ClavaJoinPoints.exprLiteral("" + chunk));
	//stmt.insertBefore(ClavaJoinPoints.stmtLiteral("#pragma HLS pipeline"));
	
	for (var i = chunk - 1; i > 0; i--) {
		const str = `testing_Y[i + ${i}] = kNN_Predict(training_X, training_Y, testing_X[i + ${i}], min, max, ${i});`
		stmt.insertAfter(ClavaJoinPoints.stmtLiteral(str));
	}

	const total = +t1.code;
	const remainder = total % chunk;
	for (var i = remainder - 1; i >= 0; i--) {
		const str = `testing_Y[N + ${i}] = kNN_Predict(training_X, training_Y, testing_X[N + ${i}], min, max, ${i});`
		loop.insertAfter(ClavaJoinPoints.stmtLiteral(str));
	}
	
	var vitis = new VitisHls("kNN_PredictAll", 5, "xcvc1902-vsvd1760-2MP-e-S");
	var success = vitis.synthesize();
	
	if (success) {
	    var report = vitis.getSynthesisReport();
	    vitis.prettyPrintReport(report);
	    results += chunk + "," + report["execTimeWorst"] + "," + report["latencyWorst"] + "," + 
	    report["execTimeBest"] + "," + report["latencyBest"] + "," + report["fmax"] + "\n";
	}
	println(results);
}