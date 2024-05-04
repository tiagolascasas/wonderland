# ==============================================================
# Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2023.2 (64-bit)
# Tool Version Limit: 2023.10
# Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
# Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
# 
# ==============================================================
CSIM_DESIGN = 1

__SIM_FPO__ = 1

__SIM_MATHHLS__ = 1

__SIM_FFT__ = 1

__SIM_FIR__ = 1

__SIM_DDS__ = 1

ObjDir = obj

HLS_SOURCES = ../../../../../src_fixed_vga/calcSobel_dX.c ../../../../../src_fixed_vga/calcSobel_dY.c ../../../../../src_fixed_vga/computeSAD.c ../../../../../src_fixed_vga/correlateSAD_2D.c ../../../../../src_fixed_vga/fDeepCopy.c ../../../../../src_fixed_vga/fFreeHandle.c ../../../../../src_fixed_vga/fMallocHandle.c ../../../../../src_fixed_vga/fSetArray.c ../../../../../src_fixed_vga/ffDivide.c ../../../../../src_fixed_vga/finalSAD.c ../../../../../src_fixed_vga/findDisparity.c ../../../../../src_fixed_vga/getDisparity.c ../../../../../src_fixed_vga/iFreeHandle.c ../../../../../src_fixed_vga/iMallocHandle.c ../../../../../src_fixed_vga/iSetArray.c ../../../../../src_fixed_vga/integralImage2D2D.c ../../../../../src_fixed_vga/padarray2.c ../../../../../src_fixed_vga/padarray4.c ../../../../../src_fixed_vga/photonEndTiming.c ../../../../../src_fixed_vga/photonPrintTiming.c ../../../../../src_fixed_vga/photonReportTiming.c ../../../../../src_fixed_vga/photonStartTiming.c ../../../../../src_fixed_vga/readImage.c ../../../../../src_fixed_vga/script_disparity.c ../../../../foo.c

override TARGET := csim.exe

AUTOPILOT_ROOT := /tools/Xilinx/Vitis_HLS/2023.2
AUTOPILOT_MACH := lnx64
ifdef AP_GCC_M32
  AUTOPILOT_MACH := Linux_x86
  IFLAG += -m32
endif
IFLAG += -fPIC
ifndef AP_GCC_PATH
  AP_GCC_PATH := /tools/Xilinx/Vitis_HLS/2023.2/tps/lnx64/gcc-8.3.0/bin
endif
AUTOPILOT_TOOL := ${AUTOPILOT_ROOT}/${AUTOPILOT_MACH}/tools
AP_CLANG_PATH := ${AUTOPILOT_TOOL}/clang-3.9/bin
AUTOPILOT_TECH := ${AUTOPILOT_ROOT}/common/technology


IFLAG += -I "${AUTOPILOT_ROOT}/include"
IFLAG += -I "${AUTOPILOT_ROOT}/include/ap_sysc"
IFLAG += -I "${AUTOPILOT_TECH}/generic/SystemC"
IFLAG += -I "${AUTOPILOT_TECH}/generic/SystemC/AESL_FP_comp"
IFLAG += -I "${AUTOPILOT_TECH}/generic/SystemC/AESL_comp"
IFLAG += -I "${AUTOPILOT_TOOL}/auto_cc/include"
IFLAG += -I "/usr/include/x86_64-linux-gnu"
IFLAG += -D__HLS_COSIM__

IFLAG += -D__HLS_CSIM__

IFLAG += -D__VITIS_HLS__

IFLAG += -D__SIM_FPO__

IFLAG += -D__SIM_FFT__

IFLAG += -D__SIM_FIR__

IFLAG += -D__SIM_DDS__

IFLAG += -D__DSP48E2__
IFLAG += -g
DFLAG += -DAUTOCC
DFLAG += -D__xilinx_ip_top= -DAESL_TB
CCFLAG += -Werror=return-type
CCFLAG += -Wno-abi
TOOLCHAIN += 



include ./Makefile.rules

all: $(TARGET)



AUTOCC := apcc 

$(ObjDir)/calcSobel_dX.o: ../../../../../src_fixed_vga/calcSobel_dX.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../src_fixed_vga/calcSobel_dX.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD -Wno-unknown-pragmas -Wno-unknown-pragmas  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/calcSobel_dX.d

$(ObjDir)/calcSobel_dY.o: ../../../../../src_fixed_vga/calcSobel_dY.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../src_fixed_vga/calcSobel_dY.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD -Wno-unknown-pragmas -Wno-unknown-pragmas  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/calcSobel_dY.d

$(ObjDir)/computeSAD.o: ../../../../../src_fixed_vga/computeSAD.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../src_fixed_vga/computeSAD.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD -Wno-unknown-pragmas -Wno-unknown-pragmas  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/computeSAD.d

$(ObjDir)/correlateSAD_2D.o: ../../../../../src_fixed_vga/correlateSAD_2D.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../src_fixed_vga/correlateSAD_2D.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD -Wno-unknown-pragmas -Wno-unknown-pragmas  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/correlateSAD_2D.d

$(ObjDir)/fDeepCopy.o: ../../../../../src_fixed_vga/fDeepCopy.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../src_fixed_vga/fDeepCopy.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD -Wno-unknown-pragmas -Wno-unknown-pragmas  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/fDeepCopy.d

$(ObjDir)/fFreeHandle.o: ../../../../../src_fixed_vga/fFreeHandle.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../src_fixed_vga/fFreeHandle.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD -Wno-unknown-pragmas -Wno-unknown-pragmas  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/fFreeHandle.d

$(ObjDir)/fMallocHandle.o: ../../../../../src_fixed_vga/fMallocHandle.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../src_fixed_vga/fMallocHandle.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD -Wno-unknown-pragmas -Wno-unknown-pragmas  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/fMallocHandle.d

$(ObjDir)/fSetArray.o: ../../../../../src_fixed_vga/fSetArray.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../src_fixed_vga/fSetArray.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD -Wno-unknown-pragmas -Wno-unknown-pragmas  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/fSetArray.d

$(ObjDir)/ffDivide.o: ../../../../../src_fixed_vga/ffDivide.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../src_fixed_vga/ffDivide.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD -Wno-unknown-pragmas -Wno-unknown-pragmas  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/ffDivide.d

$(ObjDir)/finalSAD.o: ../../../../../src_fixed_vga/finalSAD.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../src_fixed_vga/finalSAD.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD -Wno-unknown-pragmas -Wno-unknown-pragmas  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/finalSAD.d

$(ObjDir)/findDisparity.o: ../../../../../src_fixed_vga/findDisparity.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../src_fixed_vga/findDisparity.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD -Wno-unknown-pragmas -Wno-unknown-pragmas  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/findDisparity.d

$(ObjDir)/getDisparity.o: ../../../../../src_fixed_vga/getDisparity.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../src_fixed_vga/getDisparity.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD -Wno-unknown-pragmas -Wno-unknown-pragmas  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/getDisparity.d

$(ObjDir)/iFreeHandle.o: ../../../../../src_fixed_vga/iFreeHandle.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../src_fixed_vga/iFreeHandle.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD -Wno-unknown-pragmas -Wno-unknown-pragmas  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/iFreeHandle.d

$(ObjDir)/iMallocHandle.o: ../../../../../src_fixed_vga/iMallocHandle.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../src_fixed_vga/iMallocHandle.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD -Wno-unknown-pragmas -Wno-unknown-pragmas  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/iMallocHandle.d

$(ObjDir)/iSetArray.o: ../../../../../src_fixed_vga/iSetArray.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../src_fixed_vga/iSetArray.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD -Wno-unknown-pragmas -Wno-unknown-pragmas  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/iSetArray.d

$(ObjDir)/integralImage2D2D.o: ../../../../../src_fixed_vga/integralImage2D2D.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../src_fixed_vga/integralImage2D2D.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD -Wno-unknown-pragmas -Wno-unknown-pragmas  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/integralImage2D2D.d

$(ObjDir)/padarray2.o: ../../../../../src_fixed_vga/padarray2.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../src_fixed_vga/padarray2.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD -Wno-unknown-pragmas -Wno-unknown-pragmas  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/padarray2.d

$(ObjDir)/padarray4.o: ../../../../../src_fixed_vga/padarray4.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../src_fixed_vga/padarray4.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD -Wno-unknown-pragmas -Wno-unknown-pragmas  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/padarray4.d

$(ObjDir)/photonEndTiming.o: ../../../../../src_fixed_vga/photonEndTiming.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../src_fixed_vga/photonEndTiming.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD -Wno-unknown-pragmas -Wno-unknown-pragmas  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/photonEndTiming.d

$(ObjDir)/photonPrintTiming.o: ../../../../../src_fixed_vga/photonPrintTiming.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../src_fixed_vga/photonPrintTiming.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD -Wno-unknown-pragmas -Wno-unknown-pragmas  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/photonPrintTiming.d

$(ObjDir)/photonReportTiming.o: ../../../../../src_fixed_vga/photonReportTiming.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../src_fixed_vga/photonReportTiming.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD -Wno-unknown-pragmas -Wno-unknown-pragmas  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/photonReportTiming.d

$(ObjDir)/photonStartTiming.o: ../../../../../src_fixed_vga/photonStartTiming.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../src_fixed_vga/photonStartTiming.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD -Wno-unknown-pragmas -Wno-unknown-pragmas  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/photonStartTiming.d

$(ObjDir)/readImage.o: ../../../../../src_fixed_vga/readImage.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../src_fixed_vga/readImage.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD -Wno-unknown-pragmas -Wno-unknown-pragmas  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/readImage.d

$(ObjDir)/script_disparity.o: ../../../../../src_fixed_vga/script_disparity.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../src_fixed_vga/script_disparity.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD -Wno-unknown-pragmas -Wno-unknown-pragmas  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/script_disparity.d

$(ObjDir)/foo.o: ../../../../foo.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../foo.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/foo.d
