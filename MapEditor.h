#pragma once

#include "General.h"

class MapEditor
{
public:
	MapEditor();
	~MapEditor();
	void Init();
	void Loop();
	void Save();


private:
	sf::RenderWindow* window;
	sf::Event event;

	int map[WINDOW_HEIGHT / 32][WINDOW_WIDTH / 32];
	int actualTexture = 1;
};

