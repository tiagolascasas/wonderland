class DotFormatter {
    // Array of objects that contains the properties 'attr' (string) and 'predicate' (function)
    #nodeAttrs;

    // Array of objects that contains the properties 'attr' (string) and 'predicate' (function)
    #edgeAttrs;

    // Map with selected layout options
    #layoutOptions;

    // Function that receives a node and returns the corresponding label. By default, call .toString() over the data
    #nodeLabelFormatter;

    // Function that receives an edge and returns the corresponding label. By default, call .toString() over the data
    #edgeLabelFormatter;


    constructor() {
        this.#nodeAttrs = [];
        this.#edgeAttrs = [];
        this.#layoutOptions = new Map();

        this.#nodeLabelFormatter = (node) => node.data().toString();
        this.#edgeLabelFormatter = (edge) => edge.data().toString();
    }

    static #sanitizeDotLabel(label) {
        return label.replaceAll("\n", "\\l").replaceAll("\r", "");
    }

    addNodeAttribute(attrString, predicate) {
        if (predicate === undefined) {
            predicate = (node) => true;
        }

        this.#nodeAttrs.push({ attr: attrString, predicate: predicate });
    }

    addEdgeAttribute(attrString, predicate) {
        if (predicate === undefined) {
            predicate = (edge) => true;
        }

        this.#edgeAttrs.push({ attr: attrString, predicate: predicate });
    }

    setLayoutOption(option, value) {
        this.#layoutOptions.set(option, value);
    }

    setNodeLabelFormatter(nodeLabelFormatter) {
        this.#nodeLabelFormatter = nodeLabelFormatter;
    }

    setEdgeLabelFormatter(edgeLabelFormatter) {
        this.#edgeLabelFormatter = edgeLabelFormatter;
    }

    getNodeAttributes(node) {
        return this.#nodeAttrs
            .filter((obj) => obj.predicate(node))
            .map((obj) => obj.attr)
            .join(" ");
    }

    getEdgeAttributes(edge) {
        return this.#edgeAttrs
            .filter((obj) => obj.predicate(edge))
            .map((obj) => obj.attr)
            .join(" ");
    }

    getLayoutOptions() {
        let options = [];

        this.#layoutOptions.forEach((option, val) => {
            options.push(`\t${val}="${option}";`);
        });

        return options.join("\n");
    }

    getNodeLabel(node) {
        return DotFormatter.#sanitizeDotLabel(this.#nodeLabelFormatter(node));
    }

    getEdgeLabel(edge) {
        return DotFormatter.#sanitizeDotLabel(this.#edgeLabelFormatter(edge));
    }
}
