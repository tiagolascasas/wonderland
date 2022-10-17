############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
############################################################
open_project VitisClavaAutomation
set_top maddv
add_files VitisClavaAutomation/src/example.c
open_solution "solution1" -flow_target vivado
set_part {xcvu5p-flva2104-1-e}
create_clock -period 10 -name default
#source "./VitisClavaAutomation/solution1/directives.tcl"
#csim_design
csynth_design
#cosim_design
export_design -format ip_catalog
