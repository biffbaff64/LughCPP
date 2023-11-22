#ifndef REFCOUNTEDCONTAINER_H
#define REFCOUNTEDCONTAINER_H

class RefCountedContainer
{
public:
    RefCountedContainer() = default;
    explicit RefCountedContainer( void* obj );

    virtual ~RefCountedContainer() = default;

private:
    int   ref_count = 0;
    void* asset     = nullptr;
};

#endif //REFCOUNTEDCONTAINER_H
