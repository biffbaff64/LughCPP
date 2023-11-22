#ifndef IGRAPHICS_H
#define IGRAPHICS_H

#include "../Graphics/ICursor.h"
#include "../Graphics/IGL20.h"
#include "../Graphics/IGL30.h"
#include "../Graphics/GLUtils/GlVersion.h"
#include "../Graphics/GraphicsStructs.h"
#include "../Graphics/Pixmap.h"

class BaseGraphics
{
public:
    BaseGraphics();
    virtual ~BaseGraphics() = default;

    // Returns whether OpenGL ES 3.0 is available. If it is you can get an
    // instance of GL30 via GetGL30() to access OpenGL ES 3.0 functionality.
    // Note that this functionality will only be available if you instructed
    // the Application instance to use OpenGL ES 3.0!
    virtual bool IsGL30Available() = 0;

    virtual int GetWidth() = 0;
    virtual int GetHeight() = 0;
    virtual int GetLogicalWidth() = 0;
    virtual int GetLogicalHeight() = 0;
    virtual int GetBackBufferWidth() = 0;
    virtual int GetBackBufferHeight() = 0;

    virtual float  GetBackBufferScale() = 0;
    virtual int    GetSafeInsetLeft() = 0;
    virtual int    GetSafeInsetTop() = 0;
    virtual int    GetSafeInsetBottom() = 0;
    virtual int    GetSafeInsetRight() = 0;
    virtual long   GetFrameId() = 0;
    virtual int    GetFramesPerSecond() = 0;
    virtual GLType GetGraphicsType() = 0;
    virtual float  GetPpiX() = 0;
    virtual float  GetPpiY() = 0;
    virtual float  GetPpcX() = 0;
    virtual float  GetPpcY() = 0;
    virtual float  GetDeltaTime() = 0;
    virtual float  GetRawDeltaTime() = 0;

    // This is a scaling factor for the Density Independent Pixel unit,
    // following the convention where one DIP is one pixel on an approximately
    // 160 dpi screen. Thus on a 160dpi screen this density value will be 1;
    // on a 120 dpi screen it would be .75; etc.
    virtual float        GetDensity() = 0;
    virtual bool         SupportsDisplayModeChange() = 0;
    virtual Monitor      GetPrimaryMonitor() = 0;
    virtual Monitor      GetMonitor() = 0;
    virtual Monitor*     GetMonitors() = 0;
    virtual DisplayMode* GetDisplayModes() = 0;
    virtual DisplayMode* GetDisplayModes( Monitor monitor ) = 0;
    virtual DisplayMode  GetDisplayMode() = 0;
    virtual DisplayMode  GetDisplayMode( Monitor monitor ) = 0;
    virtual virtual bool SetFullscreenMode( DisplayMode display_mode ) = 0;
    virtual bool         SetWindowedMode( int width, int height ) = 0;
    virtual void         SetTitle( char* title ) = 0;
    virtual void         SetUndecorated( bool undecorated ) = 0;
    virtual void         SetResizable( bool resizable ) = 0;
    virtual void         SetVSync( bool vsync ) = 0;
    virtual void         SetForegroundFps( int fps ) = 0;
    virtual BufferFormat GetBufferFormat() = 0;
    virtual bool         SupportsExtension( char* extension ) = 0;
    virtual void         SetContinuousRendering( bool is_continuous ) = 0;
    virtual bool         IsContinuousRendering() = 0;
    virtual void         RequestRendering() = 0;
    virtual bool         IsFullscreen() = 0;
    virtual ICursor      NewCursor( Pixmap pixmap, int x_hotspot, int y_hotspot ) = 0;

    // Only viable on the lwjgl-backend and on the gwt-backend. Browsers that
    // support cursor:url() and support the png format (the pixmap is converted to a
    // data-url of type image/png) should also support custom cursors. Will set the
    // mouse cursor image to the image represented by the Cursor. It is recommended
    // to call this function in the main render thread, and maximum one time per frame.
    virtual void SetCursor( ICursor cursor ) = 0;
    virtual void SetSystemCursor( ICursor::SystemCursor system_cursor ) = 0;

protected:
    IGL20*     m_gl20;
    IGL30*     m_gl30;
    GLVersion* m_gl_version;

    BufferFormat m_buffer_format;

    float m_deltatime;

    int m_width;
    int m_height;
    int m_back_buffer_width;
    int m_back_buffer_height;
    int m_logical_width;
    int m_logical_height;
};

#endif //IGRAPHICS_H
