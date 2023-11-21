#include "GlVersion.h"

#include <exception>
#include <ranges>
#include <regex>
#include <string>

#include "../../Core/Gdx.h"
#include "../../Utils/StringUtils.h"

GLVersion::GLVersion( const IApplication::ApplicationType app_type,
                      const char*                         version_string,
                      char*                               vendor_string,
                      char*                               renderer_string )
{
    switch (app_type)
    {
        case IApplication::Android:
            this->gl_type = GLType::GLES;
            break;

        case IApplication::IOS:
            this->gl_type = GLType::Ios_ToDo;
            break;

        case IApplication::WebGL:
            this->gl_type = GLType::WebGL;
            break;

        case IApplication::Desktop:
        case IApplication::Linux:
        case IApplication::None:
        default:
            this->gl_type = GLType::OpenGL;
            break;
    }

    if (this->gl_type == GLType::GLES)
    {
        //OpenGL<space>ES<space><version number><space><vendor-specific information>.
        ExtractVersion(R"(OpenGL ES (\d(\.\d){0,2}))", version_string);
    }
    else if (this->gl_type == GLType::WebGL)
    {
        //WebGL<space><version number><space><vendor-specific information>
        ExtractVersion(R"(WebGL (\d(\.\d){0,2}))", version_string);
    }
    else if (this->gl_type == GLType::OpenGL)
    {
        //<version number><space><vendor-specific information>
        ExtractVersion(R"((\d(\.\d){0,2}))", version_string);
    }
    else
    {
        SetMajorVersion(-1);
        SetMinorVersion(-1);
        SetRevisionVersion(-1);

        vendor_string   = nullptr;
        renderer_string = nullptr;
    }

    this->vendor_string   = vendor_string;
    this->renderer_string = renderer_string;
}

char* GLVersion::GetVendorString() const
{
    return this->vendor_string;
}

GLType GLVersion::GetGLType() const
{
    return gl_type;
}

/**
 * \brief Extracts Version Data from the supplied string.
 * \param pattern_string
 * \param version_string
 */
void GLVersion::ExtractVersion( const char* pattern_string, const char* version_string )
{
    if (const auto rx = std::regex(pattern_string); std::regex_match(version_string, rx))
    {
        const auto resultSplit = StringUtils().Split(version_string, '.');

        major_version    = ParseInt(resultSplit[ 0 ], 2);
        minor_version    = resultSplit.size()< 2 ? 0 : ParseInt(resultSplit[ 1 ], 0);
        revision_version = resultSplit.size()< 3 ? 0 : ParseInt(resultSplit[ 2 ], 0);
    }
    else
    {
        Gdx().pApp->Log(TAG, "Invalid version string: " /*+ version_string*/);

        major_version    = 2;
        minor_version    = 0;
        revision_version = 0;
    }
}

/**
 * \brief Forgiving parsing of gl major, minor and release versions as,
 * apparently, some manufacturers don't adhere to spec
 */
int GLVersion::ParseInt( const std::string &v, const int default_value )
{
    return ParseInt( v.c_str(), default_value );
}

/**
 * \brief Forgiving parsing of gl major, minor and release versions as,
 * apparently, some manufacturers don't adhere to spec
 */
int GLVersion::ParseInt( const char* v, const int default_value )
{
    try
    {
        return std::stoi(v);
    }
    catch (std::exception)
    {
        Gdx().pApp->Error("LibGDXSharp GL", "Error parsing number:, assuming: ");

        return default_value;
    }
}

/**
 * \brief Checks to see if the current GL connection version is higher,
 * or equal to the provided test versions.
 */
bool GLVersion::IsVersionEqualToOrHigher( const int test_major_version, const int test_minor_version ) const
{
    return (this->major_version > test_major_version)
           || ((this->major_version == test_major_version)
               && (this->minor_version >= test_minor_version));
}

/**
 * \brief Returns a string holding GLVersion information.
 */
const char* GLVersion::DebugVersionString()
{
    return "GLVerson Debug String to be finalised";
}
