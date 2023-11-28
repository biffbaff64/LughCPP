#ifndef ITEXTUREARRAYDATA_H
#define ITEXTUREARRAYDATA_H

#include "Pixmap.h"

/**
 * \brief Used by a TextureArray to load the pixel data. The TextureArray will
 * request the TextureArrayData to prepare itself through Prepare() and upload
 * its data using ConsumeTextureArrayData(). These are the first methods to be
 * called by TextureArray. After that the TextureArray will invoke the other
 * methods to find out about the size of the image data, the format, whether
 * the TextureArrayData is able to manage the pixel data if the OpenGL ES context
 * is lost. Before a call to either ConsumeTextureArrayData(), TextureArray will
 * bind the OpenGL ES texture.
 */
class ITextureArrayData
{
public:
    /**
     * \brief  whether the TextureArrayData is prepared or not.
     */
    virtual bool IsPrepared();

    /**
     * \brief Prepares the TextureArrayData for a call to ConsumeTextureArrayData().
     * This method can be called from a non OpenGL thread and should thus not interact
     * with OpenGL.
     */
    virtual void Prepare();

    /**
     * \brief Uploads the pixel data of the TextureArray layers of the TextureArray
     * to the OpenGL ES texture. The caller must bind an OpenGL ES texture. A call
     * to Prepare() must preceed a call to this method.
     * Any internal data structures created in Prepare() should be disposed of here.
     */
    virtual void ConsumeTextureArrayData();

    /**
     * \brief  the width of this TextureArray
     */
    virtual int GetWidth();

    /**
     * \brief  the height of this TextureArray
     */
    virtual int GetHeight();

    /**
     * \brief  the layer count of this TextureArray
     */
    virtual int GetDepth();

    /**
     * \brief  whether this implementation can cope with a EGL context loss.
     */
    virtual bool IsManaged();

    /**
     * \brief  the internal format of this TextureArray
     */
    virtual int GetInternalFormat();

    /**
     * \brief  the GL type of this TextureArray 
     */
    virtual int GetGLType();

private:
    ITextureArrayData()          = default;
    virtual ~ITextureArrayData() = default;
};

/**
 * \brief Provides static method to instantiate the right implementation.
 */
class TextureArrayDataFactory
{
public:
    TextureArrayDataFactory()          = default;
    virtual ~TextureArrayDataFactory() = default;

    ITextureArrayData LoadFromFiles( Pixmap::Format format, bool useMipMaps, ... );
};

#endif //ITEXTUREARRAYDATA_H
