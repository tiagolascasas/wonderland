############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
############################################################
open_project edge_detect_vitishls
set_top rgbToGrayscale
add_files edge_detect_tasks_V0.c
open_solution "solution1" -flow_target vitis
set_part {xcvc1902-vsva2197-2MP-e-S}
create_clock -period 5 -name default
#source "./edge_detect_vitishls/solution1/directives.tcl"
#csim_design
csynth_design
#cosim_design
export_design -format ip_catalog
