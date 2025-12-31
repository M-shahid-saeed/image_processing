#include "buffer.h"
#include <iostream>

void dumpHex(FrameBuffer* fb, int count=10){
    for(int i=0; i<count; i++){
        std::cout << std::hex
                  << (int)fb->data[i].r << " "
                  << (int)fb->data[i].g << " "
                  << (int)fb->data[i].b << "\n";
    }
}
