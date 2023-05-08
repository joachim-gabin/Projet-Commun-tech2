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

    int map[WINDOW_HEIGHT / 32][WINDOW_WIDTH / 32];
    int items[WINDOW_HEIGHT / 32][WINDOW_WIDTH / 32];
    bool end = false;
    sf::RenderWindow* window;
    sf::Event event;
};