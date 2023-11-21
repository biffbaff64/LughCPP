#ifndef GDXVERSION_H
#define GDXVERSION_H

//TODO: A 'proper' library version class is needed.

class GdxVersion
{
#define MAJOR_VERSION       0
#define MINOR_VERSION       0
#define REVISION_VERSION    1

public:
    GdxVersion();
    virtual ~GdxVersion() = default;

    [[nodiscard]] virtual int GetMajorVersion() const;
    [[nodiscard]] virtual int GetMinorVersion() const;
    [[nodiscard]] virtual int GetRevisionVersion() const;

    void SetMajorVersion( int major );
    void SetMinorVersion( int minor );
    void SetRevisionVersion( int rev );

    [[nodiscard]] virtual bool IsHigher( int major, int minor, int revision ) const;
    [[nodiscard]] virtual bool IsHigherEqual( int major, int minor, int revision ) const;
    [[nodiscard]] virtual bool IsLower( int major, int minor, int revision ) const;
    [[nodiscard]] virtual bool IsLowerEqual( int major, int minor, int revision ) const;

protected:
    int major_version    = MAJOR_VERSION;
    int minor_version    = MINOR_VERSION;
    int revision_version = REVISION_VERSION;
};

#endif //GDXVERSION_H
