#include "Player.h"

player::player(std::string nom_texture, int i, int j)
{
	this->x = i * SIZE_TILE;
	this->y = j * SIZE_TILE;

	if (!this->texture.loadFromFile("texture/" + nom_texture))
	{
		std::cout << "erreur d'image" << std::endl;
	}
	this->sprite.setTexture(this->texture);
	this->sprite.setPosition(this->x, this->y);
}
player::~player()
{

}
void player::move()
{
    if (sf::Keyboard::isKeyPressed) //si n'importe quel touche est appuyé
    {
        std::cout << (this->x / 32) + (this->y / 32 * 60) << std::endl;
        if (this->x - SIZE_TILE > -SIZE_TILE)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {

                this->x -= SPEED;
                this->sprite.setPosition(x, y);

            }
        }
        if (this->x + SIZE_TILE < WINDOW_WIDTH)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                // la touche "flèche Droite" est enfoncée : on bouge le personnage a droite
                this->x += SPEED;
                this->sprite.setPosition(x, y);
            }
        }
        if (this->y + SIZE_TILE < WINDOW_HEIGHT)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                // la touche "flèche Bas" est enfoncée : on bouge le personnage en bas
                this->y += SPEED;
                this->sprite.setPosition(sf::Vector2f(x, y));
            }
        }
        if (this->y - SIZE_TILE > -SIZE_TILE)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                // la touche "flèche Haut" est enfoncée : on bouge le personnage en haut
                this->y -= SPEED;
                this->sprite.setPosition(sf::Vector2f(x, y));

            }
        }
    }
    else
    {
        //this->pause(this->last);
    }
}
sf::Sprite player::sprite_player()
{
    return this->sprite;
}