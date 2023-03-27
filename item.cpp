#include "item.h"

item::item(std::string texture, int i, int j, int num)
{
	this->x = i * SIZE_TILE;
	this->y = j * SIZE_TILE;
	this->num_obj = num;

	if (!this->texture.loadFromFile("texture/"+texture))
	{
		std::cout << "erreur d'image" << std::endl;
	}
	this->sprite.setPosition(this->x, this->y);
}

item::~item()
{

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