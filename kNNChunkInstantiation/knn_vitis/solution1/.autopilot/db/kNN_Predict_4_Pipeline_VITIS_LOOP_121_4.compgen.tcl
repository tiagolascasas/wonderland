# This script segment is generated automatically by AutoPilot

set name kNN_PredictAll_fsub_32ns_32ns_32_4_full_dsp_1
if {${::AESL::PGuard_rtl_comp_handler}} {
	::AP::rtl_comp_handler $name BINDTYPE {op} TYPE {fsub} IMPL {fulldsp} LATENCY 3 ALLOW_PRAGMA 1
}


set name kNN_PredictAll_fpext_32ns_64_2_no_dsp_1
if {${::AESL::PGuard_rtl_comp_handler}} {
	::AP::rtl_comp_handler $name BINDTYPE {op} TYPE {fpext} IMPL {auto} LATENCY 1 ALLOW_PRAGMA 1
}


set name kNN_PredictAll_dadd_64ns_64ns_64_5_full_dsp_1
if {${::AESL::PGuard_rtl_comp_handler}} {
	::AP::rtl_comp_handler $name BINDTYPE {op} TYPE {dadd} IMPL {fulldsp} LATENCY 4 ALLOW_PRAGMA 1
}


set name kNN_PredictAll_dmul_64ns_64ns_64_5_max_dsp_1
if {${::AESL::PGuard_rtl_comp_handler}} {
	::AP::rtl_comp_handler $name BINDTYPE {op} TYPE {dmul} IMPL {maxdsp} LATENCY 4 ALLOW_PRAGMA 1
}


# clear list
if {${::AESL::PGuard_autoexp_gen}} {
    cg_default_interface_gen_dc_begin
    cg_default_interface_gen_bundle_begin
    AESL_LIB_XILADAPTER::native_axis_begin
}

# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 25 \
    name training_X_0 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename training_X_0 \
    op interface \
    ports { training_X_0_address0 { O 16 vector } training_X_0_ce0 { O 1 bit } training_X_0_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'training_X_0'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 26 \
    name training_X_1 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename training_X_1 \
    op interface \
    ports { training_X_1_address0 { O 16 vector } training_X_1_ce0 { O 1 bit } training_X_1_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'training_X_1'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 27 \
    name training_X_2 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename training_X_2 \
    op interface \
    ports { training_X_2_address0 { O 16 vector } training_X_2_ce0 { O 1 bit } training_X_2_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'training_X_2'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 28 \
    name training_X_3 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename training_X_3 \
    op interface \
    ports { training_X_3_address0 { O 16 vector } training_X_3_ce0 { O 1 bit } training_X_3_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'training_X_3'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 30 \
    name testing_X \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename testing_X \
    op interface \
    ports { testing_X_address0 { O 16 vector } testing_X_ce0 { O 1 bit } testing_X_q0 { I 32 vector } testing_X_address1 { O 16 vector } testing_X_ce1 { O 1 bit } testing_X_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'testing_X'"
}
}


# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 24 \
    name mul_ln136 \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_mul_ln136 \
    op interface \
    ports { mul_ln136 { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 29 \
    name mul_ln61 \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_mul_ln61 \
    op interface \
    ports { mul_ln61 { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 31 \
    name mul_ln62 \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_mul_ln62 \
    op interface \
    ports { mul_ln62 { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 32 \
    name mul_ln63 \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_mul_ln63 \
    op interface \
    ports { mul_ln63 { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 33 \
    name mul_ln64 \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_mul_ln64 \
    op interface \
    ports { mul_ln64 { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 34 \
    name distance_q3_t3_out \
    type other \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_distance_q3_t3_out \
    op interface \
    ports { distance_q3_t3_out { O 64 vector } distance_q3_t3_out_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 35 \
    name distance_q3_t2_out \
    type other \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_distance_q3_t2_out \
    op interface \
    ports { distance_q3_t2_out { O 64 vector } distance_q3_t2_out_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 36 \
    name distance_q3_t1_out \
    type other \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_distance_q3_t1_out \
    op interface \
    ports { distance_q3_t1_out { O 64 vector } distance_q3_t1_out_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 37 \
    name distance_q3_t0_out \
    type other \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_distance_q3_t0_out \
    op interface \
    ports { distance_q3_t0_out { O 64 vector } distance_q3_t0_out_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 38 \
    name distance_q2_t3_out \
    type other \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_distance_q2_t3_out \
    op interface \
    ports { distance_q2_t3_out { O 64 vector } distance_q2_t3_out_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 39 \
    name distance_q0_t0_out \
    type other \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_distance_q0_t0_out \
    op interface \
    ports { distance_q0_t0_out { O 64 vector } distance_q0_t0_out_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 40 \
    name distance_q0_t1_out \
    type other \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_distance_q0_t1_out \
    op interface \
    ports { distance_q0_t1_out { O 64 vector } distance_q0_t1_out_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 41 \
    name distance_q0_t2_out \
    type other \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_distance_q0_t2_out \
    op interface \
    ports { distance_q0_t2_out { O 64 vector } distance_q0_t2_out_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 42 \
    name distance_q0_t3_out \
    type other \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_distance_q0_t3_out \
    op interface \
    ports { distance_q0_t3_out { O 64 vector } distance_q0_t3_out_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 43 \
    name distance_q1_t0_out \
    type other \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_distance_q1_t0_out \
    op interface \
    ports { distance_q1_t0_out { O 64 vector } distance_q1_t0_out_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 44 \
    name distance_q1_t1_out \
    type other \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_distance_q1_t1_out \
    op interface \
    ports { distance_q1_t1_out { O 64 vector } distance_q1_t1_out_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 45 \
    name distance_q1_t2_out \
    type other \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_distance_q1_t2_out \
    op interface \
    ports { distance_q1_t2_out { O 64 vector } distance_q1_t2_out_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 46 \
    name distance_q1_t3_out \
    type other \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_distance_q1_t3_out \
    op interface \
    ports { distance_q1_t3_out { O 64 vector } distance_q1_t3_out_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 47 \
    name distance_q2_t0_out \
    type other \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_distance_q2_t0_out \
    op interface \
    ports { distance_q2_t0_out { O 64 vector } distance_q2_t0_out_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 48 \
    name distance_q2_t1_out \
    type other \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_distance_q2_t1_out \
    op interface \
    ports { distance_q2_t1_out { O 64 vector } distance_q2_t1_out_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 49 \
    name distance_q2_t2_out \
    type other \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_distance_q2_t2_out \
    op interface \
    ports { distance_q2_t2_out { O 64 vector } distance_q2_t2_out_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id -1 \
    name ap_ctrl \
    type ap_ctrl \
    reset_level 1 \
    sync_rst true \
    corename ap_ctrl \
    op interface \
    ports { ap_start { I 1 bit } ap_ready { O 1 bit } ap_done { O 1 bit } ap_idle { O 1 bit } } \
} "
}


# Adapter definition:
set PortName ap_clk
set DataWd 1 
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc cg_default_interface_gen_clock] == "cg_default_interface_gen_clock"} {
eval "cg_default_interface_gen_clock { \
    id -2 \
    name ${PortName} \
    reset_level 1 \
    sync_rst true \
    corename apif_ap_clk \
    data_wd ${DataWd} \
    op interface \
}"
} else {
puts "@W \[IMPL-113\] Cannot find bus interface model in the library. Ignored generation of bus interface for '${PortName}'"
}
}


# Adapter definition:
set PortName ap_rst
set DataWd 1 
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc cg_default_interface_gen_reset] == "cg_default_interface_gen_reset"} {
eval "cg_default_interface_gen_reset { \
    id -3 \
    name ${PortName} \
    reset_level 1 \
    sync_rst true \
    corename apif_ap_rst \
    data_wd ${DataWd} \
    op interface \
}"
} else {
puts "@W \[IMPL-114\] Cannot find bus interface model in the library. Ignored generation of bus interface for '${PortName}'"
}
}



# merge
if {${::AESL::PGuard_autoexp_gen}} {
    cg_default_interface_gen_dc_end
    cg_default_interface_gen_bundle_end
    AESL_LIB_XILADAPTER::native_axis_end
}


# flow_control definition:
set InstName kNN_PredictAll_flow_control_loop_pipe_sequential_init_U
set CompName kNN_PredictAll_flow_control_loop_pipe_sequential_init
set name flow_control_loop_pipe_sequential_init
if {${::AESL::PGuard_autocg_gen} && ${::AESL::PGuard_autocg_ipmgen}} {
if {[info proc ::AESL_LIB_VIRTEX::xil_gen_UPC_flow_control] == "::AESL_LIB_VIRTEX::xil_gen_UPC_flow_control"} {
eval "::AESL_LIB_VIRTEX::xil_gen_UPC_flow_control { \
    name ${name} \
    prefix kNN_PredictAll_ \
}"
} else {
puts "@W \[IMPL-107\] Cannot find ::AESL_LIB_VIRTEX::xil_gen_UPC_flow_control, check your platform lib"
}
}


if {${::AESL::PGuard_rtl_comp_handler}} {
	::AP::rtl_comp_handler $CompName BINDTYPE interface TYPE internal_upc_flow_control INSTNAME $InstName
}


