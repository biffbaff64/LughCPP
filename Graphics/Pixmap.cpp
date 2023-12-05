#include "Pixmap.h"

#include <locale>

#include "PixmapFormat.h"
#include "../Core/Gdx.h"
#include "../Graphics/Igl20.h"

Pixmap::Pixmap( const int width, const int height, const Format format )
{
    this->gdx_2d_pixmap = new Gdx2DPixmap(width,
                                          height,
                                          PixmapFormat::ToGdx2DPixmapFormat(format));

    // Qualification added for virtual functions.
    Pixmap::SetColor(0, 0, 0, 0);
    Pixmap::FillWithCurrentColor();
}

Pixmap::Pixmap( int encoded_data[ ], int offset, int len )
{
}

Pixmap::Pixmap( FILE* file )
{
}

Pixmap::Pixmap( Gdx2DPixmap &pixmap )
{
}

void Pixmap::DownloadFromUrl( char* url, IDownloadPixmapResponseListener &responseListener )
{
}

void Pixmap::SetColor( int color )
{
}

void Pixmap::SetColor( float r, float g, float b, float a )
{
}

void Pixmap::SetColor( Color* color )
{
}

void Pixmap::FillWithCurrentColor()
{
}

void Pixmap::DrawLine( int x, int y, int x2, int y2 )
{
}

void Pixmap::DrawRectangle( int x, int y, int width, int height )
{
}

void Pixmap::DrawPixmap( Pixmap* pixmap, int x, int y )
{
}

void Pixmap::DrawPixmap( Pixmap* pixmap, int x, int y, int srcx, int srcy, int srcWidth, int srcHeight )
{
}

void Pixmap::DrawPixmap( Pixmap* pixmap, int   srcx, int srcy, int srcWidth, int srcHeight, int dstx, int dsty,
                         int     dstWidth, int dstHeight )
{
}

void Pixmap::FillRectangle( int x, int y, int width, int height )
{
}

void Pixmap::DrawCircle( int x, int y, int radius )
{
}

void Pixmap::FillCircle( int x, int y, int radius )
{
}

void Pixmap::FillTriangle( int x1, int y1, int x2, int y2, int x3, int y3 )
{
}

int Pixmap::GetPixel( int x, int y )
{
}

void Pixmap::DrawPixel( int x, int y )
{
}

void Pixmap::DrawPixel( int x, int y, int color )
{
}

int Pixmap::GetWidth() const
{
}

int Pixmap::GetHeight() const
{
}

Pixmap::BlendTypes Pixmap::GetBlending()
{
}

Pixmap::Filter Pixmap::GetFilter()
{
}

void Pixmap::SetBlending( BlendTypes blend )
{
}

void Pixmap::SetFilter( Filter filter )
{
}

int Pixmap::GetGLFormat() const
{
}

int Pixmap::GetInternalGLFormat() const
{
}

int Pixmap::GetGLType() const
{
}

ByteBuffer Pixmap::GetPixels()
{
}

Pixmap::Format Pixmap::GetFormat()
{
    return PixmapFormat::FromGdx2DPixmapFormat( gdx_2d_pixmap->GetFormat() );
}

Gdx2DPixmap* Pixmap::GetGdx2DPixmap() const
{
    return this->gdx_2d_pixmap;
}

Pixmap Pixmap::CreateFromFrameBuffer( int x, int y, int width, int height )
{
    Gdx::pGL->GLPixelStorei( IGL20::GL_PACK_ALIGNMENT, 1 );

    auto pixmap = Pixmap( width, height, Format::RGBA8888 );
    const auto pixels = pixmap.GetPixels();

    Gdx::pGL->GLReadPixels( x, y, width, height, IGL20::GL_RGBA, IGL20::GL_UNSIGNED_BYTE, pixels );

    return pixmap;
}

Pixmap::Format Pixmap::FormatFromString( const char* str )
{
    int   i = 0;
    char lower[ sizeof( str ) / sizeof( char ) ];

    while (str[ i ])
    {
        lower[ i ] = std::tolower(str[ i ]);
        i++;
    }

    if (strcmp(lower, "alpha"))
        return Format::Alpha;
    if (strcmp(lower, "intensity"))
        return Format::Intensity;
    if (strcmp(lower, "luminancealpha"))
        return Format::LuminanceAlpha;
    if (strcmp(lower, "rgb565"))
        return Format::RGB565;
    if (strcmp(lower, "rgba4444"))
        return Format::RGBA4444;
    if (strcmp(lower, "rgb888"))
        return Format::RGB888;
    if (strcmp(lower, "rgb8888"))
        return Format::RGBA8888;

    throw std::exception( "Unknown Format! " );
}

bool Pixmap::IsDisposed() const
{
    return this->is_disposed;
}

void Pixmap::Dispose( const bool disposing )
{
    if (disposing)
    {
        this->gdx_2d_pixmap->Dispose();
        this->is_disposed = true;
    }
}

void Pixmap::Dispose()
{
    Dispose(!is_disposed);
}
