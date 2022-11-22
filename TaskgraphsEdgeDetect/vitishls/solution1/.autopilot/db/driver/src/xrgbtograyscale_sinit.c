// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.1 (64-bit)
// Tool Version Limit: 2022.04
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xrgbtograyscale.h"

extern XRgbtograyscale_Config XRgbtograyscale_ConfigTable[];

XRgbtograyscale_Config *XRgbtograyscale_LookupConfig(u16 DeviceId) {
	XRgbtograyscale_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XRGBTOGRAYSCALE_NUM_INSTANCES; Index++) {
		if (XRgbtograyscale_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XRgbtograyscale_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XRgbtograyscale_Initialize(XRgbtograyscale *InstancePtr, u16 DeviceId) {
	XRgbtograyscale_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XRgbtograyscale_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XRgbtograyscale_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

