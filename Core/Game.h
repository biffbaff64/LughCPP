#ifndef GAME_H
#define GAME_H

class Game : IApplicationListener
{
public:
    IScreen* Screen;

private:
    IScreen* screen;
};

#endif //GAME_H
