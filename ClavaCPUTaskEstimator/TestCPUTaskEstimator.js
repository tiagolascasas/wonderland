laraImport("weaver.Query");
laraImport("CPUTaskEstimator");

function main() {
    const calls = [];

    for (const call of Query.search("call")) {
        calls.push(call);
    }

    const estim = new CPUTaskEstimator("results");
    estim.fromTaskList(calls);
}

main();