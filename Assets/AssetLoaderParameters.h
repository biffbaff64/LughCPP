#ifndef ASSETLOADERPARAMETERS_H
#define ASSETLOADERPARAMETERS_H

#include "AssetManager.h"

template < typename T >
class AssetLoaderParameters
{
public:
    AssetLoaderParameters() = default;
    ~AssetLoaderParameters() = default;

    void ( *loadedCallBack )( AssetManager<T> manager, char* file_name, void* type );
};

#endif //ASSETLOADERPARAMETERS_H
