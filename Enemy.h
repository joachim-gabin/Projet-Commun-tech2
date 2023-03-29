#include "Entities.h"

class Enemy : public Entities {
public:
	

	Enemy(int ValueEntities);
private:
	int Value;
	string IDString, HPString, DamageString, SpeedString, PosXString, PosYString, SizeXString, SizeYString;

	void ListEnemy();
	void Generation();
	void ReadCsv();
	void ReadJson();
	// void Collision();
};