#include "conv_kernel.h"

ConvKernel SOBEL_X = {
    3,
    {{-1,0,1}, {-2,0,2}, {-1,0,1}},
    1
};

ConvKernel BLUR = {
    3,
    {{1,1,1}, {1,1,1}, {1,1,1}},
    9
};
