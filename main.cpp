#include <iostream>
#include <string>
#include "buffer.h"
#include "conv_kernel.h"

FrameBuffer* loadPNG(const char*);
void savePNG(const char*, FrameBuffer*);
void dumpHex(FrameBuffer*, int count);
void runPipeline(FrameBuffer*, FrameBuffer*, const std::string& filterName);

extern ConvKernel SOBEL_X;
extern ConvKernel BLUR;

int main(int argc, char* argv[]){
    if(argc < 5){
        std::cout << "Usage: ./pipeline -i input.png -o output.png -filter [sobel|blur]\n";
        return 0;
    }

    std::string inputFile, outputFile, filterName;
    for(int i=1;i<argc;i++){
        std::string arg = argv[i];
        if(arg=="-i") inputFile = argv[++i];
        else if(arg=="-o") outputFile = argv[++i];
        else if(arg=="-filter") filterName = argv[++i];
    }

    FrameBuffer* in = loadPNG(inputFile.c_str());
    if(!in) return -1;

    FrameBuffer* out = new FrameBuffer;
    out->width = in->width;
    out->height = in->height;
    out->data = new Pixel[out->width*out->height];

    dumpHex(in,5); // optional HEX debug
    runPipeline(in,out,filterName);
    savePNG(outputFile.c_str(),out);

    std::cout << "Pipeline finished. Output saved to " << outputFile << "\n";

    delete[] in->data; delete in;
    delete[] out->data; delete out;
    return 0;
}
