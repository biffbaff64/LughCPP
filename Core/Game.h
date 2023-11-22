#ifndef GAME_H
#define GAME_H

#include "IApplicationListener.h"
#include "IDisposable.h"
#include "IScreen.h"

class Game : public IApplicationListener, public IDisposable
{
public:
    Game()          = default;
    virtual ~Game() = default;

    IScreen* GetScreen() const;
    void     SetScreen( IScreen &screen );

    virtual void Create() override;
    virtual void Render() override;
    virtual void Resize( int width, int height ) override;
    virtual void Pause() override;
    virtual void Resume() override;
    virtual void Dispose() override;

private:
    IScreen* screen;
};

#endif //GAME_H
