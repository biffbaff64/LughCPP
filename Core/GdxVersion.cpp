#include <exception>

#include "GdxVersion.h"
#include "../Utils/StringUtils.h"

GdxVersion::GdxVersion()
{
}

int GdxVersion::GetMajorVersion() const
{
    return this->major_version;
}

int GdxVersion::GetMinorVersion() const
{
    return this->minor_version;
}

int GdxVersion::GetRevisionVersion() const
{
    return this->revision_version;
}

void GdxVersion::SetMajorVersion( const int major )
{
    this->major_version = major;
}

void GdxVersion::SetMinorVersion( const int minor )
{
    this->minor_version = minor;
}

void GdxVersion::SetRevisionVersion( const int rev )
{
    this->revision_version = rev;
}

bool GdxVersion::IsHigher( const int major, const int minor, const int revision ) const
{
    return IsHigherEqual(major, minor, revision + 1);
}

bool GdxVersion::IsHigherEqual( const int major, const int minor, const int revision ) const
{
    if (major_version != major)
    {
        return major_version > major;
    }

    if (minor_version != minor)
    {
        return minor_version > minor;
    }

    return revision_version >= revision;
}

bool GdxVersion::IsLower( const int major, const int minor, const int revision ) const
{
    return IsLowerEqual(major, minor, revision - 1);
}

bool GdxVersion::IsLowerEqual( const int major, const int minor, const int revision ) const
{
    if (major_version != major)
    {
        return major_version < major;
    }

    if (minor_version != minor)
    {
        return minor_version < minor;
    }

    return revision_version <= revision;
}
