#pragma once
#include "General.h"

class Playground
{
private:

	sf::Texture texture;
	sf::Sprite sprite;

public:

	Playground();
	~Playground();
	int load();
	sf::Sprite GetSprite();

};