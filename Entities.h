#include "General.h"

class Entities {
public :

	Entities();
	~Entities();

	int ID, HpEntities, DamageEntities, ArmorEntities, SpeedEntities, PosXEntities, PosYEntities;
	float SizeXEntities, SizeYEntities;

	int A = 200 ,B = 500,C = 400, D = 200;

	string CategoryEntities, NameTextureOnFile, NameEntities, Format, NameTexture;
	sf::Sprite SpriteEntitiesLoader();
	sf::Texture TextureEntitiesLoader();
	void SpriteLoaderSettings();
	void MoveUpdate();
	void AnimatedEntities();
	//void CollisionEntitiesWithMap(int map[20][20]);
	//sf::Vector2f GetPositionEntities();
protected :
	sf::Sprite NameSpriteEntities;
	sf::Texture NameTextureEntities;
	sf::RectangleShape BodyEntities;
	sf::Clock clock;
};