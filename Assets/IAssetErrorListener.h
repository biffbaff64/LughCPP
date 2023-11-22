#ifndef IASSETERRORLISTENER_H
#define IASSETERRORLISTENER_H

#include <exception>

#include "AssetDescriptor.h"

template< typename T >
class IAssetErrorListener
{
public:
    virtual void Error( AssetDescriptor<T> asset, std::exception throwable ) = 0;

private:
    IAssetErrorListener() = default;
    virtual ~IAssetErrorListener() = default;
};

#endif //IASSETERRORLISTENER_H
