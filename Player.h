#pragma once
#include "General.h"
#include "AnimatedEntity.h"
#include "inventaire.h"

class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u ImageCount, float switchTime, int health, int base, int speed, int armor);
	~Player();

	void Move(float deltaTime);
	void UseItem(inventaire inv);
	void Draw(sf::RenderTarget* target);
	void Collision(int map[20][20]);
	void HpSys();
	void Sprint(float speed);
	void GenerateAttackTexture();
	void Attack(sf::RenderWindow* window);

	int x, y;
	bool immuneToGas;
	int health;
	int basehealth;
	int armor;

	sf::Vector2f GetPosition() { return body.getPosition(); }
	sf::FloatRect oldPos;
	sf::FloatRect nextPos;

private:

	string IDString;
	float speed;
	bool faceRight;
	unsigned int row;
	sf::RectangleShape body;
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Sprite AttSprite;
	sf::Texture AttTexture;
	AnimatedEntity animatedentity;
};