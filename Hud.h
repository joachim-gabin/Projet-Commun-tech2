#pragma once
#include "General.h"
#include "inventaire.h"

class hud
{
public:
	hud();
	~hud();

	void affichage(sf::RenderWindow* window, inventaire inv);
	void currentItem(inventaire inv);
	sf::Sprite creatSprite();

	int x;
	int y;
	int nbrLife;

private:
	sf::Sprite heart1;
	sf::Sprite heart2;
	sf::Sprite heart3;
	sf::Sprite item;
	sf::Texture texture;
	sf::Texture itemText;
};