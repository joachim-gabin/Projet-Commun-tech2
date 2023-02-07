#include "General.h"

class Entities {

public :
	float Hp, Damage, Armor, Speed;
	string NameEntities;
	string Format;
	string NameTexture;
	int PosX, PosY;
	sf::Sprite SpriteEntitiesLoader();
	sf::Texture TextureEntitiesLoader();
	void SpriteLoader();
protected :
	sf::Sprite NameSpriteEntities;
	sf::Texture NameTextureEntities;
};