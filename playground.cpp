#include "playground.h"

Playground::Playground()
{

}

Playground::~Playground()
{
}

int Playground::load()
{

    if (!this->texture.loadFromFile("texture/sand.png"))
    {
        std::cout << "erreur d'image" << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}


sf::Sprite Playground::GetSprite()
{
    this->sprite.setTexture(this->texture);
    this->sprite.setScale(1.0f, 1.0f);
    return this->sprite;
}