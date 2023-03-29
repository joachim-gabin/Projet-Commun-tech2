#include "Player.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, int health, int armor) :
        animatedentity(texture, imageCount, switchTime)
{
	this->health = health;
	this->armor = armor;
	this->speed = speed;
    row = 0;
    faceRight = true;

    body.setSize(sf::Vector2f(SIZE_TILE, SIZE_TILE));
    body.setOrigin(body.getSize() / 2.f);
    body.setPosition(sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2));
    body.setTexture(texture);
}
Player::~Player()
{

}

void Player::Move(float deltaTime)
{
	{
		sf::Vector2f velocity;
		velocity.x = 0.f;
		velocity.y = 0.f;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			velocity.x -= speed * deltaTime;
			row = 1;
			animatedentity.Update(row, deltaTime, faceRight);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			velocity.x += speed * deltaTime;
			row = 0;
			animatedentity.Update(row, deltaTime, faceRight);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			velocity.y -= speed * deltaTime;
			row = 3;
			animatedentity.Update(row, deltaTime, faceRight);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			velocity.y += speed * deltaTime;
			row = 2;
			animatedentity.Update(row, deltaTime, faceRight);
		}

		std::cout << GetPosition().x << std::endl;
		std::cout << GetPosition().y << std::endl;
		std::cout << speed << std::endl;
		body.setTextureRect(animatedentity.uvRect);
		body.move(velocity);
	}
}

void Player::Collision()
{
	if (GetPosition().x < 0.f)
	{
		body.setPosition(0.f, body.getPosition().y);
	};
	
	if (GetPosition().y < 0.f)
	{
		body.setPosition(body.getPosition().x, 0.f);
	};

	/*if (GetPosition().x + body.getGlobalBounds().width > WINDOW_WIDTH);
	{
		body.setPosition(WINDOW_WIDTH - body.getGlobalBounds().width, GetPosition().y);
	}

	if (GetPosition().y + body.getGlobalBounds().height  > WINDOW_HEIGHT);
	{
		body.setPosition(GetPosition().x, WINDOW_HEIGHT - body.getGlobalBounds().height);
	}*/
}

void Player::Shooting()
{

}

void Player::HpSys()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
	{
		this->health -= 1;
	}
}

void Player::Sprint(float speed)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		this->speed = 3000.f;
	}
	else
	{
		this->speed = speed;
	}
}

void Player::Draw(sf::RenderTarget* target)
{
	target->draw(this->body);
}