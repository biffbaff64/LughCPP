#ifndef GLVERSION_H
#define GLVERSION_H

#include <xstring>

#include "../../Core/GdxVersion.h"
#include "../../Core/IApplication.h"

enum class GLType
{
    None,
    OpenGL,
    GLES,
    WebGL,
    Ios_ToDo,

    // --------------------------------------
    // Sub-Categories for OpenGL
    GL10,
    GL20,
    GL30,
    GL40,
};

class GLVersion : public GdxVersion
{
public:
    GLVersion( IApplication::ApplicationType app_type,
               const char*                   version_string,
               char*                         vendor_string,
               char*                         renderer_string );

    virtual char*  GetVendorString() const;
    virtual GLType GetGLType() const;

private:
    void               ExtractVersion( const char* pattern_string, const char* version_string );
    static int         ParseInt( const std::string &v, int default_value );
    static int         ParseInt( const char* v, int default_value );
    bool               IsVersionEqualToOrHigher( int test_major_version, int test_minor_version ) const;
    static const char* DebugVersionString();

    const char* TAG = "GLVersion";

    char* vendor_string;
    char* renderer_string;

    GLType gl_type;
};

#endif //GLVERSION_H
