set moduleName kNN_Predict_4_Pipeline_VITIS_LOOP_17_115
set isTopModule 0
set isCombinational 0
set isDatapathOnly 0
set isPipelined 1
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set hasInterrupt 0
set C_modelName {kNN_Predict_4_Pipeline_VITIS_LOOP_17_115}
set C_modelType { void 0 }
set C_modelArgList {
	{ bestDistances_3_82 double 64 regular  }
	{ bestDistances_3_83 double 64 regular  }
	{ bestDistances_3_84 double 64 regular  }
	{ bestDistances_3_85 double 64 regular  }
	{ bestDistances_3_86 double 64 regular  }
	{ bestDistances_3_87 double 64 regular  }
	{ bestDistances_3_88 double 64 regular  }
	{ bestDistances_3_89 double 64 regular  }
	{ bestDistances_3_90 double 64 regular  }
	{ bestDistances_3_91 double 64 regular  }
	{ bestDistances_3_92 double 64 regular  }
	{ bestDistances_3_93 double 64 regular  }
	{ bestDistances_3_94 double 64 regular  }
	{ bestDistances_3_95 double 64 regular  }
	{ bestDistances_3_96 double 64 regular  }
	{ bestDistances_3_97 double 64 regular  }
	{ bestDistances_3_98 double 64 regular  }
	{ bestDistances_3_99 double 64 regular  }
	{ bestDistances_3_100 double 64 regular  }
	{ bestDistances_3_101 double 64 regular  }
	{ secondWorstOfBest_42_out double 64 regular {pointer 1}  }
	{ worstOfBestIdx_28_out int 5 regular {pointer 1}  }
	{ worstOfBest_28_out double 64 regular {pointer 1}  }
}
set C_modelArgMapList {[ 
	{ "Name" : "bestDistances_3_82", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_3_83", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_3_84", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_3_85", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_3_86", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_3_87", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_3_88", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_3_89", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_3_90", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_3_91", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_3_92", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_3_93", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_3_94", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_3_95", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_3_96", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_3_97", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_3_98", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_3_99", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_3_100", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_3_101", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "secondWorstOfBest_42_out", "interface" : "wire", "bitwidth" : 64, "direction" : "WRITEONLY"} , 
 	{ "Name" : "worstOfBestIdx_28_out", "interface" : "wire", "bitwidth" : 5, "direction" : "WRITEONLY"} , 
 	{ "Name" : "worstOfBest_28_out", "interface" : "wire", "bitwidth" : 64, "direction" : "WRITEONLY"} ]}
# RTL Port declarations: 
set portNum 42
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ bestDistances_3_82 sc_in sc_lv 64 signal 0 } 
	{ bestDistances_3_83 sc_in sc_lv 64 signal 1 } 
	{ bestDistances_3_84 sc_in sc_lv 64 signal 2 } 
	{ bestDistances_3_85 sc_in sc_lv 64 signal 3 } 
	{ bestDistances_3_86 sc_in sc_lv 64 signal 4 } 
	{ bestDistances_3_87 sc_in sc_lv 64 signal 5 } 
	{ bestDistances_3_88 sc_in sc_lv 64 signal 6 } 
	{ bestDistances_3_89 sc_in sc_lv 64 signal 7 } 
	{ bestDistances_3_90 sc_in sc_lv 64 signal 8 } 
	{ bestDistances_3_91 sc_in sc_lv 64 signal 9 } 
	{ bestDistances_3_92 sc_in sc_lv 64 signal 10 } 
	{ bestDistances_3_93 sc_in sc_lv 64 signal 11 } 
	{ bestDistances_3_94 sc_in sc_lv 64 signal 12 } 
	{ bestDistances_3_95 sc_in sc_lv 64 signal 13 } 
	{ bestDistances_3_96 sc_in sc_lv 64 signal 14 } 
	{ bestDistances_3_97 sc_in sc_lv 64 signal 15 } 
	{ bestDistances_3_98 sc_in sc_lv 64 signal 16 } 
	{ bestDistances_3_99 sc_in sc_lv 64 signal 17 } 
	{ bestDistances_3_100 sc_in sc_lv 64 signal 18 } 
	{ bestDistances_3_101 sc_in sc_lv 64 signal 19 } 
	{ secondWorstOfBest_42_out sc_out sc_lv 64 signal 20 } 
	{ secondWorstOfBest_42_out_ap_vld sc_out sc_logic 1 outvld 20 } 
	{ worstOfBestIdx_28_out sc_out sc_lv 5 signal 21 } 
	{ worstOfBestIdx_28_out_ap_vld sc_out sc_logic 1 outvld 21 } 
	{ worstOfBest_28_out sc_out sc_lv 64 signal 22 } 
	{ worstOfBest_28_out_ap_vld sc_out sc_logic 1 outvld 22 } 
	{ grp_fu_75624_p_din0 sc_out sc_lv 64 signal -1 } 
	{ grp_fu_75624_p_din1 sc_out sc_lv 64 signal -1 } 
	{ grp_fu_75624_p_opcode sc_out sc_lv 5 signal -1 } 
	{ grp_fu_75624_p_dout0 sc_in sc_lv 1 signal -1 } 
	{ grp_fu_75624_p_ce sc_out sc_logic 1 signal -1 } 
	{ grp_fu_75628_p_din0 sc_out sc_lv 64 signal -1 } 
	{ grp_fu_75628_p_din1 sc_out sc_lv 64 signal -1 } 
	{ grp_fu_75628_p_opcode sc_out sc_lv 5 signal -1 } 
	{ grp_fu_75628_p_dout0 sc_in sc_lv 1 signal -1 } 
	{ grp_fu_75628_p_ce sc_out sc_logic 1 signal -1 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "bestDistances_3_82", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_3_82", "role": "default" }} , 
 	{ "name": "bestDistances_3_83", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_3_83", "role": "default" }} , 
 	{ "name": "bestDistances_3_84", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_3_84", "role": "default" }} , 
 	{ "name": "bestDistances_3_85", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_3_85", "role": "default" }} , 
 	{ "name": "bestDistances_3_86", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_3_86", "role": "default" }} , 
 	{ "name": "bestDistances_3_87", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_3_87", "role": "default" }} , 
 	{ "name": "bestDistances_3_88", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_3_88", "role": "default" }} , 
 	{ "name": "bestDistances_3_89", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_3_89", "role": "default" }} , 
 	{ "name": "bestDistances_3_90", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_3_90", "role": "default" }} , 
 	{ "name": "bestDistances_3_91", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_3_91", "role": "default" }} , 
 	{ "name": "bestDistances_3_92", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_3_92", "role": "default" }} , 
 	{ "name": "bestDistances_3_93", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_3_93", "role": "default" }} , 
 	{ "name": "bestDistances_3_94", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_3_94", "role": "default" }} , 
 	{ "name": "bestDistances_3_95", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_3_95", "role": "default" }} , 
 	{ "name": "bestDistances_3_96", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_3_96", "role": "default" }} , 
 	{ "name": "bestDistances_3_97", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_3_97", "role": "default" }} , 
 	{ "name": "bestDistances_3_98", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_3_98", "role": "default" }} , 
 	{ "name": "bestDistances_3_99", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_3_99", "role": "default" }} , 
 	{ "name": "bestDistances_3_100", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_3_100", "role": "default" }} , 
 	{ "name": "bestDistances_3_101", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_3_101", "role": "default" }} , 
 	{ "name": "secondWorstOfBest_42_out", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "secondWorstOfBest_42_out", "role": "default" }} , 
 	{ "name": "secondWorstOfBest_42_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "secondWorstOfBest_42_out", "role": "ap_vld" }} , 
 	{ "name": "worstOfBestIdx_28_out", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "worstOfBestIdx_28_out", "role": "default" }} , 
 	{ "name": "worstOfBestIdx_28_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "worstOfBestIdx_28_out", "role": "ap_vld" }} , 
 	{ "name": "worstOfBest_28_out", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "worstOfBest_28_out", "role": "default" }} , 
 	{ "name": "worstOfBest_28_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "worstOfBest_28_out", "role": "ap_vld" }} , 
 	{ "name": "grp_fu_75624_p_din0", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "grp_fu_75624_p_din0", "role": "default" }} , 
 	{ "name": "grp_fu_75624_p_din1", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "grp_fu_75624_p_din1", "role": "default" }} , 
 	{ "name": "grp_fu_75624_p_opcode", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "grp_fu_75624_p_opcode", "role": "default" }} , 
 	{ "name": "grp_fu_75624_p_dout0", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "grp_fu_75624_p_dout0", "role": "default" }} , 
 	{ "name": "grp_fu_75624_p_ce", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "grp_fu_75624_p_ce", "role": "default" }} , 
 	{ "name": "grp_fu_75628_p_din0", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "grp_fu_75628_p_din0", "role": "default" }} , 
 	{ "name": "grp_fu_75628_p_din1", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "grp_fu_75628_p_din1", "role": "default" }} , 
 	{ "name": "grp_fu_75628_p_opcode", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "grp_fu_75628_p_opcode", "role": "default" }} , 
 	{ "name": "grp_fu_75628_p_dout0", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "grp_fu_75628_p_dout0", "role": "default" }} , 
 	{ "name": "grp_fu_75628_p_ce", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "grp_fu_75628_p_ce", "role": "default" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2"],
		"CDFG" : "kNN_Predict_4_Pipeline_VITIS_LOOP_17_115",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "23", "EstimateLatencyMax" : "23",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"IsBlackBox" : "0",
		"Port" : [
			{"Name" : "bestDistances_3_82", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_3_83", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_3_84", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_3_85", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_3_86", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_3_87", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_3_88", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_3_89", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_3_90", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_3_91", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_3_92", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_3_93", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_3_94", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_3_95", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_3_96", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_3_97", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_3_98", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_3_99", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_3_100", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_3_101", "Type" : "None", "Direction" : "I"},
			{"Name" : "secondWorstOfBest_42_out", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "worstOfBestIdx_28_out", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "worstOfBest_28_out", "Type" : "Vld", "Direction" : "O"}],
		"Loop" : [
			{"Name" : "VITIS_LOOP_17_1", "PipelineType" : "UPC",
				"LoopDec" : {"FSMBitwidth" : "1", "FirstState" : "ap_ST_fsm_pp0_stage0", "FirstStateIter" : "ap_enable_reg_pp0_iter1", "FirstStateBlock" : "ap_block_pp0_stage0_subdone", "LastState" : "ap_ST_fsm_pp0_stage0", "LastStateIter" : "ap_enable_reg_pp0_iter2", "LastStateBlock" : "ap_block_pp0_stage0_subdone", "QuitState" : "ap_ST_fsm_pp0_stage0", "QuitStateIter" : "ap_enable_reg_pp0_iter2", "QuitStateBlock" : "ap_block_pp0_stage0_subdone", "OneDepthLoop" : "0", "has_ap_ctrl" : "1", "has_continue" : "0"}}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mux_205_64_1_1_U417", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.flow_control_loop_pipe_sequential_init_U", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	kNN_Predict_4_Pipeline_VITIS_LOOP_17_115 {
		bestDistances_3_82 {Type I LastRead 0 FirstWrite -1}
		bestDistances_3_83 {Type I LastRead 0 FirstWrite -1}
		bestDistances_3_84 {Type I LastRead 0 FirstWrite -1}
		bestDistances_3_85 {Type I LastRead 0 FirstWrite -1}
		bestDistances_3_86 {Type I LastRead 0 FirstWrite -1}
		bestDistances_3_87 {Type I LastRead 0 FirstWrite -1}
		bestDistances_3_88 {Type I LastRead 0 FirstWrite -1}
		bestDistances_3_89 {Type I LastRead 0 FirstWrite -1}
		bestDistances_3_90 {Type I LastRead 0 FirstWrite -1}
		bestDistances_3_91 {Type I LastRead 0 FirstWrite -1}
		bestDistances_3_92 {Type I LastRead 0 FirstWrite -1}
		bestDistances_3_93 {Type I LastRead 0 FirstWrite -1}
		bestDistances_3_94 {Type I LastRead 0 FirstWrite -1}
		bestDistances_3_95 {Type I LastRead 0 FirstWrite -1}
		bestDistances_3_96 {Type I LastRead 0 FirstWrite -1}
		bestDistances_3_97 {Type I LastRead 0 FirstWrite -1}
		bestDistances_3_98 {Type I LastRead 0 FirstWrite -1}
		bestDistances_3_99 {Type I LastRead 0 FirstWrite -1}
		bestDistances_3_100 {Type I LastRead 0 FirstWrite -1}
		bestDistances_3_101 {Type I LastRead 0 FirstWrite -1}
		secondWorstOfBest_42_out {Type O LastRead -1 FirstWrite 2}
		worstOfBestIdx_28_out {Type O LastRead -1 FirstWrite 2}
		worstOfBest_28_out {Type O LastRead -1 FirstWrite 2}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "23", "Max" : "23"}
	, {"Name" : "Interval", "Min" : "23", "Max" : "23"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
]}

set Spec2ImplPortList { 
	bestDistances_3_82 { ap_none {  { bestDistances_3_82 in_data 0 64 } } }
	bestDistances_3_83 { ap_none {  { bestDistances_3_83 in_data 0 64 } } }
	bestDistances_3_84 { ap_none {  { bestDistances_3_84 in_data 0 64 } } }
	bestDistances_3_85 { ap_none {  { bestDistances_3_85 in_data 0 64 } } }
	bestDistances_3_86 { ap_none {  { bestDistances_3_86 in_data 0 64 } } }
	bestDistances_3_87 { ap_none {  { bestDistances_3_87 in_data 0 64 } } }
	bestDistances_3_88 { ap_none {  { bestDistances_3_88 in_data 0 64 } } }
	bestDistances_3_89 { ap_none {  { bestDistances_3_89 in_data 0 64 } } }
	bestDistances_3_90 { ap_none {  { bestDistances_3_90 in_data 0 64 } } }
	bestDistances_3_91 { ap_none {  { bestDistances_3_91 in_data 0 64 } } }
	bestDistances_3_92 { ap_none {  { bestDistances_3_92 in_data 0 64 } } }
	bestDistances_3_93 { ap_none {  { bestDistances_3_93 in_data 0 64 } } }
	bestDistances_3_94 { ap_none {  { bestDistances_3_94 in_data 0 64 } } }
	bestDistances_3_95 { ap_none {  { bestDistances_3_95 in_data 0 64 } } }
	bestDistances_3_96 { ap_none {  { bestDistances_3_96 in_data 0 64 } } }
	bestDistances_3_97 { ap_none {  { bestDistances_3_97 in_data 0 64 } } }
	bestDistances_3_98 { ap_none {  { bestDistances_3_98 in_data 0 64 } } }
	bestDistances_3_99 { ap_none {  { bestDistances_3_99 in_data 0 64 } } }
	bestDistances_3_100 { ap_none {  { bestDistances_3_100 in_data 0 64 } } }
	bestDistances_3_101 { ap_none {  { bestDistances_3_101 in_data 0 64 } } }
	secondWorstOfBest_42_out { ap_vld {  { secondWorstOfBest_42_out out_data 1 64 }  { secondWorstOfBest_42_out_ap_vld out_vld 1 1 } } }
	worstOfBestIdx_28_out { ap_vld {  { worstOfBestIdx_28_out out_data 1 5 }  { worstOfBestIdx_28_out_ap_vld out_vld 1 1 } } }
	worstOfBest_28_out { ap_vld {  { worstOfBest_28_out out_data 1 64 }  { worstOfBest_28_out_ap_vld out_vld 1 1 } } }
}
