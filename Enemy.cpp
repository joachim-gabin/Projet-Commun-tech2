#include "Enemy.h"



Enemy::Enemy(int ValueEntities)
{
	Value = ValueEntities;
	ListEnemy();
}

void Enemy::ListEnemy()
{
	switch (Value) {
	case 1:
		NameEntities = "zombie";
		Format = "png";
		Hp = 10;
		Damage = 10;
		Speed = 10;
		PosX = 200;
		PosY = 200;
		SizeX = 0.15f;
		SizeY = 0.15f;
		TextureEntitiesLoader();
		SpriteLoaderSettings();
		MoveUpdate();
		break;
	}
}
