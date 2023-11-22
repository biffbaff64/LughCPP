#ifndef IAPPLICATIONLISTENER_H
#define IAPPLICATIONLISTENER_H

class IApplicationListener
{
public:
    /**
     * \brief Called when the <see cref="IApplication"/> is first created.
     */
    virtual void Create() = 0;

    /**
     * \brief Called when the <see cref="IApplication"/> is resized. This can
     * happen at any point during a non-paused state but will never happen
     * before a call to <see cref="Create"/>
     * \param width The new width in pixels.
     * \param height The new height in pixels.
     */
    virtual void Resize( int width, int height ) = 0;

    /**
     * \brief Called when the <see cref="IApplication"/> should draw itself.
     */
    virtual void Render() = 0;

    /**
     * \brief Called when the <see cref="IApplication"/> is paused, usually when
     * it's not active or visible on-screen. An Application is also
     * paused before it is destroyed.
     */
    virtual void Pause() = 0;

    /**
     * \brief Called when the <see cref="IApplication"/> is resumed from a paused state,
     * usually when it regains focus.
     */
    virtual void Resume() = 0;

private:
    IApplicationListener()          = default;
    virtual ~IApplicationListener() = default;
};

#endif //IAPPLICATIONLISTENER_H
