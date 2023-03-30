#pragma once
#include "General.h"
#include "AnimatedEntity.h"
#include "inventaire.h"

class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u ImageCount, float switchTime, float speed, int hp, int armor);
	~Player();

	void Move(float deltaTime);
	void UseItem(inventaire inv);
	void Draw(sf::RenderTarget* target);
	void Collision();
	void Shooting();
	void HpSys();
	void Sprint(float speed);
	int x, y;
	bool immuneToGas;
	int health;
	int armor;

	sf::Vector2f GetPosition() { return body.getPosition(); }
	sf::FloatRect oldPos;
	sf::FloatRect nextPos;

private:

	float speed;
	bool faceRight;
	unsigned int row;
	sf::RectangleShape body;
	sf::Sprite sprite;
	sf::Texture texture;
	AnimatedEntity animatedentity;
};