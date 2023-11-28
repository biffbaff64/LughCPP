#ifndef PIXMAPFORMAT_H
#define PIXMAPFORMAT_H
#include "Pixmap.h"

class PixmapFormat
{
public:
    static int            ToGdx2DPixmapFormat( Pixmap::Format format );
    static Pixmap::Format FromGdx2DPixmapFormat( int format );
    static int            ToGLFormat( Pixmap::Format format );
    static int            ToGLType( Pixmap::Format format );

private:
    PixmapFormat()  = default;
    ~PixmapFormat() = default;
};

#endif //PIXMAPFORMAT_H
