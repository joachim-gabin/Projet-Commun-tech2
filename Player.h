#pragma once
#include "General.h"
#include "AnimatedEntity.h"

class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u ImageCount, float switchTime, float speed);
	~Player();

	void Move(float deltaTime);
	void Draw(sf::RenderTarget* target);
	int x, y;

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