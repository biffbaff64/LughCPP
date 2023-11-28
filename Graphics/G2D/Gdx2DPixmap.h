#ifndef GDX2DPIXMAP_H
#define GDX2DPIXMAP_H

#include "../../Files/Buffers/ByteBuffer.h"

class Gdx2DPixmap
{
public:
    const int GDX_2D_FORMAT_ALPHA           = 1;
    const int GDX_2D_FORMAT_LUMINANCE_ALPHA = 2;
    const int GDX_2D_FORMAT_RGB888          = 3;
    const int GDX_2D_FORMAT_RGBA8888        = 4;
    const int GDX_2D_FORMAT_RGB565          = 5;
    const int GDX_2D_FORMAT_RGBA4444        = 6;
    const int GDX_2D_SCALE_NEAREST          = 0;
    const int GDX_2D_SCALE_LINEAR           = 1;
    const int GDX_2D_BLEND_NONE             = 0;
    const int GDX_2D_BLEND_SRC_OVER         = 1;

    /**
     * \brief
     * \param encodedData
     * \param offset
     * \param len
     * \param requestedFormat
     */
    Gdx2DPixmap( int encodedData[ ], int offset, int len, int requestedFormat );

    /**
     * \brief 
     * \param inStream 
     * \param requestedFormat
     */
    Gdx2DPixmap( StreamReader inStream, int requestedFormat );

    /**
     * \brief
     * \param width
     * \param height
     * \param format
     */
    Gdx2DPixmap( int width, int height, int format );

    /**
     * \brief
     * \param pixelPtr
     * \param nativeData
     */
    Gdx2DPixmap( ByteBuffer pixelPtr, long nativeData[ ] );

    static int ToGLFormat( int format );
    static int ToGLType( int format );

    void Clear( int color );
    int  GetPixel( int x, int y );
    void SetPixel( int x, int y, int color );

    void DrawLine( int x, int y, int x2, int y2, int color );
    void DrawRect( int x, int y, int width, int height, int color );
    void DrawCircle( int x, int y, int radius, int color );
    void FillRect( int x, int y, int width, int height, int color );
    void FillCircle( int x, int y, int radius, int color );
    void FillTriangle( int x1, int y1, int x2, int y2, int x3, int y3, int color );
    void DrawPixmap( Gdx2DPixmap src, int srcX, int srcY, int dstX, int dstY, int width, int height );
    void DrawPixmap( Gdx2DPixmap src,
                     int         srcX,
                     int         srcY,
                     int         srcWidth,
                     int         srcHeight,
                     int         dstX,
                     int         dstY,
                     int         dstWidth,
                     int         dstHeight );

    void SetBlend( long src, int scale );
    void SetScale( long src, int scale );

    static Gdx2DPixmap NewPixmap( StreamReader inStream, int requestedFormat );
    static Gdx2DPixmap NewPixmap( int width, int height, int format );

    static char* GetFormatString( int format );

    /**
     * \brief Performs application-defined tasks associated with freeing,
     * releasing, or resetting unmanaged resources.
     */
    void Dispose( bool disposing );

    /**
     * \brief Performs application-defined tasks associated with freeing,
     * releasing, or resetting unmanaged resources.
     */
    void Dispose();

private:
    void Convert( int requestedFormat );

    int        blend;
    int        scale;
    long       base_ptr;
    int        format;
    ByteBuffer pixel_ptr;
    long       native_data[ ];
};

#endif //GDX2DPIXMAP_H
