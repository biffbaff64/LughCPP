#ifndef PIXMAP_H
#define PIXMAP_H

#include <cstdio>

#include "Color.h"
#include "IDownloadPixmapResponseListener.h"
#include "../Files/Buffers/ByteBuffer.h"
#include "G2D/Gdx2DPixmap.h"

class Pixmap
{
public:
    enum BlendTypes
    {
        None,
        SourceOver
    };

    enum Filter
    {
        NearestNeighbour,
        Bilinear
    };

    enum Format
    {
        Alpha,
        Intensity,
        LuminanceAlpha,
        RGB565,
        RGBA4444,
        RGB888,
        RGBA8888
    };

    Pixmap() = default;
    virtual  ~Pixmap() = default;

    /**
     * \brief Creates a new Pixmap instance with the given width, height and format.
     * \param width The width in pixels.
     * \param height The height in pixels.
     * \param format The Pixmap.Format
     */
    Pixmap( int width, int height, Format format );

    /**
     * \brief Creates a new Pixmap instance from the given encoded image data.
     * The image can be encoded as JPEG, PNG or BMP.
     */
    Pixmap( int encoded_data[ ], int offset, int len );

    /**
     * \brief Creates a new Pixmap instance from the given file. The file must
     * be a Png, Jpeg or Bitmap. Paletted formats are not supported.
     */
    explicit Pixmap( FILE* file );

    /**
     * \brief Creates a new Pixmap from the supplied Gdx2DPixmap.
     */
    explicit Pixmap( Gdx2DPixmap &pixmap );

    /**
     * \brief Downloads an image from http(s) url and passes it as a Pixmap
     * to the specified IDownloadPixmapResponseListener
     * \param url http url to download the image from.
     * \param responseListener the listener to call once the image is available as a Pixmap
     */
    virtual void DownloadFromUrl( char* url, IDownloadPixmapResponseListener &responseListener );

    /**
     * \brief Sets the color for drawing operations.
     */
    virtual void SetColor( int color );

    /**
     * \brief Sets the color for drawing operations.
     */
    virtual void SetColor( float r, float g, float b, float a );

    /**
     * \brief Sets the color for drawing operations.
     */
    virtual void SetColor( Color* color );

    /**
     * \brief Fills the complete bitmap with the currently set color.
     */
    virtual void FillWithCurrentColor();

    /**
     * \brief Draws a line between the given coordinates using the currently set color.
     */
    virtual void DrawLine( int x, int y, int x2, int y2 );

    /**
     * \brief Draws a rectangle outline starting at x, y extending by width
     * to the right and by height downwards (y-axis points downwards) using
     * the current color.
     */
    virtual void DrawRectangle( int x, int y, int width, int height );

    /**
     * \brief Draws an area from another Pixmap to this Pixmap.
     * \param pixmap The other Pixmap
     * \param x The target x-coordinate (top left corner)
     * \param y The target y-coordinate (top left corner)
     */
    virtual void DrawPixmap( Pixmap* pixmap, int x, int y );

    /**
     * \brief Draws an area from another Pixmap to this Pixmap.
     * \param pixmap The other Pixmap
     * \param x The target x-coordinate (top left corner)
     * \param y The target y-coordinate (top left corner)
     * \param srcx The source x-coordinate (top left corner)
     * \param srcy The source y-coordinate (top left corner)
     * \param srcWidth The width of the area from the other Pixmap in pixels
     * \param srcHeight The height of the area from the other Pixmap in pixels
     */
    virtual void DrawPixmap( Pixmap* pixmap, int x, int y, int srcx, int srcy, int srcWidth, int srcHeight );

    /**
     * \brief Draws an area from another Pixmap to this Pixmap.
     * This will automatically scale and stretch the source image to the specified
     * target rectangle.
     * Use Filter property to specify the type of filtering to be used (NearestNeighbour
     * or Bilinear).
     * \param pixmap The other Pixmap.
     * \param srcx The source x-coordinate (top left corner)
     * \param srcy The source y-coordinate (top left corner)
     * \param srcWidth The width of the area from the other Pixmap in pixels
     * \param srcHeight The height of the area from the other Pixmap in pixels
     * \param dstx The target x-coordinate (top left corner)
     * \param dsty The target y-coordinate (top left corner)
     * \param dstWidth The target width
     * \param dstHeight the target height
     */
    virtual void DrawPixmap( Pixmap* pixmap,
                             int     srcx,
                             int     srcy,
                             int     srcWidth,
                             int     srcHeight,
                             int     dstx,
                             int     dsty,
                             int     dstWidth,
                             int     dstHeight );

    /**
     * \brief Fills a rectangle starting at x, y extending by width to the right
     * and by height downwards (y-axis points downwards) using the current color.
     */
    virtual void FillRectangle( int x, int y, int width, int height );

    /**
     * \brief Draws a circle outline with the center at x,y and a radius using
     * the current color and stroke width.
     */
    virtual void DrawCircle( int x, int y, int radius );
    virtual void FillCircle( int x, int y, int radius );
    virtual void FillTriangle( int x1, int y1, int x2, int y2, int x3, int y3 );
    virtual int  GetPixel( int x, int y );

    /**
     * \brief Draws a pixel at the given location with the current color.
     */
    virtual void DrawPixel( int x, int y );

    /**
     * \brief Draws a pixel at the given location with the given color.
     */
    virtual void DrawPixel( int x, int y, int color );

    virtual int GetWidth() const;
    virtual int GetHeight() const;

    BlendTypes GetBlending();
    Filter GetFilter();

    void SetBlending( BlendTypes blend );
    void SetFilter( Filter filter );

    /**
     * \brief Returns the OpenGL ES internal format of this Pixmap.
     * \return one of GL_ALPHA, GL_RGB, GL_RGBA, GL_LUMINANCE, or GL_LUMINANCE_ALPHA.
     */
    virtual int GetGLFormat() const;

    /**
     * \brief Returns the OpenGL ES internal format of this Pixmap.
     * \return one of GL_ALPHA, GL_RGB, GL_RGBA, GL_LUMINANCE, or GL_LUMINANCE_ALPHA.
     */
    virtual int GetInternalGLFormat() const;

    /**
     * \brief Returns the OpenGL ES type of this Pixmap.
     * \return one of GL_UNSIGNED_BYTE, GL_UNSIGNED_SHORT_5_6_5, GL_UNSIGNED_SHORT_4_4_4_4
     */
    virtual int GetGLType() const;

    /**
     * \brief Returns the direct ByteBuffer holding the pixel data. For the format
     * Alpha each value is encoded as a byte.
     * For the format LuminanceAlpha the luminance is the first byte and the alpha
     * is the second byte of the pixel.
     * For the formats RGB888 and RGBA8888 the color components are stored in a
     * single byte each in the order red, green, blue (alpha).
     * For the formats RGB565 and RGBA4444 the pixel colors are stored in shorts in
     * machine dependent order.
     */
    virtual ByteBuffer GetPixels();

    virtual Format GetFormat();

    virtual Gdx2DPixmap* GetGdx2DPixmap() const;

    /**
     * \brief Creates a Pixmap from a part of the current framebuffer.
     * \param x Framebuffer region x
     * \param y Framebuffer region y
     * \param width Framebuffer region width
     * \param height Framebuffer region height
     * \return The new Pixmap.
     */
    Pixmap CreateFromFrameBuffer( int x, int y, int width, int height );

    Format FormatFromString( const char* str );

    bool IsDisposed() const;

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
    int width  = 0;
    int height = 0;

    Gdx2DPixmap* gdx_2d_pixmap = nullptr;
    bool         is_disposed   = false;
};

#endif //PIXMAP_H
