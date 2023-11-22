#ifndef ASSETLOADINGTASK_H
#define ASSETLOADINGTASK_H

#include <cstdio>

#include "AssetDescriptor.h"
#include "Loaders/AssetLoader.h"
#include "../Utils/Async/AsyncExecutor.h"
#include "../Utils/Async/AsyncResult.h"
#include "../Utils/Collections/Array.h"

template< typename T >
class AssetLoadingTask
{
public:
    AssetLoadingTask() = default;
    AssetLoadingTask( AssetManager         manager,
                      AssetDescriptor< T > asset_desc,
                      AssetLoader          loader,
                      AsyncExecutor        thread_pool );
    virtual ~AssetLoadingTask() = default;

    void Call();
    void Update();
    void Unload();

private:
    FILE Resolve( AssetLoader loader, AssetDescriptor< T > assetDesc );
    void HandleSyncLoader();
    void HandleAsyncLoader();
    void RemoveDuplicates( Array< AssetDescriptor< T > > array );

    AssetDescriptor< T >          asset_desc;
    Array< AssetDescriptor< T > > dependencies;

    bool          dependencies_loaded;
    bool          cancel;
    void*         asset;
    AssetManager  manager;
    AssetLoader   loader;
    bool          async_done;
    AsyncResult   deps_future;
    AsyncResult   load_future;
    AsyncExecutor executor;
    long          start_time;
};

#endif //ASSETLOADINGTASK_H
