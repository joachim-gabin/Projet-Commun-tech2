#include "Entities.h"

class Enemy : public Entities {
public:
	

	Enemy(string Category, int ValueEntities);
private:
	int Value;
	string IDString;

	void Generation();
	//void ReadCsv();
	void ReadJson();
	// void Collision();
};