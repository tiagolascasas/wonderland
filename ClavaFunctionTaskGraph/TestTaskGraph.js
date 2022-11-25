laraImport("weaver.Query");
laraImport("FunctionTaskGraphPrototype");
laraImport("TaskGraphVitisAnnotator");

function main() {
    const blacklist = ["abs", "floor", "output_dsp", "printf", "checksum", "input_dsp"];
    const graph = new FunctionTaskGraphPrototype(blacklist);

    TaskGraphVitisAnnotator.annotate(graph);

    const dot = graph.toDot(true);
    println(dot);
}

main();