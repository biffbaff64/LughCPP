#ifndef ASSETDESCRIPTOR_H
#define ASSETDESCRIPTOR_H

#include "AssetLoaderParameters.h"

template < typename T >
class AssetDescriptor
{
public:
    AssetDescriptor();
    AssetDescriptor( const char* filepath, T asset_type, AssetLoaderParameters< T >* parameters );
    ~AssetDescriptor() = default;

    static const char* to_string();

private:
    void* type{};
    char* file_name{};

    AssetLoaderParameters< T >* parameters;
};

#endif //ASSETDESCRIPTOR_H
