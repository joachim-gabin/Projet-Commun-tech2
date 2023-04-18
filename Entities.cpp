#include "Entities.h"

sf::Sprite Entities::SpriteEntitiesLoader()
{
	return this->NameSpriteEntities;
}
// load the texture of the entitie 
sf::Texture Entities::TextureEntitiesLoader()
{
	NameTexture = NameTextureOnFile + "." + Format;
	if (!NameTextureEntities.loadFromFile("texture/Entities/" + NameTexture))
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
	//sf::Time time = clock.getElapsedTime();
	//if (time.asSeconds() > 1)
	//{
		PosXEntities += SpeedEntities;
		NameSpriteEntities.setPosition(PosXEntities, PosYEntities);
		//clock.restart();
	//}
}

//void Entities::CollisionEntitiesWithMap(int map[20][20])
//{
//	if (BodyEntities.getPosition().x < 0.f)
//	{
//		BodyEntities.setPosition(0.f, BodyEntities.getPosition().y);
//	}
//
//	if (BodyEntities.getPosition().y < 0.f)
//	{
//		BodyEntities.setPosition(BodyEntities.getPosition().x, 0.f);
//	}
//
//	if (BodyEntities.getPosition().x > WINDOW_WIDTH)
//	{
//		BodyEntities.setPosition(WINDOW_WIDTH, BodyEntities.getPosition().y);
//	}
//
//	if (BodyEntities.getPosition().y > WINDOW_HEIGHT)
//	{
//		BodyEntities.setPosition(BodyEntities.getPosition().x, WINDOW_HEIGHT);
//	}
//	if (map[((int)BodyEntities.getPosition().y - 10) / 32][(int)BodyEntities.getPosition().x / 32] != 0)
//	{
//		BodyEntities.setPosition(BodyEntities.getPosition().x, BodyEntities.getPosition().y + 16);
//	}
//	if (map[((int)BodyEntities.getPosition().y + 10) / 32][(int)BodyEntities.getPosition().x / 32] != 0)
//	{
//		BodyEntities.setPosition(BodyEntities.getPosition().x, BodyEntities.getPosition().y - 16);
//	}
//	if (map[(int)BodyEntities.getPosition().y / 32][((int)BodyEntities.getPosition().x - 10) / 32] != 0)
//	{
//		BodyEntities.setPosition(BodyEntities.getPosition().x + 16, BodyEntities.getPosition().y);
//	}
//	if (map[(int)BodyEntities.getPosition().y / 32][((int)BodyEntities.getPosition().x + 10) / 32] != 0)
//	{
//		BodyEntities.setPosition(BodyEntities.getPosition().x - 16, BodyEntities.getPosition().y);
//	}
//}

//sf::Vector2f Entities::GetPositionEntities()
//{
//	return BodyEntities.getPosition();
//}
