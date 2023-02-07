#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class AnimatedEntity
{
public:
	AnimatedEntity(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	~AnimatedEntity();
	void Update(int row, float deltaTime, bool faceRight);


	sf::IntRect uvRect;
private:

	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	sf::Texture texture;

	float totalTime;
	float switchTime;
};