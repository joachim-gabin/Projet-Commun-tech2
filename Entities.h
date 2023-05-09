#include "General.h"
#include "Player.h"
#include "inventaire.h"

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
	void DrawEntities(sf::RenderTarget* window);
	sf::Sprite SpriteEntitiesLoader();
	sf::Texture TextureEntitiesLoader();
	void SpriteLoaderSettings();
	void MoveUpdate();
	bool Collision(Player player, inventaire inv);

	
protected :
	sf::Clock DamageClock;
	sf::Sprite NameSpriteEntities;
	sf::Texture NameTextureEntities;
	sf::RectangleShape BodyEntities;
	sf::Clock clock;
	sf::Time time;
	sf::Vector2f VectorEntities;
};