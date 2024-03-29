#pragma once

#include "General.h"

class MapEditor
{
public:
	MapEditor();
	~MapEditor();
	void Init();
	void Open();
	void Loop();
	void Save();


private:
	sf::RenderWindow* window;
	sf::Event event;

	int map[WINDOW_HEIGHT / 32][WINDOW_WIDTH / 32];
	int tiles[WINDOW_HEIGHT / 32][WINDOW_WIDTH / 32];
	int items[WINDOW_HEIGHT / 32][WINDOW_WIDTH / 32];
	int Entities[WINDOW_HEIGHT / 32][WINDOW_WIDTH / 32];
	int actualMapX, actualMapY = 0;
	int actualTexture = 1;
	int typeOfSprite = 0;
	int inMenu = 0;
};

