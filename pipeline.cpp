#include <iostream>
#include "buffer.h"
#include "conv_kernel.h"

extern ConvKernel SOBEL_X;
extern ConvKernel BLUR;

void runPipeline(FrameBuffer* in, FrameBuffer* out, const std::string& filterName){

    // Step 1: Grayscale conversionh
    for(int i=0; i<in->width*in->height; i++){
        uint8_t gray = (in->data[i].r + in->data[i].g + in->data[i].b)/3;
        in->data[i].r = in->data[i].g = in->data[i].b = gray;
    }

    // Step 2: Select kernel
    ConvKernel* kernel = (filterName=="sobel") ? &SOBEL_X : &BLUR;

    int w = in->width;
    int h = in->height;

    // Step 3: Row-by-row processing (simulate streaming/DMA)
    for(int y=1; y<h-1; y++){
        for(int x=1; x<w-1; x++){
            int acc=0;
            for(int ky=0; ky<3; ky++){
                for(int kx=0; kx<3; kx++){
                    int ix = x + kx -1;
                    int iy = y + ky -1;
                    int pixel = in->data[iy*w + ix].r;
                    acc += pixel * kernel->coeff[ky][kx];
                }
            }
            acc /= kernel->scale;
            if(acc<0) acc=0;
            if(acc>255) acc=255;

            out->data[y*w + x].r = out->data[y*w + x].g = out->data[y*w + x].b = acc;
        }

        // Display progress every 50 rows
        if(y%50==0) std::cout << "Processed row " << y << "/" << h << "\n";
    }
}
