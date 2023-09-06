set moduleName kNN_Predict_4_Pipeline_VITIS_LOOP_17_13
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
set C_modelName {kNN_Predict_4_Pipeline_VITIS_LOOP_17_13}
set C_modelType { void 0 }
set C_modelArgList {
	{ bestDistances_0_82 double 64 regular  }
	{ bestDistances_0_83 double 64 regular  }
	{ bestDistances_0_84 double 64 regular  }
	{ bestDistances_0_85 double 64 regular  }
	{ bestDistances_0_86 double 64 regular  }
	{ bestDistances_0_87 double 64 regular  }
	{ bestDistances_0_88 double 64 regular  }
	{ bestDistances_0_89 double 64 regular  }
	{ bestDistances_0_90 double 64 regular  }
	{ bestDistances_0_91 double 64 regular  }
	{ bestDistances_0_92 double 64 regular  }
	{ bestDistances_0_93 double 64 regular  }
	{ bestDistances_0_94 double 64 regular  }
	{ bestDistances_0_95 double 64 regular  }
	{ bestDistances_0_96 double 64 regular  }
	{ bestDistances_0_97 double 64 regular  }
	{ bestDistances_0_98 double 64 regular  }
	{ bestDistances_0_99 double 64 regular  }
	{ bestDistances_0_100 double 64 regular  }
	{ bestDistances_0_101 double 64 regular  }
	{ secondWorstOfBest_6_out double 64 regular {pointer 1}  }
	{ worstOfBestIdx_4_out int 5 regular {pointer 1}  }
	{ worstOfBest_4_out double 64 regular {pointer 1}  }
}
set C_modelArgMapList {[ 
	{ "Name" : "bestDistances_0_82", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_0_83", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_0_84", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_0_85", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_0_86", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_0_87", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_0_88", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_0_89", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_0_90", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_0_91", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_0_92", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_0_93", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_0_94", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_0_95", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_0_96", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_0_97", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_0_98", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_0_99", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_0_100", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_0_101", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "secondWorstOfBest_6_out", "interface" : "wire", "bitwidth" : 64, "direction" : "WRITEONLY"} , 
 	{ "Name" : "worstOfBestIdx_4_out", "interface" : "wire", "bitwidth" : 5, "direction" : "WRITEONLY"} , 
 	{ "Name" : "worstOfBest_4_out", "interface" : "wire", "bitwidth" : 64, "direction" : "WRITEONLY"} ]}
# RTL Port declarations: 
set portNum 42
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ bestDistances_0_82 sc_in sc_lv 64 signal 0 } 
	{ bestDistances_0_83 sc_in sc_lv 64 signal 1 } 
	{ bestDistances_0_84 sc_in sc_lv 64 signal 2 } 
	{ bestDistances_0_85 sc_in sc_lv 64 signal 3 } 
	{ bestDistances_0_86 sc_in sc_lv 64 signal 4 } 
	{ bestDistances_0_87 sc_in sc_lv 64 signal 5 } 
	{ bestDistances_0_88 sc_in sc_lv 64 signal 6 } 
	{ bestDistances_0_89 sc_in sc_lv 64 signal 7 } 
	{ bestDistances_0_90 sc_in sc_lv 64 signal 8 } 
	{ bestDistances_0_91 sc_in sc_lv 64 signal 9 } 
	{ bestDistances_0_92 sc_in sc_lv 64 signal 10 } 
	{ bestDistances_0_93 sc_in sc_lv 64 signal 11 } 
	{ bestDistances_0_94 sc_in sc_lv 64 signal 12 } 
	{ bestDistances_0_95 sc_in sc_lv 64 signal 13 } 
	{ bestDistances_0_96 sc_in sc_lv 64 signal 14 } 
	{ bestDistances_0_97 sc_in sc_lv 64 signal 15 } 
	{ bestDistances_0_98 sc_in sc_lv 64 signal 16 } 
	{ bestDistances_0_99 sc_in sc_lv 64 signal 17 } 
	{ bestDistances_0_100 sc_in sc_lv 64 signal 18 } 
	{ bestDistances_0_101 sc_in sc_lv 64 signal 19 } 
	{ secondWorstOfBest_6_out sc_out sc_lv 64 signal 20 } 
	{ secondWorstOfBest_6_out_ap_vld sc_out sc_logic 1 outvld 20 } 
	{ worstOfBestIdx_4_out sc_out sc_lv 5 signal 21 } 
	{ worstOfBestIdx_4_out_ap_vld sc_out sc_logic 1 outvld 21 } 
	{ worstOfBest_4_out sc_out sc_lv 64 signal 22 } 
	{ worstOfBest_4_out_ap_vld sc_out sc_logic 1 outvld 22 } 
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
 	{ "name": "bestDistances_0_82", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_0_82", "role": "default" }} , 
 	{ "name": "bestDistances_0_83", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_0_83", "role": "default" }} , 
 	{ "name": "bestDistances_0_84", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_0_84", "role": "default" }} , 
 	{ "name": "bestDistances_0_85", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_0_85", "role": "default" }} , 
 	{ "name": "bestDistances_0_86", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_0_86", "role": "default" }} , 
 	{ "name": "bestDistances_0_87", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_0_87", "role": "default" }} , 
 	{ "name": "bestDistances_0_88", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_0_88", "role": "default" }} , 
 	{ "name": "bestDistances_0_89", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_0_89", "role": "default" }} , 
 	{ "name": "bestDistances_0_90", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_0_90", "role": "default" }} , 
 	{ "name": "bestDistances_0_91", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_0_91", "role": "default" }} , 
 	{ "name": "bestDistances_0_92", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_0_92", "role": "default" }} , 
 	{ "name": "bestDistances_0_93", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_0_93", "role": "default" }} , 
 	{ "name": "bestDistances_0_94", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_0_94", "role": "default" }} , 
 	{ "name": "bestDistances_0_95", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_0_95", "role": "default" }} , 
 	{ "name": "bestDistances_0_96", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_0_96", "role": "default" }} , 
 	{ "name": "bestDistances_0_97", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_0_97", "role": "default" }} , 
 	{ "name": "bestDistances_0_98", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_0_98", "role": "default" }} , 
 	{ "name": "bestDistances_0_99", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_0_99", "role": "default" }} , 
 	{ "name": "bestDistances_0_100", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_0_100", "role": "default" }} , 
 	{ "name": "bestDistances_0_101", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_0_101", "role": "default" }} , 
 	{ "name": "secondWorstOfBest_6_out", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "secondWorstOfBest_6_out", "role": "default" }} , 
 	{ "name": "secondWorstOfBest_6_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "secondWorstOfBest_6_out", "role": "ap_vld" }} , 
 	{ "name": "worstOfBestIdx_4_out", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "worstOfBestIdx_4_out", "role": "default" }} , 
 	{ "name": "worstOfBestIdx_4_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "worstOfBestIdx_4_out", "role": "ap_vld" }} , 
 	{ "name": "worstOfBest_4_out", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "worstOfBest_4_out", "role": "default" }} , 
 	{ "name": "worstOfBest_4_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "worstOfBest_4_out", "role": "ap_vld" }} , 
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
		"CDFG" : "kNN_Predict_4_Pipeline_VITIS_LOOP_17_13",
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
			{"Name" : "bestDistances_0_82", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_0_83", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_0_84", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_0_85", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_0_86", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_0_87", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_0_88", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_0_89", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_0_90", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_0_91", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_0_92", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_0_93", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_0_94", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_0_95", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_0_96", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_0_97", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_0_98", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_0_99", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_0_100", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_0_101", "Type" : "None", "Direction" : "I"},
			{"Name" : "secondWorstOfBest_6_out", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "worstOfBestIdx_4_out", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "worstOfBest_4_out", "Type" : "Vld", "Direction" : "O"}],
		"Loop" : [
			{"Name" : "VITIS_LOOP_17_1", "PipelineType" : "UPC",
				"LoopDec" : {"FSMBitwidth" : "1", "FirstState" : "ap_ST_fsm_pp0_stage0", "FirstStateIter" : "ap_enable_reg_pp0_iter1", "FirstStateBlock" : "ap_block_pp0_stage0_subdone", "LastState" : "ap_ST_fsm_pp0_stage0", "LastStateIter" : "ap_enable_reg_pp0_iter2", "LastStateBlock" : "ap_block_pp0_stage0_subdone", "QuitState" : "ap_ST_fsm_pp0_stage0", "QuitStateIter" : "ap_enable_reg_pp0_iter2", "QuitStateBlock" : "ap_block_pp0_stage0_subdone", "OneDepthLoop" : "0", "has_ap_ctrl" : "1", "has_continue" : "0"}}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mux_205_64_1_1_U105", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.flow_control_loop_pipe_sequential_init_U", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	kNN_Predict_4_Pipeline_VITIS_LOOP_17_13 {
		bestDistances_0_82 {Type I LastRead 0 FirstWrite -1}
		bestDistances_0_83 {Type I LastRead 0 FirstWrite -1}
		bestDistances_0_84 {Type I LastRead 0 FirstWrite -1}
		bestDistances_0_85 {Type I LastRead 0 FirstWrite -1}
		bestDistances_0_86 {Type I LastRead 0 FirstWrite -1}
		bestDistances_0_87 {Type I LastRead 0 FirstWrite -1}
		bestDistances_0_88 {Type I LastRead 0 FirstWrite -1}
		bestDistances_0_89 {Type I LastRead 0 FirstWrite -1}
		bestDistances_0_90 {Type I LastRead 0 FirstWrite -1}
		bestDistances_0_91 {Type I LastRead 0 FirstWrite -1}
		bestDistances_0_92 {Type I LastRead 0 FirstWrite -1}
		bestDistances_0_93 {Type I LastRead 0 FirstWrite -1}
		bestDistances_0_94 {Type I LastRead 0 FirstWrite -1}
		bestDistances_0_95 {Type I LastRead 0 FirstWrite -1}
		bestDistances_0_96 {Type I LastRead 0 FirstWrite -1}
		bestDistances_0_97 {Type I LastRead 0 FirstWrite -1}
		bestDistances_0_98 {Type I LastRead 0 FirstWrite -1}
		bestDistances_0_99 {Type I LastRead 0 FirstWrite -1}
		bestDistances_0_100 {Type I LastRead 0 FirstWrite -1}
		bestDistances_0_101 {Type I LastRead 0 FirstWrite -1}
		secondWorstOfBest_6_out {Type O LastRead -1 FirstWrite 2}
		worstOfBestIdx_4_out {Type O LastRead -1 FirstWrite 2}
		worstOfBest_4_out {Type O LastRead -1 FirstWrite 2}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "23", "Max" : "23"}
	, {"Name" : "Interval", "Min" : "23", "Max" : "23"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
]}

set Spec2ImplPortList { 
	bestDistances_0_82 { ap_none {  { bestDistances_0_82 in_data 0 64 } } }
	bestDistances_0_83 { ap_none {  { bestDistances_0_83 in_data 0 64 } } }
	bestDistances_0_84 { ap_none {  { bestDistances_0_84 in_data 0 64 } } }
	bestDistances_0_85 { ap_none {  { bestDistances_0_85 in_data 0 64 } } }
	bestDistances_0_86 { ap_none {  { bestDistances_0_86 in_data 0 64 } } }
	bestDistances_0_87 { ap_none {  { bestDistances_0_87 in_data 0 64 } } }
	bestDistances_0_88 { ap_none {  { bestDistances_0_88 in_data 0 64 } } }
	bestDistances_0_89 { ap_none {  { bestDistances_0_89 in_data 0 64 } } }
	bestDistances_0_90 { ap_none {  { bestDistances_0_90 in_data 0 64 } } }
	bestDistances_0_91 { ap_none {  { bestDistances_0_91 in_data 0 64 } } }
	bestDistances_0_92 { ap_none {  { bestDistances_0_92 in_data 0 64 } } }
	bestDistances_0_93 { ap_none {  { bestDistances_0_93 in_data 0 64 } } }
	bestDistances_0_94 { ap_none {  { bestDistances_0_94 in_data 0 64 } } }
	bestDistances_0_95 { ap_none {  { bestDistances_0_95 in_data 0 64 } } }
	bestDistances_0_96 { ap_none {  { bestDistances_0_96 in_data 0 64 } } }
	bestDistances_0_97 { ap_none {  { bestDistances_0_97 in_data 0 64 } } }
	bestDistances_0_98 { ap_none {  { bestDistances_0_98 in_data 0 64 } } }
	bestDistances_0_99 { ap_none {  { bestDistances_0_99 in_data 0 64 } } }
	bestDistances_0_100 { ap_none {  { bestDistances_0_100 in_data 0 64 } } }
	bestDistances_0_101 { ap_none {  { bestDistances_0_101 in_data 0 64 } } }
	secondWorstOfBest_6_out { ap_vld {  { secondWorstOfBest_6_out out_data 1 64 }  { secondWorstOfBest_6_out_ap_vld out_vld 1 1 } } }
	worstOfBestIdx_4_out { ap_vld {  { worstOfBestIdx_4_out out_data 1 5 }  { worstOfBestIdx_4_out_ap_vld out_vld 1 1 } } }
	worstOfBest_4_out { ap_vld {  { worstOfBest_4_out out_data 1 64 }  { worstOfBest_4_out_ap_vld out_vld 1 1 } } }
}
