#ifndef IDISPOSABLE_H
#define IDISPOSABLE_H

class IDisposable
{
public:
    virtual void Dispose() = 0;
    virtual void Dispose( bool disposing ) = 0;

private:
    IDisposable() = default;
    virtual ~IDisposable() = default;
};

#endif //IDISPOSABLE_H
