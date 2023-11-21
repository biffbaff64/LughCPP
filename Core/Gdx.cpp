#include "Gdx.h"

/**
 * \brief Constructor.
 * The static reference pointers are initialised to nullptr here.
 * Their correct values will be set during the framework initialisation.
 */
Gdx::Gdx()
{
    pApp      = nullptr;
    pAudio    = nullptr;
    pFiles    = nullptr;
    pGraphics = nullptr;
    pInput    = nullptr;
    pNet      = nullptr;
    pGL       = nullptr;
    pGL20     = nullptr;
    pGL30     = nullptr;

    is_dev_mode = false;
    is_god_mode = false;
}

/**
 * \brief Returns TRUE if Developer mode is enabled.
 */
bool Gdx::IsDevMode()
{
#if DEBUG
    return is_dev_mode;
#else
    return false;
#endif
}

/**
 * \brief Returns TRUE if GOD mode is enabled.
 */
bool Gdx::IsGodMode() const
{
    return is_god_mode;
}

/**
 * \brief Sets the state of the 'is_dev_mode' flag.
 * If the build is not a DEBUG build, the flag will be set to FALSE.
 */
void Gdx::SetDevMode( bool dev_mode_state )
{
#if DEBUG
    is_dev_mode = dev_mode_state;
#else
    is_dev_mode = false;
#endif
}

/**
 * \brief Sets the state of the 'is_god_mode' flag.
 */
void Gdx::SetGodMode( bool god_mode_state )
{
    is_god_mode = god_mode_state;
}
