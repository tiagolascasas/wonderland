#!/usr/bin/env python3
import re
import argparse


def main():
    args = parse_args()

    input = args.input
    output = args.output
    filter_kernel = args.filter
    print(f"Input: {input}, Output: {output}, Filter: {filter_kernel}")

    functions, edges = build_graph(input, filter_kernel)
    generate_dotfile(functions, edges, output)


def parse_args():
    parser = argparse.ArgumentParser(
        description="Convert perf call graph to Dotfile format."
    )
    parser.add_argument(
        "input",
        type=str,
        nargs="?",
        default="folded_callgraph.txt",
        help="Input file containing the perf call graph.",
    )
    parser.add_argument(
        "output",
        type=str,
        nargs="?",
        default="folded_callgraph.dot",
        help="Output file for the Dotfile.",
    )
    parser.add_argument(
        "-f",
        "--filter",
        action="store_true",
        help="Filter out calls to kernel functions and unnamed functions.",
    )
    args = parser.parse_args()
    return args


def is_kernel_function(name):
    return name.startswith(("__", "_IO", "0x"))


def build_graph(input, filter_kernel):
    functions = {}
    edges = []

    valid_line = re.compile(r"^(\d{1,3}(?:\.\d{1,2}))% ([_\w]+[_\w\W;]*)")
    with open(input, "r") as file:
        for line in file:
            line = line.strip()
            match = valid_line.match(line)
            if match:
                percentage, fun_chain = match.groups()
                discrete_funs = fun_chain.split(";")
                n_percent = float(percentage)

                leaf = discrete_funs[-1]
                if leaf not in functions:
                    functions[leaf] = n_percent
                else:
                    functions[leaf] += n_percent

                pairs = [
                    [discrete_funs[i], discrete_funs[i + 1]]
                    for i in range(len(discrete_funs) - 1)
                ]
                for pair in pairs:
                    if filter_kernel:
                        if is_kernel_function(pair[0]):
                            continue

                    if edges.count((pair[0], pair[1])) == 0:
                        edges.append((pair[0], pair[1]))
    return functions, edges


def generate_dotfile(functions, edges, output):
    with open(output, "w") as file:
        file.write("digraph G {\n")
        file.write("  rankdir=LR;\n")
        file.write("  node [shape=box];\n")

        for fun, percent in functions.items():
            file.write(f'  "{fun}" [label="{fun} ({percent:.2f}%)"];\n')

        for edge in edges:
            file.write(f'  "{edge[0]}" -> "{edge[1]}";\n')

        file.write("}\n")


if __name__ == "__main__":
    main()
