#include "inventaire.h"

inventaire::inventaire()
{
	this->x = SIZE_TILE * 2;
	this->y = WINDOW_HEIGHT - SIZE_TILE * 4;

	if (!this->texture.loadFromFile("texture/inventaire_hud.png"))
	{
		std::cout << "erreur d'image" << std::endl;
	}
	this->sprite.setPosition(this->x, this->y);
	this->sprite.setTexture(this->texture);
	this->sprite.setScale(0.7f, 0.7f);
}
inventaire::~inventaire()
{

}
void inventaire::ajout()
{

}
void inventaire::selection()
{

}
sf::Sprite inventaire::affichage()
{
	return this->sprite;
}