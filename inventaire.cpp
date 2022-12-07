#include "inventaire.h"


inventaire::inventaire()
{
	this->x = SIZE_TILE * 2;
	this->y = WINDOW_HEIGHT - SIZE_TILE * 4;

	if (!this->hud_texture.loadFromFile("texture/inventaire_hud.png"))
	{
		std::cout << "erreur d'image" << std::endl;
	}
	this->hud_sprite.setPosition(this->x, this->y);
	this->hud_sprite.setTexture(this->hud_texture);
	this->hud_sprite.setScale(0.7f, 0.7f);
}
inventaire::~inventaire()
{

}
int inventaire::ajout(int num)
{
	for (int l = 0; l <= 8; l++)
	{
		if (this->inv[l] == 0)
		{
			this->inv[l] = num;
			return 1;
		}
	}
	return 0;
}
void inventaire::selection()
{

}
void inventaire::affichage(sf::RenderWindow* window)
{
	window->draw(this->hud_sprite);
	for (int l = 0; l <= 8; l++)
	{
		//std::cout << "rang =" << inv[l] << std::endl;
		switch (this->inv[l])
		{
		case 1:
			if (!this->obj_texture.loadFromFile("texture/axe.png"))
			{
				std::cout << "erreur d'image" << std::endl;
			}
			this->obj_sprite.setPosition(l * 50 + 92, this->y + SIZE_TILE- 8);
			this->obj_sprite.setTexture(this->obj_texture);
			window->draw(this->obj_sprite);

			break;

		case 2:
			if (!this->obj_texture.loadFromFile("texture/conserve.png"))
			{
				std::cout << "erreur d'image" << std::endl;
			}
			this->obj_sprite.setPosition(l * 50 + 92, this->y + SIZE_TILE - 8);
			this->obj_sprite.setTexture(this->obj_texture);
			window->draw(this->obj_sprite);
			break;

		default:
			break;
		}
	}
}