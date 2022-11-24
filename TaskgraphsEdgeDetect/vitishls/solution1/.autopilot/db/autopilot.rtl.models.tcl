set SynModuleInfo {
  {SRCNAME edge_detect_Pipeline_VITIS_LOOP_12_2 MODELNAME edge_detect_Pipeline_VITIS_LOOP_12_2 RTLNAME edge_detect_edge_detect_Pipeline_VITIS_LOOP_12_2
    SUBMODULES {
      {MODELNAME edge_detect_fptrunc_64ns_32_1_no_dsp_1 RTLNAME edge_detect_fptrunc_64ns_32_1_no_dsp_1 BINDTYPE op TYPE fptrunc IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME edge_detect_fpext_32ns_64_1_no_dsp_1 RTLNAME edge_detect_fpext_32ns_64_1_no_dsp_1 BINDTYPE op TYPE fpext IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME edge_detect_dadd_64ns_64ns_64_5_no_dsp_1 RTLNAME edge_detect_dadd_64ns_64ns_64_5_no_dsp_1 BINDTYPE op TYPE dadd IMPL fabric LATENCY 4 ALLOW_PRAGMA 1}
      {MODELNAME edge_detect_dmul_64ns_64ns_64_4_med_dsp_1 RTLNAME edge_detect_dmul_64ns_64ns_64_4_med_dsp_1 BINDTYPE op TYPE dmul IMPL meddsp LATENCY 3 ALLOW_PRAGMA 1}
      {MODELNAME edge_detect_sitodp_32ns_64_4_no_dsp_1 RTLNAME edge_detect_sitodp_32ns_64_4_no_dsp_1 BINDTYPE op TYPE sitodp IMPL auto LATENCY 3 ALLOW_PRAGMA 1}
      {MODELNAME edge_detect_edge_detect_Pipeline_VITIS_LOOP_12_2_mask_table_ROM_AUTO_1R RTLNAME edge_detect_edge_detect_Pipeline_VITIS_LOOP_12_2_mask_table_ROM_AUTO_1R BINDTYPE storage TYPE rom IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME edge_detect_flow_control_loop_pipe_sequential_init RTLNAME edge_detect_flow_control_loop_pipe_sequential_init BINDTYPE interface TYPE internal_upc_flow_control INSTNAME edge_detect_flow_control_loop_pipe_sequential_init_U}
    }
  }
  {SRCNAME convolve2d.286.288.290.1_Pipeline_VITIS_LOOP_53_1_VITIS_LOOP_55_2 MODELNAME convolve2d_286_288_290_1_Pipeline_VITIS_LOOP_53_1_VITIS_LOOP_55_2 RTLNAME edge_detect_convolve2d_286_288_290_1_Pipeline_VITIS_LOOP_53_1_VITIS_LOOP_55_2}
  {SRCNAME convolve2d.286.288.290.1_Pipeline_VITIS_LOOP_64_3_VITIS_LOOP_66_4 MODELNAME convolve2d_286_288_290_1_Pipeline_VITIS_LOOP_64_3_VITIS_LOOP_66_4 RTLNAME edge_detect_convolve2d_286_288_290_1_Pipeline_VITIS_LOOP_64_3_VITIS_LOOP_66_4
    SUBMODULES {
      {MODELNAME edge_detect_mul_32s_32s_32_1_1 RTLNAME edge_detect_mul_32s_32s_32_1_1 BINDTYPE op TYPE mul IMPL fabric LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME edge_detect_sdiv_32ns_32ns_32_16_1 RTLNAME edge_detect_sdiv_32ns_32ns_32_16_1 BINDTYPE op TYPE sdiv IMPL vivado_divider LATENCY 15 ALLOW_PRAGMA 1}
    }
  }
  {SRCNAME convolve2d.286.288.290.1 MODELNAME convolve2d_286_288_290_1 RTLNAME edge_detect_convolve2d_286_288_290_1}
  {SRCNAME edge_detect_Pipeline_VITIS_LOOP_88_1_VITIS_LOOP_90_2 MODELNAME edge_detect_Pipeline_VITIS_LOOP_88_1_VITIS_LOOP_90_2 RTLNAME edge_detect_edge_detect_Pipeline_VITIS_LOOP_88_1_VITIS_LOOP_90_2}
  {SRCNAME edge_detect MODELNAME edge_detect RTLNAME edge_detect IS_TOP 1
    SUBMODULES {
      {MODELNAME edge_detect_gmem_m_axi RTLNAME edge_detect_gmem_m_axi BINDTYPE interface TYPE adapter IMPL m_axi}
      {MODELNAME edge_detect_control_s_axi RTLNAME edge_detect_control_s_axi BINDTYPE interface TYPE interface_s_axilite}
    }
  }
}
