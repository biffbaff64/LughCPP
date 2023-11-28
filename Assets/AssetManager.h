#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <unordered_map>
#include <vector>

#include "AssetDescriptor.h"
#include "AssetLoadingTask.h"
#include "IAssetErrorListener.h"
#include "RefCountedContainer.h"
#include "../Utils/Async/AsyncExecutor.h"
#include "Loaders/AssetLoader.h"
#include "Loaders/Resolvers/IFileHandleResolver.h"

/// <summary>
/// Loads and stores assets like textures, bitmapfonts, tile maps,
/// sounds, music and so on.
/// </summary>
template< class T >
class AssetManager
{
public:
    AssetManager();
    explicit AssetManager( IFileHandleResolver resolver, bool default_loaders = true );
    ~AssetManager() = default;

    T                Get< T >( const char* name );
    T                Get< T >( const char* name, T type );
    T                Get< T >( AssetDescriptor< T > assetDescriptor );
    std::vector< T > GetAll< T >( T type, std::vector< T > outArray );

    bool Contains( const char* file_name );
    bool Contains( const char* file_name, T type );
    bool ContainsAsset< T >( T asset );

    bool Update();
    bool Update( int millis );

    char*       GetAssetFileName< T >( T asset );
    AssetLoader GetLoader( T type, const char* file_name = nullptr );
    void        Load( const char* file_name, T type, AssetLoaderParameters< T > parameter );
    void        Load( AssetDescriptor< T > desc );
    T           FinishLoadingAsset< T >( AssetDescriptor< T > assetDesc );
    T           FinishLoadingAsset< T >( char* file_name );
    bool        IsLoaded( const char* file_name );
    bool        IsLoaded( const char* file_name, T type );
    bool        IsFinished();
    void        FinishLoading();
    void        Unload( const char* file_name );

    void InjectDependencies( const char* parentAssetFilename, std::vector< AssetDescriptor< T > > dependendAssetDescs );
    void InjectDependency( const char* parentAssetFilename, AssetDescriptor< T > dependendAssetDesc );

    void  AddTask( AssetDescriptor< T > assetDesc );
    void  AddAsset< T >( const char* fileName, T type, T asset );
    void  NextTask();
    bool  UpdateTask();
    void  TaskFailed( AssetDescriptor< T > assetDesc, std::exception ex );
    void  IncrementRefCountedDependencies( const char* parent );
    void  HandleTaskError( std::exception t );
    float GetProgress();

    void SetLoader( T type, AssetLoader loader );
    void SetLoader( T type, const char* suffix, AssetLoader loader );

    int                   GetQueuedAssets();
    void                  SetErrorListener( IAssetErrorListener< T > listener );
    int                   GetReferenceCount( const char* file_name );
    void                  SetReferenceCount( const char* file_name, int refCount );
    char*                 GetDiagnostics();
    std::vector< char * > GetAssetNames();
    std::vector< char * > GetDependencies( const char* name );
    T                     GetAssetType( const char* name );

    void Clear();
    void Dispose();

private:
    std::unordered_map< T, std::unordered_map< char *, RefCountedContainer > > assets;
    std::unordered_map< T, std::unordered_map< char *, AssetLoader > >         loaders;

    std::unordered_map< char *, T >                     asset_types;
    std::unordered_map< char *, std::vector< char * > > asset_dependencies;
    std::vector< char * >                               injected;
    std::vector< AssetDescriptor< T > >                 load_queue;
    std::vector< AssetLoadingTask< T > >                tasks;

    AsyncExecutor*            executor = nullptr;
    IAssetErrorListener< T >* listener = nullptr;

    int loaded     = 0;
    int to_load    = 0;
    int peak_tasks = 0;

    IFileHandleResolver file_handle_resolver;
};

#endif //ASSETMANAGER_H
