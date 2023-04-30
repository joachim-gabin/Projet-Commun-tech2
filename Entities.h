#include "General.h"

class Entities {
public :

	Entities();
	~Entities();

	int ID, HpEntities, DamageEntities, ArmorEntities, SpeedEntities;
	float SizeXEntities, SizeYEntities, PosXEntities, PosYEntities;

	int A,
		B;

	//* C = NameSpriteEntities().getPosition();
	int* p_A = &A;
	int* p_B = &B;
	

	bool ValidPath = false;

	string CategoryEntities, NameTextureOnFile, NameEntities, Format, NameTexture;
	sf::Sprite SpriteEntitiesLoader();
	sf::Texture TextureEntitiesLoader();
	void SpriteLoaderSettings();
	void MoveUpdate();
	//void CollisionEntitiesWithMap(int map[20][20]);
	//sf::Vector2f GetPositionEntities();
protected :
	sf::Sprite NameSpriteEntities;
	sf::Texture NameTextureEntities;
	sf::RectangleShape BodyEntities;
	sf::Clock clock;
	sf::Time time;
};