#include "General.h"

class Entities {
public :
	int Hp, Damage, Armor, Speed, PosX, PosY;
	float SizeX, SizeY;
	string NameEntities;
	string Format;
	string NameTexture;
	sf::Sprite SpriteEntitiesLoader();
	sf::Texture TextureEntitiesLoader();
	void SpriteLoaderSettings();
	void MoveUpdate();
	//sf::Vector2f GetPositionEntities();
protected :
	sf::Sprite NameSpriteEntities;
	sf::Texture NameTextureEntities;
	sf::RectangleShape BodyEntities;
	sf::Clock clock;
};