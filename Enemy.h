#include "Entities.h"
#include <windows.data.json.h>

class Enemy : public Entities {
public:
	int Value;

	Enemy(int ValueEntities);
private:
	void ListEnemy();
	void Generation();
	void ReadCsv();

	// void Collision();
};