#include "Enemy.h"
#include "Player.h"

Enemy::Enemy(int ValueEntities, string Category)
{
	ID = ValueEntities;
	CategoryEntities = Category;
	Generation();
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

	ReadJson();

	TextureEntitiesLoader();
	SpriteLoaderSettings();
	//GetPositionEntities();

}

//void Enemy::ReadCsv()
//{
//	fstream File;
//
//	string Line;
//
//	File.open("EnemyOnCsv.csv", ios::in);
//
//	while (getline(File, Line)) {
//		stringstream ss(Line);
//
//		getline(ss, IDString, ',');
//		getline(ss, NameEntities, ',');
//		getline(ss, Format, ',');
//		getline(ss, HPString, ',');
//		getline(ss, DamageString, ',');
//		getline(ss, SpeedString, ',');
//		getline(ss, PosXString, ',');
//		getline(ss, PosYString, ',');
//		getline(ss, SizeXString, ',');
//		getline(ss, SizeYString, ',');
//
//		ID = stoi(IDString);
//
//		HpEntities = stoi(HPString);
//		DamageEntities = stoi(DamageString);
//		SpeedEntities = stoi(SpeedString);
//
//		PosXEntities = stof(PosXString);
//		PosYEntities = stof(PosYString);
//		SizeXEntities = stof(SizeXString);
//		SizeYEntities = stof(SizeYString);
//
//	}
//	File.close();
//}

void Enemy::ReadJson()
{
	ifstream file("EnemyOnJson.json");

	Json::Value actualValue;
	Json::Reader reader;

	reader.parse(file, actualValue);

	IDString = to_string(ID);

	NameEntities = actualValue[CategoryEntities][IDString]["Name"].asString();
	NameTextureOnFile = actualValue[CategoryEntities][IDString]["NameTexture"].asString();
	Format = actualValue[CategoryEntities][IDString]["Format"].asString();
	HpEntities = actualValue[CategoryEntities][IDString]["HP"].asInt();
	DamageEntities = actualValue[CategoryEntities][IDString]["Damage"].asInt();
	SpeedEntities = actualValue[CategoryEntities][IDString]["Speed"].asInt();
	PosXEntities = actualValue[CategoryEntities][IDString]["PosX"].asInt();
	PosYEntities = actualValue[CategoryEntities][IDString]["PosY"].asInt();
	SizeXEntities = actualValue[CategoryEntities][IDString]["SizeX"].asFloat();
	SizeYEntities = actualValue[CategoryEntities][IDString]["SizeY"].asFloat();



	cout << NameEntities;

}
