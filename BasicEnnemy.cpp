#include "BasicEnnemy.h"

void BasicEnnemy::ListBasicEnnemy(int ValueEntities)
{
	switch (ValueEntities) {
	case 1:
		NameEntities = "Zombie";
		Hp = 10;
		Damage = 10;
		Speed = 10;
	}
}
