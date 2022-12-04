#pragma once
#include "General.h"

class inventaire
{
public:
	inventaire();
	~inventaire();

	void ajout();
	void selection();
	sf::Sprite affichage();

	int inv[9];
	int statut = 0;

private:

	sf::Sprite sprite;
	sf::Texture texture;

	int x;
	int y;
};