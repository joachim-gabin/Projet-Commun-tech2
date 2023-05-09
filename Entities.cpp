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
	BodyEntities.setSize(VectorEntities);

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
		PosXEntities += SpeedEntities / 10.f;
		BodyEntities.setPosition(PosXEntities, PosYEntities);

		if (BodyEntities.getPosition().x == B) {
			time = clock.getElapsedTime();
			ValidPath = true;
			if (time.asSeconds() > 1.5) {
				BodyEntities.setScale(VectorEntities.x / -32, VectorEntities.y - 31); // flip shape texture in negative
				clock.restart();
			}
		}
	}
	else if (BodyEntities.getPosition().x != A && ValidPath == true) {
		PosXEntities -= SpeedEntities / 10.f;
		BodyEntities.setPosition(PosXEntities, PosYEntities);

		if (BodyEntities.getPosition().x == A) {
			time = clock.getElapsedTime();
			ValidPath = false;
			if (time.asSeconds() > 1.5) {
				BodyEntities.setScale(VectorEntities.x / 32, VectorEntities.y - 31); // reset shape texture in the good position
				clock.restart();
			}
		}
	}
	
//}
}

bool Entities::Collision(Player player, inventaire inv)
{
	// Recupére la taille des rectangles
	sf::FloatRect box = BodyEntities.getGlobalBounds();
	sf::FloatRect pBox = player.body.getGlobalBounds();

	// Si le carré blanc autour du player touche le carré blanc autour des ennemis se touchent alors hp -1
	if (pBox.intersects(box))
	{
		if (DamageClock.getElapsedTime().asSeconds() >= 1)
		{
			DamageClock.restart();
			std::cout << player.health << std::endl;
			return true;
		}
		return false;
	}
}