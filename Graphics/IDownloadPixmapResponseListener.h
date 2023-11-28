#ifndef IDOWNLOADPIXMAPRESPONSELISTENER_H
#define IDOWNLOADPIXMAPRESPONSELISTENER_H

#include <exception>

#include "Pixmap.h"

class IDownloadPixmapResponseListener
{
public:
    /**
     * \brief Called on the render thread when image was downloaded successfully.
     */
    virtual void DownloadComplete( Pixmap pixmap );

    /**
     * \brief Called when image download failed. This might get called on a background thread.
     */
    virtual void DownloadFailed( std::exception e );

private:
    IDownloadPixmapResponseListener() = default;
    virtual ~IDownloadPixmapResponseListener() = default;
};

#endif //IDOWNLOADPIXMAPRESPONSELISTENER_H
