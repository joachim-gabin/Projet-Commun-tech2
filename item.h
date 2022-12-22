#pragma once
#include "General.h"

class item
{
public:
	item(std::string texture, int i, int j, int num_obj);
	~item();

	int interaction(sf::RenderWindow* window, int x, int y);
	sf::Sprite item_sprite();

	int x;
	int y;
	int num_obj;

private:
	sf::Sprite sprite;
	sf::Texture texture;
};