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
	sf::Vector2f position(PosX, PosY);
	float dt = clock.restart().asSeconds();
	sf::Vector2f velocity(32.f, 0.f);
	position += velocity * dt;
	NameSpriteEntities.setPosition(position);
}
