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
	void select(sf::Event event);
	void removeItem(int i);
	void addLife(int n);
	void removeLife(int n);
	void currentLife(int life);

	int inv[9] = { 1, 2, 0, 0, 0, 0, 0, 0, 0 };
	int statut = 0;
	int statut_knife = 0;
	int statut_axe = 0;
	int statut_gas = 0;
	int currentChoose;
	int current_item;
	int current_life;


private:

	sf::Sprite hud_sprite;
	sf::Texture hud_texture;

	sf::Sprite obj_sprite;
	sf::Texture obj_texture;


	float x;
	float y;
};