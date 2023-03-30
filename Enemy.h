#include "Entities.h"

class Enemy : public Entities {
public:
	

	Enemy(int ValueEntities, string Category);
private:
	int Value;
	string IDString;

	void Generation();
	//void ReadCsv();
	void ReadJson();
	// void Collision();
};