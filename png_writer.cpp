#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include "buffer.h"

void savePNG(const char* filename, FrameBuffer* fb){
    stbi_write_png(filename, fb->width, fb->height, 3, fb->data, fb->width*3);
}
