############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
############################################################
open_project vitishls
set_top edge_detect
add_files src/common.c
add_files src/common.h
add_files src/config.h
add_files src/edge_detect_tasks_v0.c
open_solution "solution1" -flow_target vitis
set_part {xcvc1902-vsva2197-2MP-e-S}
create_clock -period 5 -name default
config_interface -m_axi_alignment_byte_size 64 -m_axi_latency 64 -m_axi_max_widen_bitwidth 512
config_rtl -register_reset_num 3
#source "./vitishls/solution1/directives.tcl"
#csim_design
csynth_design
#cosim_design
export_design -format ip_catalog
