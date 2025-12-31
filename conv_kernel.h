#ifndef CONV_KERNEL_H
#define CONV_KERNEL_H

struct ConvKernel {
    int size;           // Kernel size (e.g., 3)
    int coeff[3][3];    // Kernel coefficients (registers)
    int scale;          // Normalization factor
};

#endif
