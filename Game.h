#pragma once
#include "General.h"

class Game
{
public:
	Game();
	~Game();

    void initVariables();
    void gameInit();
    void gameLoop();

private:

    bool end = false;
    sf::RenderWindow* window;
    sf::Event event;
};