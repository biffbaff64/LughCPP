#include "AssetLoadingTask.h"

template< typename T >
AssetLoadingTask< T >::AssetLoadingTask( AssetManager         manager,
                                         AssetDescriptor< T > asset_desc,
                                         AssetLoader          loader,
                                         AsyncExecutor        thread_pool )
{
    this->manager    = manager;
    this->asset_desc = asset_desc;
    this->loader     = loader;
    this->executor   = thread_pool;
    this->start_time = manager.Log.Level == Logger.LOG_DEBUG
                           ? TimeUtils.NanoTime()
                           : 0;
}

template< typename T >
void AssetLoadingTask< T >::Call()
{
}

template< typename T >
void AssetLoadingTask< T >::Update()
{
}

template< typename T >
void AssetLoadingTask< T >::Unload()
{
}

template< typename T >
FILE AssetLoadingTask< T >::Resolve( AssetLoader loader, AssetDescriptor< T > assetDesc )
{
}

template< typename T >
void AssetLoadingTask< T >::RemoveDuplicates( __resharper_unknown_type array )
{
}

template< typename T >
void AssetLoadingTask< T >::HandleSyncLoader()
{
}

template< typename T >
void AssetLoadingTask< T >::HandleAsyncLoader()
{
}
