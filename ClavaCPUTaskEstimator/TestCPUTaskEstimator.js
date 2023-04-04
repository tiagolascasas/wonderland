laraImport("weaver.Query");
laraImport("lara.Platforms");
laraImport("CPUTaskEstimator");

function main() {
	Platforms.setLinux()
    const calls = [];

    for (const call of Query.search("call")) {
        calls.push(call);
    }

    const estim = new CPUTaskEstimator("results");
    estim.fromTaskList(calls);
}

main();