#include "Player.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) : 
        animatedentity(texture, imageCount, switchTime)
{
	this->speed = speed;
    row = 0;
    faceRight = true;

    body.setSize(sf::Vector2f(32.f, 32.f));
    body.setOrigin(body.getSize() / 2.f);
    body.setPosition(sf::Vector2f(SIZE_TILE, SIZE_TILE));
    body.setTexture(texture);
}
Player::~Player()
{

}

void Player::Move(float deltaTime)
{
	{
		oldPos = body.getGlobalBounds();
		sf::Vector2f movement(0.f, 0.f);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			movement.x -= speed;
			row = 1;
			animatedentity.Update(row, deltaTime, faceRight);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			movement.x += speed;
			row = 0;
			animatedentity.Update(row, deltaTime, faceRight);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			movement.y -= speed;
			row = 3;
			animatedentity.Update(row, deltaTime, faceRight);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			movement.y += speed;
			row = 2;
			animatedentity.Update(row, deltaTime, faceRight);
		}

		std::cout << GetPosition().x << std::endl;
		std::cout << GetPosition().y << std::endl;
		body.setTextureRect(animatedentity.uvRect);
		body.move(movement);
	}
}

void Player::Draw(sf::RenderTarget* target)
{
	target->draw(this->body);
}