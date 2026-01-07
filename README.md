# FPGA-Based Image Processing Pipeline Simulator

> **C++ Hardware Accelerator Model | Ubuntu Linux | IC Design Training Mega Project**

---

## Overview

This project implements a **hardware-style image processing pipeline simulator** in C++. It models the architecture and dataflow typically used in **FPGA/SoC-based embedded vision systems** (e.g., Xilinx, Intel, NVIDIA).

The design follows a **hardware modeling mindset** using buffers, FIFOs, registers, and modular pipeline stages.

---

## Pipeline Architecture

```
Load → RGB to Grayscale → Smoothing Filter → Convolution (Sobel/Gaussian/Sharpen) → Save
```

Each stage is implemented as an independent module, similar to hardware IP cores.

---

## Key Features

* **Modular Pipeline Design** (Frame Reader, Converter, Filters, Convolution Engine, Writer)
* **Struct-based Hardware Modeling** (`Pixel`, `Buffer`, `Kernel`)
* **Dynamic Memory Management** (heap-based frame buffers)
* **OOP & Polymorphism** (base `Filter` class with derived filters)
* **Compile-Time Modes** using `#ifdef` (DEBUG, FPGA_MODE, FIXED_POINT)
* **Makefile-based Build System**
* **Multi-file Project Structure** (industry-style)

---

## Technologies & Concepts

* C++ (OOP, Templates, Pointers)
* Hardware-style dataflow modeling
* Dynamic memory (new/delete, malloc/free)
* Function pointers for dynamic filter selection
* Namespaces for clean architecture
* Linux (Ubuntu) development environment

---

## Project Structure

```
FPGA-Image-Pipeline/
├── src/        # Source files
├── include/   # Header files
├── input image
├── output image
├── Makefile
└── README.md
```

---

## Build & Run (Ubuntu)

```bash
make
./pipeline
```

### Debug Mode

```bash
make DEBUG=1
```

---

## Design Philosophy

This project is written with **hardware thinking**:

* Buffers → BRAM
* FIFOs → Streams
* Modules → IP Cores
* Pipeline → Dataflow Architecture
* Registers → Variables

---

## Implemented Advanced Features

* DMA / Streaming simulation
* Multi-threaded processing
* Fixed-point data type modeling
* OpenCV verification
* CLI-based pipeline control

---
## Input Image
<img width="296" height="443" alt="image" src="https://github.com/user-attachments/assets/efbb2949-0213-4fe6-b7e3-0770049b6e89" />

---
## output Image
<img width="289" height="440" alt="image" src="https://github.com/user-attachments/assets/c36827d8-f0e7-4a0f-a85d-6883e0f215b2" />

## Author

**Muhammad Shahid Saeed**
Electronics Engineering Student – IC Design Training
Developed on Ubuntu Linux

---

> *"Think in hardware. Implement in software."*

