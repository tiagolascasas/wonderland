#!/usr/bin/env python3
import sys
import re

input = "perf-flat.txt" if len(sys.argv) < 2 else sys.argv[1]
output = input.replace(".txt", ".dot") if len(sys.argv) < 3 else sys.argv[2]

valid_line = re.compile(r"^(\d{1,3}(?:\.\d{1,2}))% ([_\w]+[_\w\W;]*)")

functions = {}
edges = []

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
                if edges.count((pair[0], pair[1])) == 0:
                    edges.append((pair[0], pair[1]))

with open(output, "w") as file:
    file.write("digraph G {\n")
    file.write("  rankdir=LR;\n")
    file.write("  node [shape=box];\n")

    for fun, percent in functions.items():
        file.write(f'  "{fun}" [label="{fun} ({percent:.2f}%)"];\n')

    for edge in edges:
        file.write(f'  "{edge[0]}" -> "{edge[1]}";\n')

    file.write("}\n")
