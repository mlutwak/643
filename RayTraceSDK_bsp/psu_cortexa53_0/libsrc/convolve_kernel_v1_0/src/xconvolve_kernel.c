// ==============================================================
// File generated on Sat Sep 21 15:13:34 -0400 2019
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xconvolve_kernel.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XConvolve_kernel_CfgInitialize(XConvolve_kernel *InstancePtr, XConvolve_kernel_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XConvolve_kernel_Start(XConvolve_kernel *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConvolve_kernel_ReadReg(InstancePtr->Control_BaseAddress, XCONVOLVE_KERNEL_CONTROL_ADDR_AP_CTRL) & 0x80;
    XConvolve_kernel_WriteReg(InstancePtr->Control_BaseAddress, XCONVOLVE_KERNEL_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XConvolve_kernel_IsDone(XConvolve_kernel *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConvolve_kernel_ReadReg(InstancePtr->Control_BaseAddress, XCONVOLVE_KERNEL_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XConvolve_kernel_IsIdle(XConvolve_kernel *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConvolve_kernel_ReadReg(InstancePtr->Control_BaseAddress, XCONVOLVE_KERNEL_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XConvolve_kernel_IsReady(XConvolve_kernel *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConvolve_kernel_ReadReg(InstancePtr->Control_BaseAddress, XCONVOLVE_KERNEL_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XConvolve_kernel_EnableAutoRestart(XConvolve_kernel *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConvolve_kernel_WriteReg(InstancePtr->Control_BaseAddress, XCONVOLVE_KERNEL_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XConvolve_kernel_DisableAutoRestart(XConvolve_kernel *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConvolve_kernel_WriteReg(InstancePtr->Control_BaseAddress, XCONVOLVE_KERNEL_CONTROL_ADDR_AP_CTRL, 0);
}

void XConvolve_kernel_InterruptGlobalEnable(XConvolve_kernel *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConvolve_kernel_WriteReg(InstancePtr->Control_BaseAddress, XCONVOLVE_KERNEL_CONTROL_ADDR_GIE, 1);
}

void XConvolve_kernel_InterruptGlobalDisable(XConvolve_kernel *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConvolve_kernel_WriteReg(InstancePtr->Control_BaseAddress, XCONVOLVE_KERNEL_CONTROL_ADDR_GIE, 0);
}

void XConvolve_kernel_InterruptEnable(XConvolve_kernel *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XConvolve_kernel_ReadReg(InstancePtr->Control_BaseAddress, XCONVOLVE_KERNEL_CONTROL_ADDR_IER);
    XConvolve_kernel_WriteReg(InstancePtr->Control_BaseAddress, XCONVOLVE_KERNEL_CONTROL_ADDR_IER, Register | Mask);
}

void XConvolve_kernel_InterruptDisable(XConvolve_kernel *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XConvolve_kernel_ReadReg(InstancePtr->Control_BaseAddress, XCONVOLVE_KERNEL_CONTROL_ADDR_IER);
    XConvolve_kernel_WriteReg(InstancePtr->Control_BaseAddress, XCONVOLVE_KERNEL_CONTROL_ADDR_IER, Register & (~Mask));
}

void XConvolve_kernel_InterruptClear(XConvolve_kernel *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConvolve_kernel_WriteReg(InstancePtr->Control_BaseAddress, XCONVOLVE_KERNEL_CONTROL_ADDR_ISR, Mask);
}

u32 XConvolve_kernel_InterruptGetEnabled(XConvolve_kernel *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XConvolve_kernel_ReadReg(InstancePtr->Control_BaseAddress, XCONVOLVE_KERNEL_CONTROL_ADDR_IER);
}

u32 XConvolve_kernel_InterruptGetStatus(XConvolve_kernel *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XConvolve_kernel_ReadReg(InstancePtr->Control_BaseAddress, XCONVOLVE_KERNEL_CONTROL_ADDR_ISR);
}

