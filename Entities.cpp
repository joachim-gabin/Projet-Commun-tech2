#include "Entities.h"

sf::Sprite Entities::SpriteEntitiesLoader() 
{
	return this->NameSpriteEntities;
}

sf::Texture Entities::TextureEntitiesLoader()
{
	NameTexture = NameEntities + "." + Format;
	if (!NameTextureEntities.loadFromFile("texture/" + NameTexture))
	{
		std::cout << "pas charger l'image" << std::endl;
	}

	return this->NameTextureEntities;
}

void Entities::SpriteLoader()
{
	NameSpriteEntities.setTexture(NameTextureEntities);
}
