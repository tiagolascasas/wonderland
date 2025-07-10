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
    valid_functions = set()
    edges = {}

    pattern_1 = re.compile(r"^(\d{1,3}(?:\.\d{1,2}))% ([_\w]+[_\w\W;]*)")
    pattern_2 = re.compile(r"^(\d{1,3}(?:\.\d{1,2}))%.*\[\.\]\s([\w_]+)")
    with open(input, "r") as file:
        for line in file:
            line = line.strip()
            match = pattern_1.match(line)
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
                    source, target = pair
                    if filter_kernel and is_kernel_function(source):
                        continue
                    if source not in edges:
                        edges[source] = set()
                        edges[source].add(target)
                        valid_functions.add(source)
                    else:
                        edges[source].add(target)
                    valid_functions.add(target)
            else:
                match = pattern_2.match(line)
                if match:
                    percentage, fun = match.groups()
                    n_percent = float(percentage)
                    if filter_kernel and is_kernel_function(fun):
                        continue
                    if fun not in functions:
                        functions[fun] = n_percent
                    else:
                        functions[fun] += n_percent
                    valid_functions.add(fun)

    # functions = {k: v for k, v in functions.items() if k in valid_functions}
    return functions, edges


def generate_dotfile(functions, edges, output):
    with open(output, "w") as file:
        file.write("digraph G {\n")
        file.write("  rankdir=LR;\n")
        file.write("  node [shape=box];\n")

        fun_stack = set()
        fun_stack.add("main")
        while len(fun_stack) > 0:
            fun = fun_stack.pop()
            if fun not in functions:
                file.write(f'  "{fun}" [label="{fun}\n(??.??%)"];\n')
            else:
                file.write(f'  "{fun}" [label="{fun}\n({functions[fun]:.2f}%)"];\n')
            if fun in edges:
                for target in edges[fun]:
                    file.write(f'  "{fun}" -> "{target}";\n')
                    fun_stack.add(target)

        file.write("}\n")


if __name__ == "__main__":
    main()
