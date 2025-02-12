// ==============================================================
// File generated on Sat Sep 21 15:13:34 -0400 2019
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XCONVOLVE_KERNEL_H
#define XCONVOLVE_KERNEL_H

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
#include "xconvolve_kernel_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else
typedef struct {
    u16 DeviceId;
    u32 Control_BaseAddress;
} XConvolve_kernel_Config;
#endif

typedef struct {
    u32 Control_BaseAddress;
    u32 IsReady;
} XConvolve_kernel;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XConvolve_kernel_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XConvolve_kernel_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XConvolve_kernel_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XConvolve_kernel_ReadReg(BaseAddress, RegOffset) \
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
int XConvolve_kernel_Initialize(XConvolve_kernel *InstancePtr, u16 DeviceId);
XConvolve_kernel_Config* XConvolve_kernel_LookupConfig(u16 DeviceId);
int XConvolve_kernel_CfgInitialize(XConvolve_kernel *InstancePtr, XConvolve_kernel_Config *ConfigPtr);
#else
int XConvolve_kernel_Initialize(XConvolve_kernel *InstancePtr, const char* InstanceName);
int XConvolve_kernel_Release(XConvolve_kernel *InstancePtr);
#endif

void XConvolve_kernel_Start(XConvolve_kernel *InstancePtr);
u32 XConvolve_kernel_IsDone(XConvolve_kernel *InstancePtr);
u32 XConvolve_kernel_IsIdle(XConvolve_kernel *InstancePtr);
u32 XConvolve_kernel_IsReady(XConvolve_kernel *InstancePtr);
void XConvolve_kernel_EnableAutoRestart(XConvolve_kernel *InstancePtr);
void XConvolve_kernel_DisableAutoRestart(XConvolve_kernel *InstancePtr);


void XConvolve_kernel_InterruptGlobalEnable(XConvolve_kernel *InstancePtr);
void XConvolve_kernel_InterruptGlobalDisable(XConvolve_kernel *InstancePtr);
void XConvolve_kernel_InterruptEnable(XConvolve_kernel *InstancePtr, u32 Mask);
void XConvolve_kernel_InterruptDisable(XConvolve_kernel *InstancePtr, u32 Mask);
void XConvolve_kernel_InterruptClear(XConvolve_kernel *InstancePtr, u32 Mask);
u32 XConvolve_kernel_InterruptGetEnabled(XConvolve_kernel *InstancePtr);
u32 XConvolve_kernel_InterruptGetStatus(XConvolve_kernel *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
