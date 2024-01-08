# Experiments

A monorepo for all my small experiments and scripts that don't really warrant their own repository. Some highlights that may be of use to someone are:

* **CommunicationLatencyModel** - generates a linear model for communication between a CPU and an FPGA via OpenCL, from real data. Takes in a CSV of measurements, does a linear regression and outputs a JavaScript class capable of estimating the communication cost of any input size.

* **CPLEXBaselinePartitioningModel** - an ILP formulation of the Hardware/Software partitioning problem using IBM CPLEX.

* **ImageToArray** - a Python script that takes in an image and converts it to a C array (a comma-separated list of bytes in decimal, where each byte is a color channel, e.g., a greyscale image would have one number per pixel, while an RGB image would have 3), and vice-versa. Extremely useful if you want to embed an image in an executable.

* **VitisDataflowDirective** - an example-driven exploration of Vitis HLS's dataflow directive.
