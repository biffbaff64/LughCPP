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

    T Get< T >( char* name );
    T Get< T >( char* name, T type );
    T Get< T >( AssetDescriptor< T > assetDescriptor );
    std::vector< T > GetAll< T >( Type type, std::vector< T > outArray );
    bool Contains( char* fileName );
    bool Contains( char* fileName, Type type );
    void Unload( char* fileName );
    bool ContainsAsset< T >( T asset );
    char* GetAssetFileName< T >( T asset );
    bool IsLoaded( char* fileName );
    bool IsLoaded( char* fileName, Type type );
    AssetLoader GetLoader( Type type, char* fileName = null );
    void Load( char* fileName, Type type, AssetLoaderParameters< T > parameter );
    void Load( AssetDescriptor< T > desc );
    bool Update();
    bool Update( int millis );
    bool IsFinished();
    void FinishLoading();
    T FinishLoadingAsset< T >( AssetDescriptor< T > assetDesc );
    T FinishLoadingAsset< T >( char* fileName );
    void InjectDependencies( char* parentAssetFilename, std::vector< AssetDescriptor< T > > dependendAssetDescs );
    void InjectDependency( char* parentAssetFilename, AssetDescriptor< T > dependendAssetDesc );
    void NextTask();
    void AddTask( AssetDescriptor< T > assetDesc );
    void AddAsset< T >( char* fileName, Type type, T asset );
    bool UpdateTask();
    void TaskFailed( AssetDescriptor< T > assetDesc, std::exception ex );
    void IncrementRefCountedDependencies( char* parent );
    void HandleTaskError( std::exception t );
    void SetLoader( Type type, AssetLoader loader );
    void SetLoader( Type type, char* suffix, AssetLoader loader );
    int GetQueuedAssets();
    float GetProgress();
    void SetErrorListener( IAssetErrorListener< T > listener );
    void Dispose();
    void Clear();
    int GetReferenceCount( char* fileName );
    void SetReferenceCount( char* fileName, int refCount );
    char* GetDiagnostics();
    std::vector< char * > GetAssetNames();
    std::vector< char * > GetDependencies( char* name );
    Type GetAssetType( char* name );

private:
    std::unordered_map< T, std::unordered_map< char *, IRefCountedContainer > > assets;
    std::unordered_map< T, std::unordered_map< char *, AssetLoader > >          loaders;
    std::unordered_map< char *, T >                                             asset_types;
    std::unordered_map< char *, std::vector< char * > >                         asset_dependencies;
    std::vector< char * >                                                       injected;
    std::vector< AssetDescriptor< T > >                                         load_queue;
    std::vector< AssetLoadingTask< T > >                                        tasks;

    AsyncExecutor*            executor = nullptr;
    IAssetErrorListener< T >* listener = nullptr;

    int loaded     = 0;
    int to_load    = 0;
    int peak_tasks = 0;

    IFileHandleResolver file_handle_resolver;
};

#endif //ASSETMANAGER_H
