#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "buffer.h"
#include <iostream>

FrameBuffer* loadPNG(const char* filename) {
    int w,h,ch;
    unsigned char* img = stbi_load(filename, &w, &h, &ch, 3);
    if(!img) {
        std::cout << "Cannot open " << filename << "\n";
        return nullptr;
    }

    FrameBuffer* fb = new FrameBuffer;
    fb->width = w;
    fb->height = h;
    fb->data = new Pixel[w*h];

    for(int i=0; i<w*h; i++){
        fb->data[i].r = img[i*3 + 0];
        fb->data[i].g = img[i*3 + 1];
        fb->data[i].b = img[i*3 + 2];
    }

    stbi_image_free(img);
    return fb;
}
