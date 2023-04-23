#include "Player.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, int health, int armor) :
        animatedentity(texture, imageCount, switchTime)
{
	this->health = health;
	this->armor = armor;
	this->speed = speed;
    row = 0;
    faceRight = true;
	immuneToGas = false;

    body.setSize(sf::Vector2f(SIZE_TILE, SIZE_TILE));
    body.setOrigin(body.getSize() / 2.f);
    body.setPosition(sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2));
    body.setTexture(texture);

	this->GenerateAttackTexture();
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
			velocity.x -= speed;
			row = 1;
			animatedentity.Update(row, deltaTime, faceRight);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			velocity.x += speed;
			row = 0;
			animatedentity.Update(row, deltaTime, faceRight);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			velocity.y -= speed;
			row = 3;
			animatedentity.Update(row, deltaTime, faceRight);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			velocity.y += speed;
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

void Player::UseItem(inventaire inv)
{
	int currentItem = inv.current_item;

	switch (currentItem)
	{
	case 1:			//Attaque aux poings
		break;

	case 2:			//Utilise Conserve pour vie+1
		if (inv.current_life < 3)
		{
			inv.addLife(1);
			std::cout << "Vous avez utilisé une conserve, elle était délicieuse" << std::endl;
		}
		else
		{
			std::cout << "Vous possedez deja toute votre sante" << std::endl;
		}
		break;

	case 3:			//Attaque au couteau
		break;

	case 4:			//Attaque à la hache
		break;
	}

	if (currentItem == 5)		//Utilise masque a gaz
	{
		immuneToGas = true;
		std::cout << "Vous enfilez le masque a gaz" << std::endl;
	}
}






void Player::Collision(int map[20][20])
{
	if (GetPosition().x < 0.f)
	{
		body.setPosition(0.f, body.getPosition().y);
	}
	
	if (GetPosition().y < 0.f)
	{
		body.setPosition(body.getPosition().x, 0.f);
	}

	if (GetPosition().x > WINDOW_WIDTH)
	{
		body.setPosition(WINDOW_WIDTH, GetPosition().y);
	}

	if (GetPosition().y > WINDOW_HEIGHT)
	{
		body.setPosition(GetPosition().x, WINDOW_HEIGHT);
	}
	if (map[((int)GetPosition().y - 10) / 32][(int)GetPosition().x / 32] != 0)
	{
		body.setPosition(GetPosition().x, GetPosition().y + 16);
	}
	if (map[((int)GetPosition().y + 10) / 32][(int)GetPosition().x / 32] != 0)
	{
		body.setPosition(GetPosition().x, GetPosition().y - 16);
	}
	if (map[(int)GetPosition().y / 32][((int)GetPosition().x - 10) / 32] != 0)
	{
		body.setPosition(GetPosition().x + 16, GetPosition().y);
	}
	if (map[(int)GetPosition().y / 32][((int)GetPosition().x + 10) / 32] != 0)
	{
		body.setPosition(GetPosition().x - 16, GetPosition().y);
	}
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
		this->speed = 32.f;
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

void Player::GenerateAttackTexture()
{
	if (!this->AttTexture.loadFromFile("texture/Entities/QaQ.png"))
	{
		std::cout << "erreur d'image" << std::endl;
	}
	this->AttSprite.setTexture(this->AttTexture);
}

void Player::Attack(sf::RenderWindow* window)
{
	this->AttSprite.setScale(0.5f, 0.5f);
	this->AttSprite.setPosition(200,200);
	window->draw(this->AttSprite);
}