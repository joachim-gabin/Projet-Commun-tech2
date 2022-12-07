#pragma once
#include "General.h"

class inventaire
{
public:
	inventaire();
	~inventaire();

	int ajout(int num);
	void selection();
	void affichage(sf::RenderWindow* window);

	int inv[9] = { 2, 0, 0, 0, 0, 0, 0, 0, 0 };
	int statut = 0;

private:

	sf::Sprite hud_sprite;
	sf::Texture hud_texture;

	sf::Sprite obj_sprite;
	sf::Texture obj_texture;

	int x;
	int y;
};