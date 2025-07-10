#### perf2csv \<input> \<output>

Converts a call graph obtained from perf into a CSV with the % of time spent on each function.

The call graph format should be full, obtained, e.g., with the command:

```bash
perf report --stdio --sort symbol --percent-limit 0 > full_callgraph.txt
```

See "full_callgraph.txt" file for an example

#### perf2dotfile \<input> \<output> -f

Converts a call graph obtained from perf into a Dotfile, ready to be rendered by Graphviz

`-f` filters out calls to kernel functions and unnamed functions

The call graph format should be folded, obtained, e.g., with the command:

```bash
sudo perf report --stdio --call-graph=folded > folded_callgraph.txt
```

See "folded_callgraph.txt" for an example
