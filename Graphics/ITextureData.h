#ifndef ITEXTUREDATA_H
#define ITEXTUREDATA_H

#include <cstdio>

#include "Pixmap.h"

/**
 * \brief Used by a Texture to load the pixel data. A TextureData can either return a Pixmap or
 * upload the pixel data itself. It signals it's type via getType() to the Texture that's
 * using it. The Texture will then either invoke consumePixmap() or consumeCustomData(int).
 * These are the first methods to be called by Texture. After that the Texture will invoke
 * the other methods to find out about the size of the image data, the format, whether
 * mipmaps should be generated and whether the TextureData is able to manage the pixel data
 * if the OpenGL ES context is lost. In case the TextureData implementation has the type
 * TextureData.TextureDataType.Custom, the implementation has to generate the mipmaps itself
 * if necessary. See MipMapGenerator. Before a call to either consumePixmap() or
 * consumeCustomData(int), Texture will bind the OpenGL ES texture.
 * Look at FileTextureData and ETC1TextureData for example implementations of this interface.
 */
class ITextureData
{
public:
    enum TextureType
    {
        Pixelmap,
        Custom
    };

    /**
     * \brief the TextureDataType
     */
    virtual TextureType GetTextureDataType();

    /**
     * \brief whether the TextureData is prepared or not.
     */
    virtual bool IsPrepared() const;

    /**
     * \brief whether to generate mipmaps or not.
     */
    virtual bool UseMipMaps();

    /**
     * \brief Prepares the TextureData for a call to ConsumePixmap() or
     * ConsumeCustomData(int). This method can be called from a non
     * OpenGL thread and should thus not interact with OpenGL.
     */
    virtual void Prepare();

    /**
     * \brief Returns the Pixmap for upload by Texture.
     * A call to Prepare() must precede a call to this method. Any
     * internal data structures created in Prepare() should be
     * disposed of here.
     */
    virtual Pixmap ConsumePixmap();

    /**
     * \brief whether the caller of ConsumePixmap() should dispose the
     * Pixmap returned by ConsumePixmap()
     */
    virtual bool DisposePixmap();

    /**
     * \brief Uploads the pixel data to the OpenGL ES texture. The caller must bind an
     * OpenGL ES texture. A call to Prepare() must preceed a call
     * to this method.
     * Any internal data structures created in Prepare() should be
     * disposed of here.
     */
    virtual void ConsumeCustomData( int target );

    /**
     * \brief the width of the pixel data
     */
    virtual int GetWidth() const;

    /**
     * the height of the pixel data
     */
    virtual int GetHeight() const;

    /**
     * \brief the Pixmap.Format of the pixel data
     */
    virtual Pixmap::Format GetFormat() const;

    /**
     * \brief whether this implementation can cope with a EGL context loss.
     */
    virtual bool IsManaged() const;

    /**
     * Provides static methods to instantiate the right implementation (Pixmap, ETC1, KTX).
     */
    class Factory
    {
    public:
        Factory()          = default;
        virtual ~Factory() = default;

        /**
         * \brief
         * <param name="file"></param>
         * <param name="useMipMaps"></param>
         */
        ITextureData LoadFromFile( FILE file, bool useMipMaps );

        /**
         * \brief
         */
        ITextureData LoadFromFile( FILE file, Pixmap::Format format, bool useMipMaps );
    };

private:
    ITextureData()          = default;
    virtual ~ITextureData() = default;
};

#endif //ITEXTUREDATA_H
