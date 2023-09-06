set moduleName kNN_Predict_4_Pipeline_VITIS_LOOP_121_4
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
set C_modelName {kNN_Predict_4_Pipeline_VITIS_LOOP_121_4}
set C_modelType { void 0 }
set C_modelArgList {
	{ mul_ln136 int 16 regular  }
	{ training_X_0 int 32 regular {array 46612 { 1 3 } 1 1 }  }
	{ training_X_1 int 32 regular {array 46612 { 1 3 } 1 1 }  }
	{ training_X_2 int 32 regular {array 46612 { 1 3 } 1 1 }  }
	{ training_X_3 int 32 regular {array 46612 { 1 3 } 1 1 }  }
	{ mul_ln61 int 16 regular  }
	{ testing_X int 32 regular {array 46526 { 1 1 } 1 1 }  }
	{ mul_ln62 int 16 regular  }
	{ mul_ln63 int 16 regular  }
	{ mul_ln64 int 16 regular  }
	{ distance_q3_t3_out double 64 regular {pointer 1}  }
	{ distance_q3_t2_out double 64 regular {pointer 1}  }
	{ distance_q3_t1_out double 64 regular {pointer 1}  }
	{ distance_q3_t0_out double 64 regular {pointer 1}  }
	{ distance_q2_t3_out double 64 regular {pointer 1}  }
	{ distance_q0_t0_out double 64 regular {pointer 1}  }
	{ distance_q0_t1_out double 64 regular {pointer 1}  }
	{ distance_q0_t2_out double 64 regular {pointer 1}  }
	{ distance_q0_t3_out double 64 regular {pointer 1}  }
	{ distance_q1_t0_out double 64 regular {pointer 1}  }
	{ distance_q1_t1_out double 64 regular {pointer 1}  }
	{ distance_q1_t2_out double 64 regular {pointer 1}  }
	{ distance_q1_t3_out double 64 regular {pointer 1}  }
	{ distance_q2_t0_out double 64 regular {pointer 1}  }
	{ distance_q2_t1_out double 64 regular {pointer 1}  }
	{ distance_q2_t2_out double 64 regular {pointer 1}  }
}
set C_modelArgMapList {[ 
	{ "Name" : "mul_ln136", "interface" : "wire", "bitwidth" : 16, "direction" : "READONLY"} , 
 	{ "Name" : "training_X_0", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "training_X_1", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "training_X_2", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "training_X_3", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "mul_ln61", "interface" : "wire", "bitwidth" : 16, "direction" : "READONLY"} , 
 	{ "Name" : "testing_X", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "mul_ln62", "interface" : "wire", "bitwidth" : 16, "direction" : "READONLY"} , 
 	{ "Name" : "mul_ln63", "interface" : "wire", "bitwidth" : 16, "direction" : "READONLY"} , 
 	{ "Name" : "mul_ln64", "interface" : "wire", "bitwidth" : 16, "direction" : "READONLY"} , 
 	{ "Name" : "distance_q3_t3_out", "interface" : "wire", "bitwidth" : 64, "direction" : "WRITEONLY"} , 
 	{ "Name" : "distance_q3_t2_out", "interface" : "wire", "bitwidth" : 64, "direction" : "WRITEONLY"} , 
 	{ "Name" : "distance_q3_t1_out", "interface" : "wire", "bitwidth" : 64, "direction" : "WRITEONLY"} , 
 	{ "Name" : "distance_q3_t0_out", "interface" : "wire", "bitwidth" : 64, "direction" : "WRITEONLY"} , 
 	{ "Name" : "distance_q2_t3_out", "interface" : "wire", "bitwidth" : 64, "direction" : "WRITEONLY"} , 
 	{ "Name" : "distance_q0_t0_out", "interface" : "wire", "bitwidth" : 64, "direction" : "WRITEONLY"} , 
 	{ "Name" : "distance_q0_t1_out", "interface" : "wire", "bitwidth" : 64, "direction" : "WRITEONLY"} , 
 	{ "Name" : "distance_q0_t2_out", "interface" : "wire", "bitwidth" : 64, "direction" : "WRITEONLY"} , 
 	{ "Name" : "distance_q0_t3_out", "interface" : "wire", "bitwidth" : 64, "direction" : "WRITEONLY"} , 
 	{ "Name" : "distance_q1_t0_out", "interface" : "wire", "bitwidth" : 64, "direction" : "WRITEONLY"} , 
 	{ "Name" : "distance_q1_t1_out", "interface" : "wire", "bitwidth" : 64, "direction" : "WRITEONLY"} , 
 	{ "Name" : "distance_q1_t2_out", "interface" : "wire", "bitwidth" : 64, "direction" : "WRITEONLY"} , 
 	{ "Name" : "distance_q1_t3_out", "interface" : "wire", "bitwidth" : 64, "direction" : "WRITEONLY"} , 
 	{ "Name" : "distance_q2_t0_out", "interface" : "wire", "bitwidth" : 64, "direction" : "WRITEONLY"} , 
 	{ "Name" : "distance_q2_t1_out", "interface" : "wire", "bitwidth" : 64, "direction" : "WRITEONLY"} , 
 	{ "Name" : "distance_q2_t2_out", "interface" : "wire", "bitwidth" : 64, "direction" : "WRITEONLY"} ]}
# RTL Port declarations: 
set portNum 79
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ mul_ln136 sc_in sc_lv 16 signal 0 } 
	{ training_X_0_address0 sc_out sc_lv 16 signal 1 } 
	{ training_X_0_ce0 sc_out sc_logic 1 signal 1 } 
	{ training_X_0_q0 sc_in sc_lv 32 signal 1 } 
	{ training_X_1_address0 sc_out sc_lv 16 signal 2 } 
	{ training_X_1_ce0 sc_out sc_logic 1 signal 2 } 
	{ training_X_1_q0 sc_in sc_lv 32 signal 2 } 
	{ training_X_2_address0 sc_out sc_lv 16 signal 3 } 
	{ training_X_2_ce0 sc_out sc_logic 1 signal 3 } 
	{ training_X_2_q0 sc_in sc_lv 32 signal 3 } 
	{ training_X_3_address0 sc_out sc_lv 16 signal 4 } 
	{ training_X_3_ce0 sc_out sc_logic 1 signal 4 } 
	{ training_X_3_q0 sc_in sc_lv 32 signal 4 } 
	{ mul_ln61 sc_in sc_lv 16 signal 5 } 
	{ testing_X_address0 sc_out sc_lv 16 signal 6 } 
	{ testing_X_ce0 sc_out sc_logic 1 signal 6 } 
	{ testing_X_q0 sc_in sc_lv 32 signal 6 } 
	{ testing_X_address1 sc_out sc_lv 16 signal 6 } 
	{ testing_X_ce1 sc_out sc_logic 1 signal 6 } 
	{ testing_X_q1 sc_in sc_lv 32 signal 6 } 
	{ mul_ln62 sc_in sc_lv 16 signal 7 } 
	{ mul_ln63 sc_in sc_lv 16 signal 8 } 
	{ mul_ln64 sc_in sc_lv 16 signal 9 } 
	{ distance_q3_t3_out sc_out sc_lv 64 signal 10 } 
	{ distance_q3_t3_out_ap_vld sc_out sc_logic 1 outvld 10 } 
	{ distance_q3_t2_out sc_out sc_lv 64 signal 11 } 
	{ distance_q3_t2_out_ap_vld sc_out sc_logic 1 outvld 11 } 
	{ distance_q3_t1_out sc_out sc_lv 64 signal 12 } 
	{ distance_q3_t1_out_ap_vld sc_out sc_logic 1 outvld 12 } 
	{ distance_q3_t0_out sc_out sc_lv 64 signal 13 } 
	{ distance_q3_t0_out_ap_vld sc_out sc_logic 1 outvld 13 } 
	{ distance_q2_t3_out sc_out sc_lv 64 signal 14 } 
	{ distance_q2_t3_out_ap_vld sc_out sc_logic 1 outvld 14 } 
	{ distance_q0_t0_out sc_out sc_lv 64 signal 15 } 
	{ distance_q0_t0_out_ap_vld sc_out sc_logic 1 outvld 15 } 
	{ distance_q0_t1_out sc_out sc_lv 64 signal 16 } 
	{ distance_q0_t1_out_ap_vld sc_out sc_logic 1 outvld 16 } 
	{ distance_q0_t2_out sc_out sc_lv 64 signal 17 } 
	{ distance_q0_t2_out_ap_vld sc_out sc_logic 1 outvld 17 } 
	{ distance_q0_t3_out sc_out sc_lv 64 signal 18 } 
	{ distance_q0_t3_out_ap_vld sc_out sc_logic 1 outvld 18 } 
	{ distance_q1_t0_out sc_out sc_lv 64 signal 19 } 
	{ distance_q1_t0_out_ap_vld sc_out sc_logic 1 outvld 19 } 
	{ distance_q1_t1_out sc_out sc_lv 64 signal 20 } 
	{ distance_q1_t1_out_ap_vld sc_out sc_logic 1 outvld 20 } 
	{ distance_q1_t2_out sc_out sc_lv 64 signal 21 } 
	{ distance_q1_t2_out_ap_vld sc_out sc_logic 1 outvld 21 } 
	{ distance_q1_t3_out sc_out sc_lv 64 signal 22 } 
	{ distance_q1_t3_out_ap_vld sc_out sc_logic 1 outvld 22 } 
	{ distance_q2_t0_out sc_out sc_lv 64 signal 23 } 
	{ distance_q2_t0_out_ap_vld sc_out sc_logic 1 outvld 23 } 
	{ distance_q2_t1_out sc_out sc_lv 64 signal 24 } 
	{ distance_q2_t1_out_ap_vld sc_out sc_logic 1 outvld 24 } 
	{ distance_q2_t2_out sc_out sc_lv 64 signal 25 } 
	{ distance_q2_t2_out_ap_vld sc_out sc_logic 1 outvld 25 } 
	{ grp_fu_55918_p_din0 sc_out sc_lv 32 signal -1 } 
	{ grp_fu_55918_p_din1 sc_out sc_lv 32 signal -1 } 
	{ grp_fu_55918_p_opcode sc_out sc_lv 2 signal -1 } 
	{ grp_fu_55918_p_dout0 sc_in sc_lv 32 signal -1 } 
	{ grp_fu_55918_p_ce sc_out sc_logic 1 signal -1 } 
	{ grp_fu_55922_p_din0 sc_out sc_lv 32 signal -1 } 
	{ grp_fu_55922_p_din1 sc_out sc_lv 32 signal -1 } 
	{ grp_fu_55922_p_opcode sc_out sc_lv 2 signal -1 } 
	{ grp_fu_55922_p_dout0 sc_in sc_lv 32 signal -1 } 
	{ grp_fu_55922_p_ce sc_out sc_logic 1 signal -1 } 
	{ grp_fu_55926_p_din0 sc_out sc_lv 32 signal -1 } 
	{ grp_fu_55926_p_din1 sc_out sc_lv 32 signal -1 } 
	{ grp_fu_55926_p_opcode sc_out sc_lv 2 signal -1 } 
	{ grp_fu_55926_p_dout0 sc_in sc_lv 32 signal -1 } 
	{ grp_fu_55926_p_ce sc_out sc_logic 1 signal -1 } 
	{ grp_fu_56117_p_din0 sc_out sc_lv 32 signal -1 } 
	{ grp_fu_56117_p_dout0 sc_in sc_lv 64 signal -1 } 
	{ grp_fu_56117_p_ce sc_out sc_logic 1 signal -1 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "mul_ln136", "direction": "in", "datatype": "sc_lv", "bitwidth":16, "type": "signal", "bundle":{"name": "mul_ln136", "role": "default" }} , 
 	{ "name": "training_X_0_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":16, "type": "signal", "bundle":{"name": "training_X_0", "role": "address0" }} , 
 	{ "name": "training_X_0_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "training_X_0", "role": "ce0" }} , 
 	{ "name": "training_X_0_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "training_X_0", "role": "q0" }} , 
 	{ "name": "training_X_1_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":16, "type": "signal", "bundle":{"name": "training_X_1", "role": "address0" }} , 
 	{ "name": "training_X_1_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "training_X_1", "role": "ce0" }} , 
 	{ "name": "training_X_1_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "training_X_1", "role": "q0" }} , 
 	{ "name": "training_X_2_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":16, "type": "signal", "bundle":{"name": "training_X_2", "role": "address0" }} , 
 	{ "name": "training_X_2_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "training_X_2", "role": "ce0" }} , 
 	{ "name": "training_X_2_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "training_X_2", "role": "q0" }} , 
 	{ "name": "training_X_3_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":16, "type": "signal", "bundle":{"name": "training_X_3", "role": "address0" }} , 
 	{ "name": "training_X_3_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "training_X_3", "role": "ce0" }} , 
 	{ "name": "training_X_3_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "training_X_3", "role": "q0" }} , 
 	{ "name": "mul_ln61", "direction": "in", "datatype": "sc_lv", "bitwidth":16, "type": "signal", "bundle":{"name": "mul_ln61", "role": "default" }} , 
 	{ "name": "testing_X_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":16, "type": "signal", "bundle":{"name": "testing_X", "role": "address0" }} , 
 	{ "name": "testing_X_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "testing_X", "role": "ce0" }} , 
 	{ "name": "testing_X_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "testing_X", "role": "q0" }} , 
 	{ "name": "testing_X_address1", "direction": "out", "datatype": "sc_lv", "bitwidth":16, "type": "signal", "bundle":{"name": "testing_X", "role": "address1" }} , 
 	{ "name": "testing_X_ce1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "testing_X", "role": "ce1" }} , 
 	{ "name": "testing_X_q1", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "testing_X", "role": "q1" }} , 
 	{ "name": "mul_ln62", "direction": "in", "datatype": "sc_lv", "bitwidth":16, "type": "signal", "bundle":{"name": "mul_ln62", "role": "default" }} , 
 	{ "name": "mul_ln63", "direction": "in", "datatype": "sc_lv", "bitwidth":16, "type": "signal", "bundle":{"name": "mul_ln63", "role": "default" }} , 
 	{ "name": "mul_ln64", "direction": "in", "datatype": "sc_lv", "bitwidth":16, "type": "signal", "bundle":{"name": "mul_ln64", "role": "default" }} , 
 	{ "name": "distance_q3_t3_out", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "distance_q3_t3_out", "role": "default" }} , 
 	{ "name": "distance_q3_t3_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "distance_q3_t3_out", "role": "ap_vld" }} , 
 	{ "name": "distance_q3_t2_out", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "distance_q3_t2_out", "role": "default" }} , 
 	{ "name": "distance_q3_t2_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "distance_q3_t2_out", "role": "ap_vld" }} , 
 	{ "name": "distance_q3_t1_out", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "distance_q3_t1_out", "role": "default" }} , 
 	{ "name": "distance_q3_t1_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "distance_q3_t1_out", "role": "ap_vld" }} , 
 	{ "name": "distance_q3_t0_out", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "distance_q3_t0_out", "role": "default" }} , 
 	{ "name": "distance_q3_t0_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "distance_q3_t0_out", "role": "ap_vld" }} , 
 	{ "name": "distance_q2_t3_out", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "distance_q2_t3_out", "role": "default" }} , 
 	{ "name": "distance_q2_t3_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "distance_q2_t3_out", "role": "ap_vld" }} , 
 	{ "name": "distance_q0_t0_out", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "distance_q0_t0_out", "role": "default" }} , 
 	{ "name": "distance_q0_t0_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "distance_q0_t0_out", "role": "ap_vld" }} , 
 	{ "name": "distance_q0_t1_out", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "distance_q0_t1_out", "role": "default" }} , 
 	{ "name": "distance_q0_t1_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "distance_q0_t1_out", "role": "ap_vld" }} , 
 	{ "name": "distance_q0_t2_out", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "distance_q0_t2_out", "role": "default" }} , 
 	{ "name": "distance_q0_t2_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "distance_q0_t2_out", "role": "ap_vld" }} , 
 	{ "name": "distance_q0_t3_out", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "distance_q0_t3_out", "role": "default" }} , 
 	{ "name": "distance_q0_t3_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "distance_q0_t3_out", "role": "ap_vld" }} , 
 	{ "name": "distance_q1_t0_out", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "distance_q1_t0_out", "role": "default" }} , 
 	{ "name": "distance_q1_t0_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "distance_q1_t0_out", "role": "ap_vld" }} , 
 	{ "name": "distance_q1_t1_out", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "distance_q1_t1_out", "role": "default" }} , 
 	{ "name": "distance_q1_t1_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "distance_q1_t1_out", "role": "ap_vld" }} , 
 	{ "name": "distance_q1_t2_out", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "distance_q1_t2_out", "role": "default" }} , 
 	{ "name": "distance_q1_t2_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "distance_q1_t2_out", "role": "ap_vld" }} , 
 	{ "name": "distance_q1_t3_out", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "distance_q1_t3_out", "role": "default" }} , 
 	{ "name": "distance_q1_t3_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "distance_q1_t3_out", "role": "ap_vld" }} , 
 	{ "name": "distance_q2_t0_out", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "distance_q2_t0_out", "role": "default" }} , 
 	{ "name": "distance_q2_t0_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "distance_q2_t0_out", "role": "ap_vld" }} , 
 	{ "name": "distance_q2_t1_out", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "distance_q2_t1_out", "role": "default" }} , 
 	{ "name": "distance_q2_t1_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "distance_q2_t1_out", "role": "ap_vld" }} , 
 	{ "name": "distance_q2_t2_out", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "distance_q2_t2_out", "role": "default" }} , 
 	{ "name": "distance_q2_t2_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "distance_q2_t2_out", "role": "ap_vld" }} , 
 	{ "name": "grp_fu_55918_p_din0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_55918_p_din0", "role": "default" }} , 
 	{ "name": "grp_fu_55918_p_din1", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_55918_p_din1", "role": "default" }} , 
 	{ "name": "grp_fu_55918_p_opcode", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "grp_fu_55918_p_opcode", "role": "default" }} , 
 	{ "name": "grp_fu_55918_p_dout0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_55918_p_dout0", "role": "default" }} , 
 	{ "name": "grp_fu_55918_p_ce", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "grp_fu_55918_p_ce", "role": "default" }} , 
 	{ "name": "grp_fu_55922_p_din0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_55922_p_din0", "role": "default" }} , 
 	{ "name": "grp_fu_55922_p_din1", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_55922_p_din1", "role": "default" }} , 
 	{ "name": "grp_fu_55922_p_opcode", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "grp_fu_55922_p_opcode", "role": "default" }} , 
 	{ "name": "grp_fu_55922_p_dout0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_55922_p_dout0", "role": "default" }} , 
 	{ "name": "grp_fu_55922_p_ce", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "grp_fu_55922_p_ce", "role": "default" }} , 
 	{ "name": "grp_fu_55926_p_din0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_55926_p_din0", "role": "default" }} , 
 	{ "name": "grp_fu_55926_p_din1", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_55926_p_din1", "role": "default" }} , 
 	{ "name": "grp_fu_55926_p_opcode", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "grp_fu_55926_p_opcode", "role": "default" }} , 
 	{ "name": "grp_fu_55926_p_dout0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_55926_p_dout0", "role": "default" }} , 
 	{ "name": "grp_fu_55926_p_ce", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "grp_fu_55926_p_ce", "role": "default" }} , 
 	{ "name": "grp_fu_56117_p_din0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_56117_p_din0", "role": "default" }} , 
 	{ "name": "grp_fu_56117_p_dout0", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "grp_fu_56117_p_dout0", "role": "default" }} , 
 	{ "name": "grp_fu_56117_p_ce", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "grp_fu_56117_p_ce", "role": "default" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13"],
		"CDFG" : "kNN_Predict_4_Pipeline_VITIS_LOOP_121_4",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "190", "EstimateLatencyMax" : "190",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"IsBlackBox" : "0",
		"Port" : [
			{"Name" : "mul_ln136", "Type" : "None", "Direction" : "I"},
			{"Name" : "training_X_0", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "training_X_1", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "training_X_2", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "training_X_3", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "mul_ln61", "Type" : "None", "Direction" : "I"},
			{"Name" : "testing_X", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "mul_ln62", "Type" : "None", "Direction" : "I"},
			{"Name" : "mul_ln63", "Type" : "None", "Direction" : "I"},
			{"Name" : "mul_ln64", "Type" : "None", "Direction" : "I"},
			{"Name" : "distance_q3_t3_out", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "distance_q3_t2_out", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "distance_q3_t1_out", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "distance_q3_t0_out", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "distance_q2_t3_out", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "distance_q0_t0_out", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "distance_q0_t1_out", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "distance_q0_t2_out", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "distance_q0_t3_out", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "distance_q1_t0_out", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "distance_q1_t1_out", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "distance_q1_t2_out", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "distance_q1_t3_out", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "distance_q2_t0_out", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "distance_q2_t1_out", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "distance_q2_t2_out", "Type" : "Vld", "Direction" : "O"}],
		"Loop" : [
			{"Name" : "VITIS_LOOP_121_4", "PipelineType" : "UPC",
				"LoopDec" : {"FSMBitwidth" : "4", "FirstState" : "ap_ST_fsm_pp0_stage0", "FirstStateIter" : "ap_enable_reg_pp0_iter0", "FirstStateBlock" : "ap_block_pp0_stage0_subdone", "LastState" : "ap_ST_fsm_pp0_stage0", "LastStateIter" : "ap_enable_reg_pp0_iter5", "LastStateBlock" : "ap_block_pp0_stage0_subdone", "QuitState" : "ap_ST_fsm_pp0_stage0", "QuitStateIter" : "ap_enable_reg_pp0_iter5", "QuitStateBlock" : "ap_block_pp0_stage0_subdone", "OneDepthLoop" : "0", "has_ap_ctrl" : "1", "has_continue" : "0"}}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fsub_32ns_32ns_32_4_full_dsp_1_U7", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fpext_32ns_64_2_no_dsp_1_U9", "Parent" : "0"},
	{"ID" : "3", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fpext_32ns_64_2_no_dsp_1_U10", "Parent" : "0"},
	{"ID" : "4", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fpext_32ns_64_2_no_dsp_1_U11", "Parent" : "0"},
	{"ID" : "5", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dadd_64ns_64ns_64_5_full_dsp_1_U12", "Parent" : "0"},
	{"ID" : "6", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dadd_64ns_64ns_64_5_full_dsp_1_U13", "Parent" : "0"},
	{"ID" : "7", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dadd_64ns_64ns_64_5_full_dsp_1_U14", "Parent" : "0"},
	{"ID" : "8", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dadd_64ns_64ns_64_5_full_dsp_1_U15", "Parent" : "0"},
	{"ID" : "9", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dmul_64ns_64ns_64_5_max_dsp_1_U16", "Parent" : "0"},
	{"ID" : "10", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dmul_64ns_64ns_64_5_max_dsp_1_U17", "Parent" : "0"},
	{"ID" : "11", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dmul_64ns_64ns_64_5_max_dsp_1_U18", "Parent" : "0"},
	{"ID" : "12", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dmul_64ns_64ns_64_5_max_dsp_1_U19", "Parent" : "0"},
	{"ID" : "13", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.flow_control_loop_pipe_sequential_init_U", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	kNN_Predict_4_Pipeline_VITIS_LOOP_121_4 {
		mul_ln136 {Type I LastRead 0 FirstWrite -1}
		training_X_0 {Type I LastRead 0 FirstWrite -1}
		training_X_1 {Type I LastRead 0 FirstWrite -1}
		training_X_2 {Type I LastRead 0 FirstWrite -1}
		training_X_3 {Type I LastRead 0 FirstWrite -1}
		mul_ln61 {Type I LastRead 0 FirstWrite -1}
		testing_X {Type I LastRead 2 FirstWrite -1}
		mul_ln62 {Type I LastRead 0 FirstWrite -1}
		mul_ln63 {Type I LastRead 0 FirstWrite -1}
		mul_ln64 {Type I LastRead 0 FirstWrite -1}
		distance_q3_t3_out {Type O LastRead -1 FirstWrite 16}
		distance_q3_t2_out {Type O LastRead -1 FirstWrite 16}
		distance_q3_t1_out {Type O LastRead -1 FirstWrite 16}
		distance_q3_t0_out {Type O LastRead -1 FirstWrite 16}
		distance_q2_t3_out {Type O LastRead -1 FirstWrite 16}
		distance_q0_t0_out {Type O LastRead -1 FirstWrite 16}
		distance_q0_t1_out {Type O LastRead -1 FirstWrite 16}
		distance_q0_t2_out {Type O LastRead -1 FirstWrite 16}
		distance_q0_t3_out {Type O LastRead -1 FirstWrite 16}
		distance_q1_t0_out {Type O LastRead -1 FirstWrite 16}
		distance_q1_t1_out {Type O LastRead -1 FirstWrite 16}
		distance_q1_t2_out {Type O LastRead -1 FirstWrite 16}
		distance_q1_t3_out {Type O LastRead -1 FirstWrite 16}
		distance_q2_t0_out {Type O LastRead -1 FirstWrite 16}
		distance_q2_t1_out {Type O LastRead -1 FirstWrite 16}
		distance_q2_t2_out {Type O LastRead -1 FirstWrite 16}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "190", "Max" : "190"}
	, {"Name" : "Interval", "Min" : "190", "Max" : "190"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
]}

set Spec2ImplPortList { 
	mul_ln136 { ap_none {  { mul_ln136 in_data 0 16 } } }
	training_X_0 { ap_memory {  { training_X_0_address0 mem_address 1 16 }  { training_X_0_ce0 mem_ce 1 1 }  { training_X_0_q0 in_data 0 32 } } }
	training_X_1 { ap_memory {  { training_X_1_address0 mem_address 1 16 }  { training_X_1_ce0 mem_ce 1 1 }  { training_X_1_q0 in_data 0 32 } } }
	training_X_2 { ap_memory {  { training_X_2_address0 mem_address 1 16 }  { training_X_2_ce0 mem_ce 1 1 }  { training_X_2_q0 in_data 0 32 } } }
	training_X_3 { ap_memory {  { training_X_3_address0 mem_address 1 16 }  { training_X_3_ce0 mem_ce 1 1 }  { training_X_3_q0 in_data 0 32 } } }
	mul_ln61 { ap_none {  { mul_ln61 in_data 0 16 } } }
	testing_X { ap_memory {  { testing_X_address0 mem_address 1 16 }  { testing_X_ce0 mem_ce 1 1 }  { testing_X_q0 in_data 0 32 }  { testing_X_address1 MemPortADDR2 1 16 }  { testing_X_ce1 MemPortCE2 1 1 }  { testing_X_q1 in_data 0 32 } } }
	mul_ln62 { ap_none {  { mul_ln62 in_data 0 16 } } }
	mul_ln63 { ap_none {  { mul_ln63 in_data 0 16 } } }
	mul_ln64 { ap_none {  { mul_ln64 in_data 0 16 } } }
	distance_q3_t3_out { ap_vld {  { distance_q3_t3_out out_data 1 64 }  { distance_q3_t3_out_ap_vld out_vld 1 1 } } }
	distance_q3_t2_out { ap_vld {  { distance_q3_t2_out out_data 1 64 }  { distance_q3_t2_out_ap_vld out_vld 1 1 } } }
	distance_q3_t1_out { ap_vld {  { distance_q3_t1_out out_data 1 64 }  { distance_q3_t1_out_ap_vld out_vld 1 1 } } }
	distance_q3_t0_out { ap_vld {  { distance_q3_t0_out out_data 1 64 }  { distance_q3_t0_out_ap_vld out_vld 1 1 } } }
	distance_q2_t3_out { ap_vld {  { distance_q2_t3_out out_data 1 64 }  { distance_q2_t3_out_ap_vld out_vld 1 1 } } }
	distance_q0_t0_out { ap_vld {  { distance_q0_t0_out out_data 1 64 }  { distance_q0_t0_out_ap_vld out_vld 1 1 } } }
	distance_q0_t1_out { ap_vld {  { distance_q0_t1_out out_data 1 64 }  { distance_q0_t1_out_ap_vld out_vld 1 1 } } }
	distance_q0_t2_out { ap_vld {  { distance_q0_t2_out out_data 1 64 }  { distance_q0_t2_out_ap_vld out_vld 1 1 } } }
	distance_q0_t3_out { ap_vld {  { distance_q0_t3_out out_data 1 64 }  { distance_q0_t3_out_ap_vld out_vld 1 1 } } }
	distance_q1_t0_out { ap_vld {  { distance_q1_t0_out out_data 1 64 }  { distance_q1_t0_out_ap_vld out_vld 1 1 } } }
	distance_q1_t1_out { ap_vld {  { distance_q1_t1_out out_data 1 64 }  { distance_q1_t1_out_ap_vld out_vld 1 1 } } }
	distance_q1_t2_out { ap_vld {  { distance_q1_t2_out out_data 1 64 }  { distance_q1_t2_out_ap_vld out_vld 1 1 } } }
	distance_q1_t3_out { ap_vld {  { distance_q1_t3_out out_data 1 64 }  { distance_q1_t3_out_ap_vld out_vld 1 1 } } }
	distance_q2_t0_out { ap_vld {  { distance_q2_t0_out out_data 1 64 }  { distance_q2_t0_out_ap_vld out_vld 1 1 } } }
	distance_q2_t1_out { ap_vld {  { distance_q2_t1_out out_data 1 64 }  { distance_q2_t1_out_ap_vld out_vld 1 1 } } }
	distance_q2_t2_out { ap_vld {  { distance_q2_t2_out out_data 1 64 }  { distance_q2_t2_out_ap_vld out_vld 1 1 } } }
}
