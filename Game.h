#pragma once
#include "General.h"

class Game
{
public:
	Game();
	~Game();

    void initVariables();
    void gameInit();
    void Open();
    void gameLoop();

    bool dead = false;

private:
    int map[WINDOW_HEIGHT / 32][WINDOW_WIDTH / 32];
    int tiles[WINDOW_HEIGHT / 32][WINDOW_WIDTH / 32];
    int items[WINDOW_HEIGHT / 32][WINDOW_WIDTH / 32];
    int actualMapX, actualMapY = 0;
    bool end = false;
    sf::RenderWindow* window;
    sf::Event event;
};