#pragma once
#include "General.h"

class item
{
public:
	item(std::string texture, int i, int j);
	~item();

	int interaction(int x, int y);
	sf::Sprite item_sprite();

	int x;
	int y;

private:
	sf::Sprite sprite;
	sf::Texture texture;
};