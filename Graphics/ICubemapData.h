#ifndef ICUBEMAPDATA_H
#define ICUBEMAPDATA_H

/**
 * \brief Used by a Cubemap to load the pixel data. The Cubemap will
 * request the CubemapData to prepare itself through Prepare()
 * and upload its data using ConsumeCubemapData(). These are
 * the first methods to be called by Cubemap.
 * After that the Cubemap will invoke the other methods to find out about the
 * size of the image data, the format, whether the CubemapData is able to
 * manage the pixel data if the OpenGL ES context is lost.
 * Before a call to either ConsumeCubemapData(), Cubemap will
 * bind the OpenGL ES texture.
 */
class ICubemapData
{
private:
    ICubemapData()          = default;
    virtual ~ICubemapData() = default;

public:
    /**
     * \brief whether the TextureData is prepared or not.
     */
    virtual bool IsPrepared() = 0;

    /**
     * \brief Prepares the TextureData for a call to ConsumeCubemapData().
     * This method can be called from a non OpenGL thread and should thus not
     * interact with OpenGL. 
     */
    virtual void Prepare() = 0;

    /**
     * \brief Uploads the pixel data for the 6 faces of the cube to the OpenGL
     * ES texture. The caller must bind an OpenGL ES texture. A call to Prepare()
     * must preceed a call to this method. Any internal data structures created
     * in Prepare() should be disposed of here.
     */
    virtual void ConsumeCubemapData() = 0;

    /**
     * \brief The width of the pixel data.
     */
    virtual int GetWidth() = 0;

    /**
     * \brief The height of the pixel data.
     */
    virtual int GetHeight() = 0;

    /**
     * \brief Returns true if this implementation can cope with a EGL context loss.
     */
    virtual bool IsManaged() = 0;
};

#endif //ICUBEMAPDATA_H
