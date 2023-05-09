#include "Entities.h"

class Enemy : public Entities {
public:
	Enemy(string Category, int ValueEntities);
	~Enemy();

	sf::Vector2f GetPosition() { return BodyEntities.getPosition(); }

private:
	int Value;
	string IDString;

	void Generation();
	//void ReadCsv();
	void ReadJson();

};