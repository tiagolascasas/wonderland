set moduleName kNN_Predict_4_Pipeline_VITIS_LOOP_17_14
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
set C_modelName {kNN_Predict_4_Pipeline_VITIS_LOOP_17_14}
set C_modelType { void 0 }
set C_modelArgList {
	{ bestDistances_0_123 double 64 regular  }
	{ bestDistances_0_124 double 64 regular  }
	{ bestDistances_0_125 double 64 regular  }
	{ bestDistances_0_126 double 64 regular  }
	{ bestDistances_0_127 double 64 regular  }
	{ bestDistances_0_128 double 64 regular  }
	{ bestDistances_0_129 double 64 regular  }
	{ bestDistances_0_130 double 64 regular  }
	{ bestDistances_0_131 double 64 regular  }
	{ bestDistances_0_132 double 64 regular  }
	{ bestDistances_0_133 double 64 regular  }
	{ bestDistances_0_134 double 64 regular  }
	{ bestDistances_0_135 double 64 regular  }
	{ bestDistances_0_136 double 64 regular  }
	{ bestDistances_0_137 double 64 regular  }
	{ bestDistances_0_138 double 64 regular  }
	{ bestDistances_0_139 double 64 regular  }
	{ bestDistances_0_140 double 64 regular  }
	{ bestDistances_0_141 double 64 regular  }
	{ bestDistances_0_142 double 64 regular  }
	{ secondWorstOfBest_9_out double 64 regular {pointer 1}  }
	{ worstOfBestIdx_6_out int 5 regular {pointer 1}  }
	{ worstOfBest_6_out double 64 regular {pointer 1}  }
}
set C_modelArgMapList {[ 
	{ "Name" : "bestDistances_0_123", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_0_124", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_0_125", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_0_126", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_0_127", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_0_128", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_0_129", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_0_130", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_0_131", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_0_132", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_0_133", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_0_134", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_0_135", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_0_136", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_0_137", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_0_138", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_0_139", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_0_140", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_0_141", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_0_142", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "secondWorstOfBest_9_out", "interface" : "wire", "bitwidth" : 64, "direction" : "WRITEONLY"} , 
 	{ "Name" : "worstOfBestIdx_6_out", "interface" : "wire", "bitwidth" : 5, "direction" : "WRITEONLY"} , 
 	{ "Name" : "worstOfBest_6_out", "interface" : "wire", "bitwidth" : 64, "direction" : "WRITEONLY"} ]}
# RTL Port declarations: 
set portNum 42
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ bestDistances_0_123 sc_in sc_lv 64 signal 0 } 
	{ bestDistances_0_124 sc_in sc_lv 64 signal 1 } 
	{ bestDistances_0_125 sc_in sc_lv 64 signal 2 } 
	{ bestDistances_0_126 sc_in sc_lv 64 signal 3 } 
	{ bestDistances_0_127 sc_in sc_lv 64 signal 4 } 
	{ bestDistances_0_128 sc_in sc_lv 64 signal 5 } 
	{ bestDistances_0_129 sc_in sc_lv 64 signal 6 } 
	{ bestDistances_0_130 sc_in sc_lv 64 signal 7 } 
	{ bestDistances_0_131 sc_in sc_lv 64 signal 8 } 
	{ bestDistances_0_132 sc_in sc_lv 64 signal 9 } 
	{ bestDistances_0_133 sc_in sc_lv 64 signal 10 } 
	{ bestDistances_0_134 sc_in sc_lv 64 signal 11 } 
	{ bestDistances_0_135 sc_in sc_lv 64 signal 12 } 
	{ bestDistances_0_136 sc_in sc_lv 64 signal 13 } 
	{ bestDistances_0_137 sc_in sc_lv 64 signal 14 } 
	{ bestDistances_0_138 sc_in sc_lv 64 signal 15 } 
	{ bestDistances_0_139 sc_in sc_lv 64 signal 16 } 
	{ bestDistances_0_140 sc_in sc_lv 64 signal 17 } 
	{ bestDistances_0_141 sc_in sc_lv 64 signal 18 } 
	{ bestDistances_0_142 sc_in sc_lv 64 signal 19 } 
	{ secondWorstOfBest_9_out sc_out sc_lv 64 signal 20 } 
	{ secondWorstOfBest_9_out_ap_vld sc_out sc_logic 1 outvld 20 } 
	{ worstOfBestIdx_6_out sc_out sc_lv 5 signal 21 } 
	{ worstOfBestIdx_6_out_ap_vld sc_out sc_logic 1 outvld 21 } 
	{ worstOfBest_6_out sc_out sc_lv 64 signal 22 } 
	{ worstOfBest_6_out_ap_vld sc_out sc_logic 1 outvld 22 } 
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
 	{ "name": "bestDistances_0_123", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_0_123", "role": "default" }} , 
 	{ "name": "bestDistances_0_124", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_0_124", "role": "default" }} , 
 	{ "name": "bestDistances_0_125", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_0_125", "role": "default" }} , 
 	{ "name": "bestDistances_0_126", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_0_126", "role": "default" }} , 
 	{ "name": "bestDistances_0_127", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_0_127", "role": "default" }} , 
 	{ "name": "bestDistances_0_128", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_0_128", "role": "default" }} , 
 	{ "name": "bestDistances_0_129", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_0_129", "role": "default" }} , 
 	{ "name": "bestDistances_0_130", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_0_130", "role": "default" }} , 
 	{ "name": "bestDistances_0_131", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_0_131", "role": "default" }} , 
 	{ "name": "bestDistances_0_132", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_0_132", "role": "default" }} , 
 	{ "name": "bestDistances_0_133", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_0_133", "role": "default" }} , 
 	{ "name": "bestDistances_0_134", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_0_134", "role": "default" }} , 
 	{ "name": "bestDistances_0_135", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_0_135", "role": "default" }} , 
 	{ "name": "bestDistances_0_136", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_0_136", "role": "default" }} , 
 	{ "name": "bestDistances_0_137", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_0_137", "role": "default" }} , 
 	{ "name": "bestDistances_0_138", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_0_138", "role": "default" }} , 
 	{ "name": "bestDistances_0_139", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_0_139", "role": "default" }} , 
 	{ "name": "bestDistances_0_140", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_0_140", "role": "default" }} , 
 	{ "name": "bestDistances_0_141", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_0_141", "role": "default" }} , 
 	{ "name": "bestDistances_0_142", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_0_142", "role": "default" }} , 
 	{ "name": "secondWorstOfBest_9_out", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "secondWorstOfBest_9_out", "role": "default" }} , 
 	{ "name": "secondWorstOfBest_9_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "secondWorstOfBest_9_out", "role": "ap_vld" }} , 
 	{ "name": "worstOfBestIdx_6_out", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "worstOfBestIdx_6_out", "role": "default" }} , 
 	{ "name": "worstOfBestIdx_6_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "worstOfBestIdx_6_out", "role": "ap_vld" }} , 
 	{ "name": "worstOfBest_6_out", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "worstOfBest_6_out", "role": "default" }} , 
 	{ "name": "worstOfBest_6_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "worstOfBest_6_out", "role": "ap_vld" }} , 
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
		"CDFG" : "kNN_Predict_4_Pipeline_VITIS_LOOP_17_14",
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
			{"Name" : "bestDistances_0_123", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_0_124", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_0_125", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_0_126", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_0_127", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_0_128", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_0_129", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_0_130", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_0_131", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_0_132", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_0_133", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_0_134", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_0_135", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_0_136", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_0_137", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_0_138", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_0_139", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_0_140", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_0_141", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_0_142", "Type" : "None", "Direction" : "I"},
			{"Name" : "secondWorstOfBest_9_out", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "worstOfBestIdx_6_out", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "worstOfBest_6_out", "Type" : "Vld", "Direction" : "O"}],
		"Loop" : [
			{"Name" : "VITIS_LOOP_17_1", "PipelineType" : "UPC",
				"LoopDec" : {"FSMBitwidth" : "1", "FirstState" : "ap_ST_fsm_pp0_stage0", "FirstStateIter" : "ap_enable_reg_pp0_iter1", "FirstStateBlock" : "ap_block_pp0_stage0_subdone", "LastState" : "ap_ST_fsm_pp0_stage0", "LastStateIter" : "ap_enable_reg_pp0_iter2", "LastStateBlock" : "ap_block_pp0_stage0_subdone", "QuitState" : "ap_ST_fsm_pp0_stage0", "QuitStateIter" : "ap_enable_reg_pp0_iter2", "QuitStateBlock" : "ap_block_pp0_stage0_subdone", "OneDepthLoop" : "0", "has_ap_ctrl" : "1", "has_continue" : "0"}}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mux_205_64_1_1_U131", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.flow_control_loop_pipe_sequential_init_U", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	kNN_Predict_4_Pipeline_VITIS_LOOP_17_14 {
		bestDistances_0_123 {Type I LastRead 0 FirstWrite -1}
		bestDistances_0_124 {Type I LastRead 0 FirstWrite -1}
		bestDistances_0_125 {Type I LastRead 0 FirstWrite -1}
		bestDistances_0_126 {Type I LastRead 0 FirstWrite -1}
		bestDistances_0_127 {Type I LastRead 0 FirstWrite -1}
		bestDistances_0_128 {Type I LastRead 0 FirstWrite -1}
		bestDistances_0_129 {Type I LastRead 0 FirstWrite -1}
		bestDistances_0_130 {Type I LastRead 0 FirstWrite -1}
		bestDistances_0_131 {Type I LastRead 0 FirstWrite -1}
		bestDistances_0_132 {Type I LastRead 0 FirstWrite -1}
		bestDistances_0_133 {Type I LastRead 0 FirstWrite -1}
		bestDistances_0_134 {Type I LastRead 0 FirstWrite -1}
		bestDistances_0_135 {Type I LastRead 0 FirstWrite -1}
		bestDistances_0_136 {Type I LastRead 0 FirstWrite -1}
		bestDistances_0_137 {Type I LastRead 0 FirstWrite -1}
		bestDistances_0_138 {Type I LastRead 0 FirstWrite -1}
		bestDistances_0_139 {Type I LastRead 0 FirstWrite -1}
		bestDistances_0_140 {Type I LastRead 0 FirstWrite -1}
		bestDistances_0_141 {Type I LastRead 0 FirstWrite -1}
		bestDistances_0_142 {Type I LastRead 0 FirstWrite -1}
		secondWorstOfBest_9_out {Type O LastRead -1 FirstWrite 2}
		worstOfBestIdx_6_out {Type O LastRead -1 FirstWrite 2}
		worstOfBest_6_out {Type O LastRead -1 FirstWrite 2}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "23", "Max" : "23"}
	, {"Name" : "Interval", "Min" : "23", "Max" : "23"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
]}

set Spec2ImplPortList { 
	bestDistances_0_123 { ap_none {  { bestDistances_0_123 in_data 0 64 } } }
	bestDistances_0_124 { ap_none {  { bestDistances_0_124 in_data 0 64 } } }
	bestDistances_0_125 { ap_none {  { bestDistances_0_125 in_data 0 64 } } }
	bestDistances_0_126 { ap_none {  { bestDistances_0_126 in_data 0 64 } } }
	bestDistances_0_127 { ap_none {  { bestDistances_0_127 in_data 0 64 } } }
	bestDistances_0_128 { ap_none {  { bestDistances_0_128 in_data 0 64 } } }
	bestDistances_0_129 { ap_none {  { bestDistances_0_129 in_data 0 64 } } }
	bestDistances_0_130 { ap_none {  { bestDistances_0_130 in_data 0 64 } } }
	bestDistances_0_131 { ap_none {  { bestDistances_0_131 in_data 0 64 } } }
	bestDistances_0_132 { ap_none {  { bestDistances_0_132 in_data 0 64 } } }
	bestDistances_0_133 { ap_none {  { bestDistances_0_133 in_data 0 64 } } }
	bestDistances_0_134 { ap_none {  { bestDistances_0_134 in_data 0 64 } } }
	bestDistances_0_135 { ap_none {  { bestDistances_0_135 in_data 0 64 } } }
	bestDistances_0_136 { ap_none {  { bestDistances_0_136 in_data 0 64 } } }
	bestDistances_0_137 { ap_none {  { bestDistances_0_137 in_data 0 64 } } }
	bestDistances_0_138 { ap_none {  { bestDistances_0_138 in_data 0 64 } } }
	bestDistances_0_139 { ap_none {  { bestDistances_0_139 in_data 0 64 } } }
	bestDistances_0_140 { ap_none {  { bestDistances_0_140 in_data 0 64 } } }
	bestDistances_0_141 { ap_none {  { bestDistances_0_141 in_data 0 64 } } }
	bestDistances_0_142 { ap_none {  { bestDistances_0_142 in_data 0 64 } } }
	secondWorstOfBest_9_out { ap_vld {  { secondWorstOfBest_9_out out_data 1 64 }  { secondWorstOfBest_9_out_ap_vld out_vld 1 1 } } }
	worstOfBestIdx_6_out { ap_vld {  { worstOfBestIdx_6_out out_data 1 5 }  { worstOfBestIdx_6_out_ap_vld out_vld 1 1 } } }
	worstOfBest_6_out { ap_vld {  { worstOfBest_6_out out_data 1 64 }  { worstOfBest_6_out_ap_vld out_vld 1 1 } } }
}
