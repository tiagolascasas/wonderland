############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
############################################################
open_project knn_vitis
set_top kNN_PredictAll
add_files knn/design_params.h
add_files knn/knn.cpp
add_files knn/knn.h
add_files knn/knn_2.cpp
add_files knn/knn_2.h
add_files knn/knn_4.cpp
add_files knn/knn_4.h
add_files knn/knn_6.cpp
add_files knn/knn_6.h
add_files knn/knn_8.cpp
add_files knn/knn_8.h
add_files knn/scenarios.h
open_solution "solution1" -flow_target vivado
set_part {xczu9eg-ffvb1156-2-e}
create_clock -period 10 -name default
source "./knn_vitis/solution1/directives.tcl"
#csim_design
csynth_design
#cosim_design
export_design -format ip_catalog
