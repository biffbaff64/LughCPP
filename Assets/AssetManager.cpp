#include "AssetManager.h"
#include "Loaders/Resolvers/AbsoluteFileHandleResolver.h"

#include <vector>

/**
 * \brief Default constructor.
 */
template< class T >
AssetManager< T >::AssetManager()
{
    this(new AbsoluteFileHandleResolver());
}

/**
 * \brief
 * \param resolver
 * \param default_loaders defaults to true
 */
template< class T >
AssetManager< T >::AssetManager( IFileHandleResolver resolver, const bool default_loaders )
{
    if (default_loaders)
    {
    }

    this->file_handle_resolver = resolver;
}

template< class T >
T AssetManager< T >::Get< T >( const char* name )
{
    return nullptr;
}

template< class T >
T AssetManager< T >::Get( const char* name, T type )
{
    return nullptr;
}

template< class T >
T AssetManager< T >::Get( AssetDescriptor< T > asset_descriptor )
{
    return nullptr;
}

template< class T >
std::vector< T > AssetManager< T >::GetAll( T type, std::vector< T > out_array )
{
    return nullptr;
}

template< class T >
bool AssetManager< T >::Contains( const char* file_name )
{
    return false;
}

template< class T >
bool AssetManager< T >::Contains( const char* file_name, T type )
{
    return false;
}

template< class T >
bool AssetManager< T >::ContainsAsset( T asset )
{
    return false;
}

template< class T >
bool AssetManager< T >::Update()
{
    return false;
}

template< class T >
bool AssetManager< T >::Update( int millis )
{
    return false;
}

template< class T >
char* AssetManager< T >::GetAssetFileName( T asset )
{
    return nullptr;
}

template< class T >
AssetLoader AssetManager< T >::GetLoader( T type, const char* fileName )
{
}

template< class T >
void AssetManager< T >::Load( const char* fileName, T type, AssetLoaderParameters< T > parameter )
{
}

template< class T >
void AssetManager< T >::Load( AssetDescriptor< T > desc )
{
}

template< class T >
T AssetManager< T >::FinishLoadingAsset( AssetDescriptor< T > assetDesc )
{
}

template< class T >
T AssetManager< T >::FinishLoadingAsset( char* fileName )
{
}

template< class T >
bool AssetManager< T >::IsLoaded( const char* fileName )
{
}

template< class T >
bool AssetManager< T >::IsLoaded( const char* fileName, T type )
{
}

template< class T >
bool AssetManager< T >::IsFinished()
{
}

template< class T >
void AssetManager< T >::FinishLoading()
{
}

template< class T >
void AssetManager< T >::Unload( const char* file_name )
{
}

template< class T >
void AssetManager< T >::InjectDependencies( const char*                         parentAssetFilename,
                                            std::vector< AssetDescriptor< T > > dependendAssetDescs )
{
}

template< class T >
void AssetManager< T >::InjectDependency( const char* parentAssetFilename, AssetDescriptor< T > dependendAssetDesc )
{
}

template< class T >
void AssetManager< T >::AddTask( AssetDescriptor< T > assetDesc )
{
}

template< class T >
void AssetManager< T >::AddAsset( const char* fileName, T type, T asset )
{
}

template< class T >
void AssetManager< T >::NextTask()
{
}

template< class T >
bool AssetManager< T >::UpdateTask()
{
}

template< class T >
void AssetManager< T >::TaskFailed( AssetDescriptor< T > assetDesc, std::exception ex )
{
}

template< class T >
void AssetManager< T >::IncrementRefCountedDependencies( const char* parent )
{
}

template< class T >
void AssetManager< T >::HandleTaskError( std::exception t )
{
}

template< class T >
float AssetManager< T >::GetProgress()
{
}

template< class T >
void AssetManager< T >::SetLoader( T type, AssetLoader loader )
{
}

template< class T >
void AssetManager< T >::SetLoader( T type, const char* suffix, AssetLoader loader )
{
}

template< class T >
int AssetManager< T >::GetQueuedAssets()
{
}

template< class T >
void AssetManager< T >::SetErrorListener( IAssetErrorListener< T > listener )
{
}

template< class T >
int AssetManager< T >::GetReferenceCount( const char* file_name )
{
}

template< class T >
void AssetManager< T >::SetReferenceCount( const char* file_name, int refCount )
{
}

template< class T >
char* AssetManager< T >::GetDiagnostics()
{
}

template< class T >
std::vector< char * > AssetManager< T >::GetAssetNames()
{
}

template< class T >
std::vector< char * > AssetManager< T >::GetDependencies( const char* name )
{
}

template< class T >
T AssetManager< T >::GetAssetType( const char* name )
{
}

/**
 * \brief Clears and disposes all assets and the preloading queue.
 */
template< class T >
void AssetManager< T >::Clear()
{
    load_queue.Clear();

    while (!Update())
    {
    }

    const auto dependency_count = new std::unordered_map< char *, int >();

    while (asset_types.size() > 0)
    {
        // for each asset, figure out how often it was referenced
        dependency_count->clear();

        std::vector< char * > asset_keys;
        asset_keys.reserve(asset_types.size());

        for (auto &kv: asset_types)
        {
            asset_keys.push_back(kv.first);
        }

        for (auto &asset: asset_keys)
        {
            dependency_count(asset) = 0;

            std::vector< char * > dependencies = asset_dependencies ? [ asset ];

            if (dependencies != nullptr)
            {
                foreach(var dependency in dependencies)
                {
                    var count = 0;

                    if (dependencyCount.TryGetValue(dependency, out var value))
                    {
                        count = value == default(int) ? 0 : value;
                    }

                    count++;
                    dependencyCount[ dependency ] = count;
                }
            }
        }

        // only dispose of assets that are root assets (not referenced)
        foreach(var asset in assets)
        {
            if (dependencyCount.TryGetValue(asset, out _) == default(bool))
            {
                Unload(asset);
            }
        }
    }

    this._assets.Clear();
    this._assetTypes.Clear();
    this._assetDependencies ? Clear();

    this._loaded    = 0;
    this._toLoad    = 0;
    this._peakTasks = 0;
    this._loadQueue.Clear();
    this._tasks.Clear();
}

/**
 * \brief Disposes all assets in the manager and stops all asynchronous loading.
 */
template< class T >
void AssetManager< T >::Dispose()
{
    Clear();

    executor->Dispose();
}
