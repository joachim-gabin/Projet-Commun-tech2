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
	NameSpriteEntities.setPosition(PosX, PosY);

	return this->NameTextureEntities;
}

void Entities::SpriteLoaderSettings()
{
	NameSpriteEntities.setTexture(NameTextureEntities);
	BodyEntities.setTexture(&NameTextureEntities);
	NameSpriteEntities.setPosition(PosX, PosY);
	NameSpriteEntities.setScale(SizeX, SizeY);
	BodyEntities.getGlobalBounds().width;
}

void Entities::MoveUpdate()
{
	sf::Time time = clock.getElapsedTime();
	if (time.asSeconds() > 1)
	{
		PosX += Speed;
		NameSpriteEntities.setPosition(PosX, PosY);
		clock.restart();
	}
}

//sf::Vector2f Entities::GetPositionEntities()
//{
//	return BodyEntities.getPosition();
//}
