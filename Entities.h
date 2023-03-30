#include "General.h"

class Entities {
public :
	int ID, HpEntities, DamageEntities, ArmorEntities, SpeedEntities, PosXEntities, PosYEntities;
	float SizeXEntities, SizeYEntities;

	string CategoryEntities, NameTextureOnFile, NameEntities, Format, NameTexture;
	sf::Sprite SpriteEntitiesLoader();
	sf::Texture TextureEntitiesLoader();
	void SpriteLoaderSettings();
	void MoveUpdate();
	void CollisionEntitiesWithMap(int map[20][20]);
	//sf::Vector2f GetPositionEntities();
protected :
	sf::Sprite NameSpriteEntities;
	sf::Texture NameTextureEntities;
	sf::RectangleShape BodyEntities;
	sf::Clock clock;
};