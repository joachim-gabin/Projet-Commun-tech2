#include "General.h"

class Entities {

public :
	float Hp, Damage, Armor;
	string NameEntities;
	int PosX, PosY;
	sf::Sprite SpriteEntitiesLoader(string NameEntities);
	sf::Texture TextureEntitiesLoader(string NameEntities);

private :
	sf::Sprite sprite;
	sf::Texture texture;
};