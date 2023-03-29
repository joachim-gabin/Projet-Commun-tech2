#include "General.h"

class Entities {
public :
	int ID, HpEntities, DamageEntities, ArmorEntities, SpeedEntities, PosXEntities, PosYEntities;
	float SizeXEntities, SizeYEntities;
	string NameEntities, Format, NameTexture, CategoryEntities;
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