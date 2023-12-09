#include "src/Game.h"
#include"src/MenuState.h"
#include<SFML/Audio.hpp>

int main()
{
    Game game;

    game.pushState(new menuState(&game));
    game.gameLoop();

    return 0;
}
