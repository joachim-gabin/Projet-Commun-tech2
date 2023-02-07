#include "General.h"

class Entities {

public :
	int Hp, Damage, Armor, Speed, PosX, PosY;
	string NameEntities;
	string Format;
	string NameTexture;
	sf::Sprite SpriteEntitiesLoader();
	sf::Texture TextureEntitiesLoader();
	void SpriteLoader();
protected :
	sf::Sprite NameSpriteEntities;
	sf::Texture NameTextureEntities;
};