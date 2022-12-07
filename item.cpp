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
int item::interaction(int x, int y)
{
	if (x >= this->x - SIZE_TILE && y >= this->y - SIZE_TILE && x <= this->x + SIZE_TILE && y <= this->y + SIZE_TILE)
	{
		std::cout << "interaction possible" << std::endl;
		return 1;
	}
	return 0;
}
sf::Sprite item::item_sprite()
{
	this->sprite.setTexture(this->texture);
	return this->sprite;
}