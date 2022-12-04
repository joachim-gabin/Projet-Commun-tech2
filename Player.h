#pragma once
#include "General.h"

class player
{
public:
	player(std::string nom_texture, int x, int y);
	~player();

	void move();
	sf::Sprite sprite_player();

	int x;
	int y;


private:

	sf::Sprite sprite;
	sf::Texture texture;
};