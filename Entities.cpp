#include "Entities.h"

sf::Sprite Entities::SpriteEntitiesLoader()
{
	return this->NameSpriteEntities;
}
// load the texture of the entitie 
sf::Texture Entities::TextureEntitiesLoader()
{
	NameTexture = NameTextureOnFile + "." + Format;
	if (!NameTextureEntities.loadFromFile("texture/" + NameTexture))
	{
		std::cout << "pas charger l'image" << std::endl;
	}
	NameSpriteEntities.setPosition(PosXEntities, PosYEntities);

	return this->NameTextureEntities;
}
// set the entire of what the entitie need
void Entities::SpriteLoaderSettings()
{
	NameSpriteEntities.setTexture(NameTextureEntities);
	BodyEntities.setTexture(&NameTextureEntities);
	NameSpriteEntities.setPosition(PosXEntities, PosYEntities);
	NameSpriteEntities.setScale(SizeXEntities, SizeYEntities);
	BodyEntities.getGlobalBounds().width;
}

void Entities::MoveUpdate()
{
	sf::Time time = clock.getElapsedTime();
	if (time.asSeconds() > 1)
	{
		PosXEntities += SpeedEntities;
		NameSpriteEntities.setPosition(PosXEntities, PosYEntities);
		clock.restart();
	}
}

//sf::Vector2f Entities::GetPositionEntities()
//{
//	return BodyEntities.getPosition();
//}
