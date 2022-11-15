############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
############################################################
open_project VitisEdgeDetect
add_files VitisEdgeDetect/src/edge_detect_tasks.c
open_solution "solution1" -flow_target vivado
set_part {xcvu5p-flva2104-1-e}
create_clock -period 10 -name default
#source "./VitisEdgeDetect/solution1/directives.tcl"
#csim_design
csynth_design
#cosim_design
export_design -format ip_catalog
