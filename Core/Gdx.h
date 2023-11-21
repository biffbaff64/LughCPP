#ifndef GDX_H
#define GDX_H

#include "IApplication.h"
#include "IAudio.h"
#include "IFile.h"
#include "../Graphics/Igl20.h"
#include "../Graphics/Igl30.h"
#include "BaseGraphics.h"
#include "IInput.h"
#include "INet.h"

// Environment class holding references to the Application,
// Graphics, Audio, Files and Input instances.
class Gdx
{
public:
    Gdx();
    ~Gdx() = default;

    [[nodiscard]] static bool IsDevMode();
    [[nodiscard]] bool        IsGodMode() const;

    void SetDevMode( bool dev_mode_state );
    void SetGodMode( bool god_mode_state );

    IApplication* pApp;
    BaseGraphics* pGraphics;
    IAudio*       pAudio;
    IFile*        pFiles;
    IInput*       pInput;
    INet*         pNet;
    IGL20*        pGL;
    IGL20*        pGL20;
    IGL30*        pGL30;

private:
    bool is_dev_mode = false;
    bool is_god_mode = false;
};

#endif //GDX_H
