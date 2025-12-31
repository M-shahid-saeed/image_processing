Image Convolution Hardware Accelerator (FPGA)
Project Overview

This project implements a hardware accelerator for 2D image convolution using SystemVerilog on an FPGA.
The goal is to speed up image processing by performing convolution in parallel hardware instead of software.

This project is designed for beginners in hardware-based image processing and focuses on clear architecture and verification.

Objectives

Implement 2D convolution in hardware

Use parallel MAC (Multiply-Accumulate) operations

Verify functionality using SystemVerilog testbench

Understand how hardware accelerators improve performance

 Concept Used

Image Convolution

Parallel Processing

DSP Slices for MAC operations

Hardware Acceleration

RTL Design & Verification

 Image & Kernel Details

Input Image Size: 12 × 12 (Grayscale)

Pixel Depth: 8-bit (1 byte per pixel)

Kernel Size: 5 × 5

Stride: 1

Output Size: 8 × 8

 Architecture

Input image stored in memory

Kernel stored in registers

25 parallel multipliers (for 5×5 kernel)

Adder tree for accumulation

Output stored in output buffer

Input Image → MAC Units → Adder Tree → Output Memory
