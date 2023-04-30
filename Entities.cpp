#include "Entities.h"

Entities::Entities() {

}

Entities::~Entities() {

}

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

	*p_A = (int)NameSpriteEntities.getPosition().x;
	*p_B = (int)NameSpriteEntities.getPosition().x + 200;
}

void Entities::MoveUpdate()
{
	
	//if (time.asSeconds() > 1)
	//{
		//PosXEntities += SpeedEntities;
		//NameSpriteEntities.setPosition(PosXEntities, PosYEntities);

	if (NameSpriteEntities.getPosition().x != B && ValidPath == false) {
		PosXEntities += SpeedEntities / 10;
		NameSpriteEntities.setPosition(PosXEntities, PosYEntities);

		if (NameSpriteEntities.getPosition().x == B) {
			time = clock.getElapsedTime();
			ValidPath = true;
			if (time.asSeconds() > 1.5) {
				NameSpriteEntities.setScale(-SizeXEntities, SizeYEntities);
				clock.restart();
			}
		}
	}
	else if (NameSpriteEntities.getPosition().x != A && ValidPath == true) {
		PosXEntities -= SpeedEntities / 10;
		NameSpriteEntities.setPosition(PosXEntities, PosYEntities);

		if (NameSpriteEntities.getPosition().x == A) {
			time = clock.getElapsedTime();
			ValidPath = false;
			if (time.asSeconds() > 1.5) {
				NameSpriteEntities.setScale(SizeXEntities, SizeYEntities);
				clock.restart();
			}
		}
	}
	
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
