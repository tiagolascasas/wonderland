// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.1 (64-bit)
// Tool Version Limit: 2022.04
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xrgbtograyscale.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XRgbtograyscale_CfgInitialize(XRgbtograyscale *InstancePtr, XRgbtograyscale_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XRgbtograyscale_Start(XRgbtograyscale *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XRgbtograyscale_ReadReg(InstancePtr->Control_BaseAddress, XRGBTOGRAYSCALE_CONTROL_ADDR_AP_CTRL) & 0x80;
    XRgbtograyscale_WriteReg(InstancePtr->Control_BaseAddress, XRGBTOGRAYSCALE_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XRgbtograyscale_IsDone(XRgbtograyscale *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XRgbtograyscale_ReadReg(InstancePtr->Control_BaseAddress, XRGBTOGRAYSCALE_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XRgbtograyscale_IsIdle(XRgbtograyscale *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XRgbtograyscale_ReadReg(InstancePtr->Control_BaseAddress, XRGBTOGRAYSCALE_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XRgbtograyscale_IsReady(XRgbtograyscale *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XRgbtograyscale_ReadReg(InstancePtr->Control_BaseAddress, XRGBTOGRAYSCALE_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XRgbtograyscale_Continue(XRgbtograyscale *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XRgbtograyscale_ReadReg(InstancePtr->Control_BaseAddress, XRGBTOGRAYSCALE_CONTROL_ADDR_AP_CTRL) & 0x80;
    XRgbtograyscale_WriteReg(InstancePtr->Control_BaseAddress, XRGBTOGRAYSCALE_CONTROL_ADDR_AP_CTRL, Data | 0x10);
}

void XRgbtograyscale_EnableAutoRestart(XRgbtograyscale *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XRgbtograyscale_WriteReg(InstancePtr->Control_BaseAddress, XRGBTOGRAYSCALE_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XRgbtograyscale_DisableAutoRestart(XRgbtograyscale *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XRgbtograyscale_WriteReg(InstancePtr->Control_BaseAddress, XRGBTOGRAYSCALE_CONTROL_ADDR_AP_CTRL, 0);
}

void XRgbtograyscale_Set_input_image(XRgbtograyscale *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XRgbtograyscale_WriteReg(InstancePtr->Control_BaseAddress, XRGBTOGRAYSCALE_CONTROL_ADDR_INPUT_IMAGE_DATA, (u32)(Data));
    XRgbtograyscale_WriteReg(InstancePtr->Control_BaseAddress, XRGBTOGRAYSCALE_CONTROL_ADDR_INPUT_IMAGE_DATA + 4, (u32)(Data >> 32));
}

u64 XRgbtograyscale_Get_input_image(XRgbtograyscale *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XRgbtograyscale_ReadReg(InstancePtr->Control_BaseAddress, XRGBTOGRAYSCALE_CONTROL_ADDR_INPUT_IMAGE_DATA);
    Data += (u64)XRgbtograyscale_ReadReg(InstancePtr->Control_BaseAddress, XRGBTOGRAYSCALE_CONTROL_ADDR_INPUT_IMAGE_DATA + 4) << 32;
    return Data;
}

void XRgbtograyscale_Set_output_image(XRgbtograyscale *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XRgbtograyscale_WriteReg(InstancePtr->Control_BaseAddress, XRGBTOGRAYSCALE_CONTROL_ADDR_OUTPUT_IMAGE_DATA, (u32)(Data));
    XRgbtograyscale_WriteReg(InstancePtr->Control_BaseAddress, XRGBTOGRAYSCALE_CONTROL_ADDR_OUTPUT_IMAGE_DATA + 4, (u32)(Data >> 32));
}

u64 XRgbtograyscale_Get_output_image(XRgbtograyscale *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XRgbtograyscale_ReadReg(InstancePtr->Control_BaseAddress, XRGBTOGRAYSCALE_CONTROL_ADDR_OUTPUT_IMAGE_DATA);
    Data += (u64)XRgbtograyscale_ReadReg(InstancePtr->Control_BaseAddress, XRGBTOGRAYSCALE_CONTROL_ADDR_OUTPUT_IMAGE_DATA + 4) << 32;
    return Data;
}

void XRgbtograyscale_InterruptGlobalEnable(XRgbtograyscale *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XRgbtograyscale_WriteReg(InstancePtr->Control_BaseAddress, XRGBTOGRAYSCALE_CONTROL_ADDR_GIE, 1);
}

void XRgbtograyscale_InterruptGlobalDisable(XRgbtograyscale *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XRgbtograyscale_WriteReg(InstancePtr->Control_BaseAddress, XRGBTOGRAYSCALE_CONTROL_ADDR_GIE, 0);
}

void XRgbtograyscale_InterruptEnable(XRgbtograyscale *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XRgbtograyscale_ReadReg(InstancePtr->Control_BaseAddress, XRGBTOGRAYSCALE_CONTROL_ADDR_IER);
    XRgbtograyscale_WriteReg(InstancePtr->Control_BaseAddress, XRGBTOGRAYSCALE_CONTROL_ADDR_IER, Register | Mask);
}

void XRgbtograyscale_InterruptDisable(XRgbtograyscale *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XRgbtograyscale_ReadReg(InstancePtr->Control_BaseAddress, XRGBTOGRAYSCALE_CONTROL_ADDR_IER);
    XRgbtograyscale_WriteReg(InstancePtr->Control_BaseAddress, XRGBTOGRAYSCALE_CONTROL_ADDR_IER, Register & (~Mask));
}

void XRgbtograyscale_InterruptClear(XRgbtograyscale *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    //XRgbtograyscale_WriteReg(InstancePtr->Control_BaseAddress, XRGBTOGRAYSCALE_CONTROL_ADDR_ISR, Mask);
}

u32 XRgbtograyscale_InterruptGetEnabled(XRgbtograyscale *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XRgbtograyscale_ReadReg(InstancePtr->Control_BaseAddress, XRGBTOGRAYSCALE_CONTROL_ADDR_IER);
}

u32 XRgbtograyscale_InterruptGetStatus(XRgbtograyscale *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    // Current Interrupt Clear Behavior is Clear on Read(COR).
    return XRgbtograyscale_ReadReg(InstancePtr->Control_BaseAddress, XRGBTOGRAYSCALE_CONTROL_ADDR_ISR);
}

