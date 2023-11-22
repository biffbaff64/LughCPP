#include "Game.h"

#include "Gdx.h"

IScreen* Game::GetScreen() const
{
    return this->screen;
}

void Game::SetScreen( IScreen &screen )
{
    this->screen->Hide();

    this->screen = &screen;

    if ( this->screen != nullptr )
    {
        this->screen->Show();

        this->screen->Resize( Gdx().pGraphics->GetWidth(), Gdx().pGraphics->GetHeight() );
    }
}

void Game::Create()
{
}

void Game::Render()
{
}

void Game::Resize( int width, int height )
{
}

void Game::Pause()
{
}

void Game::Resume()
{
}

void Game::Dispose()
{
}




