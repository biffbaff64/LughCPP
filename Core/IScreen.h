#ifndef ISCREEN_H
#define ISCREEN_H

/**
 * \brief Represents one of many application screens, such as a main menu,
 * a settings menu, the game screen and so on.
 * Note that Dispose() is not called automatically.
 */
class IScreen
{
public:
    /**
     * \brief Called when this screen becomes the current screen for a Game.
     */
    void Show();

    /**
     * \brief Called when the screen should render itself.
     * \param delta The time in seconds since the last render.
     */
    void Render( float delta );

    /**
     * \brief
     */
    void Resize( int width, int height );

    /**
     * \brief
     */
    void Pause();

    /**
     * \brief
     */
    void Resume();

    /**
     * \brief Called when this screen is no longer the current screen for a Game.
     */
    void Hide();

    /**
     * \brief Called when this screen should release all resources.
     */
    void Dispose();
};

#endif //ISCREEN_H
