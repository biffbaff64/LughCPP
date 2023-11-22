#include "AssetManager.h"
#include "Loaders/Resolvers/AbsoluteFileHandleResolver.h"

#include <vector>

/**
 * \brief Default constructor.
 */
template < class T >
AssetManager< T >::AssetManager()
{
    this( new AbsoluteFileHandleResolver() );
}

/**
 * \brief
 * \param resolver
 * \param default_loaders defaults to true
 */
template < class T >
AssetManager< T >::AssetManager( IFileHandleResolver resolver, bool default_loaders )
{
    if ( default_loaders )
    {
    }

    this->file_handle_resolver = resolver;
}

template < class T >
bool AssetManager< T >::Contains( char* file_name )
{
    return false;
}

template < class T >
T AssetManager< T >::Get( char* name )
{
    return nullptr;
}

template < class T >
T AssetManager< T >::Get( char* name, T type )
{
    return nullptr;
}

template < class T >
T AssetManager< T >::Get( AssetDescriptor< T > asset_descriptor )
{
    return nullptr;
}

template < class T >
std::vector< T > AssetManager< T >::GetAll( T type, std::vector< T > out_array )
{
    return nullptr;
}
