#ifndef FILTER_H
#define FILTER_H

#include "buffer.h"

class Filter {
public:
    virtual void apply(FrameBuffer* in, FrameBuffer* out) = 0;
    virtual ~Filter() {}
};

#endif
