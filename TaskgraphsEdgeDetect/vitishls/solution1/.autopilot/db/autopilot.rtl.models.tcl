set SynModuleInfo {
  {SRCNAME rgbToGrayscale_Pipeline_VITIS_LOOP_165_1_VITIS_LOOP_167_2 MODELNAME rgbToGrayscale_Pipeline_VITIS_LOOP_165_1_VITIS_LOOP_167_2 RTLNAME rgbToGrayscale_rgbToGrayscale_Pipeline_VITIS_LOOP_165_1_VITIS_LOOP_167_2
    SUBMODULES {
      {MODELNAME rgbToGrayscale_fptrunc_64ns_32_1_no_dsp_1 RTLNAME rgbToGrayscale_fptrunc_64ns_32_1_no_dsp_1 BINDTYPE op TYPE fptrunc IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME rgbToGrayscale_fpext_32ns_64_1_no_dsp_1 RTLNAME rgbToGrayscale_fpext_32ns_64_1_no_dsp_1 BINDTYPE op TYPE fpext IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME rgbToGrayscale_dadd_64ns_64ns_64_5_no_dsp_1 RTLNAME rgbToGrayscale_dadd_64ns_64ns_64_5_no_dsp_1 BINDTYPE op TYPE dadd IMPL fabric LATENCY 4 ALLOW_PRAGMA 1}
      {MODELNAME rgbToGrayscale_dmul_64ns_64ns_64_4_med_dsp_1 RTLNAME rgbToGrayscale_dmul_64ns_64ns_64_4_med_dsp_1 BINDTYPE op TYPE dmul IMPL meddsp LATENCY 3 ALLOW_PRAGMA 1}
      {MODELNAME rgbToGrayscale_sitodp_32ns_64_4_no_dsp_1 RTLNAME rgbToGrayscale_sitodp_32ns_64_4_no_dsp_1 BINDTYPE op TYPE sitodp IMPL auto LATENCY 3 ALLOW_PRAGMA 1}
      {MODELNAME rgbToGrayscale_rgbToGrayscale_Pipeline_VITIS_LOOP_165_1_VITIS_LOOP_167_2_mask_table_ROM_AUTObkb RTLNAME rgbToGrayscale_rgbToGrayscale_Pipeline_VITIS_LOOP_165_1_VITIS_LOOP_167_2_mask_table_ROM_AUTObkb BINDTYPE storage TYPE rom IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME rgbToGrayscale_flow_control_loop_pipe_sequential_init RTLNAME rgbToGrayscale_flow_control_loop_pipe_sequential_init BINDTYPE interface TYPE internal_upc_flow_control INSTNAME rgbToGrayscale_flow_control_loop_pipe_sequential_init_U}
    }
  }
  {SRCNAME rgbToGrayscale MODELNAME rgbToGrayscale RTLNAME rgbToGrayscale IS_TOP 1
    SUBMODULES {
      {MODELNAME rgbToGrayscale_gmem_m_axi RTLNAME rgbToGrayscale_gmem_m_axi BINDTYPE interface TYPE adapter IMPL m_axi}
      {MODELNAME rgbToGrayscale_control_s_axi RTLNAME rgbToGrayscale_control_s_axi BINDTYPE interface TYPE interface_s_axilite}
    }
  }
}
