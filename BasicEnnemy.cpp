#include "BasicEnnemy.h"

void BasicEnnemy::ListBasicEnnemy(int ValueEntities)
{
	switch (ValueEntities) {
	case 1:
		NameEntities = "car";
		Format = "png";
		Hp = 10;
		Damage = 10;
		Speed = 10;
		PosX = 200;
		PosY = 200;
		TextureEntitiesLoader();
		SpriteLoader();
		break;
	}
}
