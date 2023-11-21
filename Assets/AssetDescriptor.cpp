#include "AssetDescriptor.h"

/**
 * \brief Default constructor.
 *        Sets members to nullptr.
 */
template< typename  T >
AssetDescriptor< T >::AssetDescriptor()
{
    this.type       = nullptr;
    this.file_name  = nullptr;
    this.parameters = nullptr;
}

/**
 * \brief Creates a new AssetDescriptor from the supplied data.
 * \param filepath - Filepath of the asset.
 * \param asset_type - The type of the asset.
 * \param parameters - loader parameter info.
 */
template< typename T >
AssetDescriptor< T >::AssetDescriptor( const char* filepath, T asset_type, AssetLoaderParameters< T >* parameters )
{
    this.type       = asset_type;
    this.file_name  = filepath;
    this.parameters = parameters;
}

template< typename T >
const char* AssetDescriptor< T >::to_string()
{
    return nullptr;
}
