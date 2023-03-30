#include "Hud.h"

hud::hud()
{
	this->nbrLife = 3;
	this->x = 0;
	this->y = 0;

	if (!this->texture.loadFromFile("texture/life.png"))
	{
		std::cout << "erreur d'image" << std::endl;
	}
	this->heart1 = this->creatSprite();
	this->heart2 = this->creatSprite();
	this->heart3 = this->creatSprite();
	this->item.setPosition(130, 5);
}


hud::~hud()
{

}

void hud::affichage(sf::RenderWindow* window, inventaire inv)
{
	this->nbrLife = inv.current_life;			//Combient de vie possède actuellement le joueur
	if (this->nbrLife >= 1)
	{
		this->heart1.setPosition(0,0);
		window->draw(this->heart1);
	}
	if (this->nbrLife >= 2)
	{
		this->heart2.setPosition(40,0);
		window->draw(this->heart2);
	}
	if (this->nbrLife >= 3)
	{
		this->heart3.setPosition(80,0);
		window->draw(this->heart3);
	}
	this->currentItem(inv);
	this->item.setTexture(this->itemText);
	window->draw(this->item);
}

void hud::currentItem(inventaire inv)
{
	switch (inv.current_item)
	{
		case 0:
			this->itemText.loadFromFile("texture/items/poing1.png");
			break;
		
		case 1:
			this->itemText.loadFromFile("texture/items/poing1.png");
			break;

		case 2:
			this->itemText.loadFromFile("texture/items/conserve.png");
			break;

		case 3:
			this->itemText.loadFromFile("texture/items/knife2.png");
			break;

		case 4:
			this->itemText.loadFromFile("texture/items/axe.png");
			break;

		case 5:
			this->itemText.loadFromFile("texture/items/gas_masque.png");
			break;
	}
}

sf::Sprite hud::creatSprite()
{
	sf::Sprite sprite;
	sprite.setTexture(this->texture);
	sprite.setScale(0.05f, 0.05f);


	return sprite;
}