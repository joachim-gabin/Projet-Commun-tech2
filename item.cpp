#include "item.h"


item::item(int numObject, int CorX, int CorY)
{
	this->x = CorX * SIZE_TILE;
	this->y = CorY * SIZE_TILE;
	this->num_obj = numObject;

	this->category(numObject);
	this->sprite.setPosition(this->x, this->y);
}


item::~item()
{

}

void item::category(int itemType)
{
	string path;
	switch (itemType)
	{
		case 1:
			path = "poing1.png";
			break;

		case 2:
			path = "conserve.png";
			break;

		case 3:
			path = "knife2.png";
			break;

		case 4:
			path = "axe.png";
			break;

		case 5:
			path = "gas_masque.png";
			break;

	default:
		path = "poing1.png";
		break;
	}

	if (!this->texture.loadFromFile("texture/items/"+path))
	{
		std::cout << "erreur d'image" << std::endl;
	}
	this->sprite.setTexture(this->texture);
}

int item::interaction(sf::RenderWindow* window, int x, int y)
{
	sf::Sprite sprite;
	sf::Texture texture;
	if (!texture.loadFromFile("texture/interagir.png"))
	{
		std::cout << "erreur d'image" << std::endl;
	}
	sprite.setPosition(250,400);
	sprite.setTexture(texture);
	sprite.setScale(0.7f, 0.7f);


	if (x >= this->x && y >= this->y && x <= this->x + SIZE_TILE && y <= this->y + SIZE_TILE)
	{
		window->draw(sprite);
		return 1;
	}
	return 0;
}

sf::Sprite item::item_sprite()
{
	this->sprite.setTexture(this->texture);
	return this->sprite;
}