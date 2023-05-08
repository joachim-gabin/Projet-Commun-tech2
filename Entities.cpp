#include "Entities.h"

Entities::Entities() {

}

Entities::~Entities() {

}

void Entities::DrawEntities(sf::RenderTarget* window)
{
	//window->draw(NameSpriteEntities);
	window->draw(BodyEntities);
}

sf::Sprite Entities::SpriteEntitiesLoader()
{
	return NameSpriteEntities;
}
// load the texture of the entitie 
sf::Texture Entities::TextureEntitiesLoader()
{
	NameTexture = NameTextureOnFile + "." + Format;
	if (!NameTextureEntities.loadFromFile("texture/Entities/" + NameTexture))
	{
		std::cout << "pas charger l'image" << std::endl;
	}
	NameTextureEntities.setSmooth(true);
	return this->NameTextureEntities;
}
// set the entire of what the entitie need
void Entities::SpriteLoaderSettings()
{
	VectorEntities = {SizeXEntities, SizeYEntities};
	//NameSpriteEntities.setTexture(NameTextureEntities);
	BodyEntities.setTexture(&NameTextureEntities);
	//NameSpriteEntities.setPosition(PosXEntities, PosYEntities);
	//NameSpriteEntities.setScale(SizeXEntities, SizeYEntities);
	BodyEntities.setPosition(PosXEntities, PosYEntities);
	BodyEntities.getGlobalBounds().width;
	BodyEntities.setSize(VectorEntities);
	BodyEntities.setOutlineThickness(3);

	*p_A = (int)BodyEntities.getPosition().x;
	*p_B = (int)BodyEntities.getPosition().x + 200;
}

void Entities::MoveUpdate()
{
	
	//if (time.asSeconds() > 1)
	//{
		//PosXEntities += SpeedEntities;
		//NameSpriteEntities.setPosition(PosXEntities, PosYEntities);

	if (BodyEntities.getPosition().x != B && ValidPath == false) {
		PosXEntities += SpeedEntities / 10;
		BodyEntities.setPosition(PosXEntities, PosYEntities);

		if (BodyEntities.getPosition().x == B) {
			time = clock.getElapsedTime();
			ValidPath = true;
			if (time.asSeconds() > 1.5) {
				BodyEntities.setSize(VectorEntities);
				clock.restart();
			}
		}
	}
	else if (BodyEntities.getPosition().x != A && ValidPath == true) {
		PosXEntities -= SpeedEntities / 10;
		BodyEntities.setPosition(PosXEntities, PosYEntities);

		if (BodyEntities.getPosition().x == A) {
			time = clock.getElapsedTime();
			ValidPath = false;
			if (time.asSeconds() > 1.5) {
				BodyEntities.getSize().x;
				clock.restart();
			}
		}
	}
	
//}
}

void Entities::Collision(Player player)
{
	//if (PosXEntities && PosYEntities <= player.GetPosition().x && player.GetPosition().y)
	//{
	//	player.health -= 1;
	//	std::cout << player.health << std::endl;
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
