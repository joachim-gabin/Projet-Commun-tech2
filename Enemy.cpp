#include "Enemy.h"
#include "Player.h"

Enemy::Enemy(int ValueEntities)
{
	Value = ValueEntities;
	ListEnemy();
}

void Enemy::ListEnemy()
{
	switch (Value) {
	case 1:
		Generation();
		break;
	}
}

//void Enemy::Collision() {
//
//	//Collision enemy
//
//	if (enemy.GetPositionEntities().x <= player.GetPosition().x)
//	{
//		body.setPosition(0.f, body.getPosition().y);
//
//	};
//
//	if (GetPosition().y < 0.f)
//	{
//		body.setPosition(body.getPosition().x, 0.f);
//	};
//}

void Enemy::Generation() {
	NameEntities = "zombie";
	Format = "png";
	HpEntities = 10;
	DamageEntities = 10;
	SpeedEntities = 10;
	PosXEntities = 200;
	PosYEntities = 200;
	SizeXEntities = 0.15f;
	SizeYEntities = 0.15f;
	TextureEntitiesLoader();
	SpriteLoaderSettings();
	//GetPositionEntities();

}

void Enemy::ReadCsv()
{
	fstream File;

	string Line;


	//File.open("EnemyOnCsv.csv", ios::in);

	//if (File.good()) {
	//	//ID = ", ";
	//	NameEntities = "zombie";
	//	Format = "png";
	//	HpEntities = 10;
	//	DamageEntities = 10;
	//	SpeedEntities = 10;
	//	PosXEntities = 200;
	//	PosYEntities = 200;
	//	SizeXEntities = 0.15f;
	//	SizeYEntities = 0.15f;
	//}
}
