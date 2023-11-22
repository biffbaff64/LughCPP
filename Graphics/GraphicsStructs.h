#ifndef GRAPHICSSTRUCTS_H
#define GRAPHICSSTRUCTS_H

struct DisplayMode
{
    int width;
    int height;
    int refresh_rate;
    int bits_per_pixel;
};

struct Monitor
{
    int   virtualx;
    int   virtualy;
    char* name;
};

struct BufferFormat
{
    int  r;
    int  g;
    int  b;
    int  a;
    int  depth;
    int  stencil;
    int  samples;
    bool coverage_sampling;
};

#endif //GRAPHICSSTRUCTS_H
