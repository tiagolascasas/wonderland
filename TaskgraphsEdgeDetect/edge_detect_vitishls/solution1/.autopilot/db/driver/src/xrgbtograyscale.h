// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.1 (64-bit)
// Tool Version Limit: 2022.04
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XRGBTOGRAYSCALE_H
#define XRGBTOGRAYSCALE_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xrgbtograyscale_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
#else
typedef struct {
    u16 DeviceId;
    u64 Control_BaseAddress;
} XRgbtograyscale_Config;
#endif

typedef struct {
    u64 Control_BaseAddress;
    u32 IsReady;
} XRgbtograyscale;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XRgbtograyscale_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XRgbtograyscale_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XRgbtograyscale_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XRgbtograyscale_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XRgbtograyscale_Initialize(XRgbtograyscale *InstancePtr, u16 DeviceId);
XRgbtograyscale_Config* XRgbtograyscale_LookupConfig(u16 DeviceId);
int XRgbtograyscale_CfgInitialize(XRgbtograyscale *InstancePtr, XRgbtograyscale_Config *ConfigPtr);
#else
int XRgbtograyscale_Initialize(XRgbtograyscale *InstancePtr, const char* InstanceName);
int XRgbtograyscale_Release(XRgbtograyscale *InstancePtr);
#endif

void XRgbtograyscale_Start(XRgbtograyscale *InstancePtr);
u32 XRgbtograyscale_IsDone(XRgbtograyscale *InstancePtr);
u32 XRgbtograyscale_IsIdle(XRgbtograyscale *InstancePtr);
u32 XRgbtograyscale_IsReady(XRgbtograyscale *InstancePtr);
void XRgbtograyscale_Continue(XRgbtograyscale *InstancePtr);
void XRgbtograyscale_EnableAutoRestart(XRgbtograyscale *InstancePtr);
void XRgbtograyscale_DisableAutoRestart(XRgbtograyscale *InstancePtr);

void XRgbtograyscale_Set_input_image(XRgbtograyscale *InstancePtr, u64 Data);
u64 XRgbtograyscale_Get_input_image(XRgbtograyscale *InstancePtr);
void XRgbtograyscale_Set_output_image(XRgbtograyscale *InstancePtr, u64 Data);
u64 XRgbtograyscale_Get_output_image(XRgbtograyscale *InstancePtr);

void XRgbtograyscale_InterruptGlobalEnable(XRgbtograyscale *InstancePtr);
void XRgbtograyscale_InterruptGlobalDisable(XRgbtograyscale *InstancePtr);
void XRgbtograyscale_InterruptEnable(XRgbtograyscale *InstancePtr, u32 Mask);
void XRgbtograyscale_InterruptDisable(XRgbtograyscale *InstancePtr, u32 Mask);
void XRgbtograyscale_InterruptClear(XRgbtograyscale *InstancePtr, u32 Mask);
u32 XRgbtograyscale_InterruptGetEnabled(XRgbtograyscale *InstancePtr);
u32 XRgbtograyscale_InterruptGetStatus(XRgbtograyscale *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
