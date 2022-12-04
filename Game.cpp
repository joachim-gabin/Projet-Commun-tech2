#include "Game.h"
#include "item.h"
#include "Player.h"
#include "playground.h"
#include "inventaire.h"

Game::Game()
{
    this->initVariables();
    this->gameInit();
    this->gameLoop();
}
Game::~Game()
{

}
void Game::initVariables()
{
    this->window = nullptr;
}
void Game::gameInit()
{
    this->window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Last Man");
}
void Game::gameLoop()
{


    sf::Texture texture_sable;
    if (!texture_sable.loadFromFile("texture/sable.png"))
    {
        std::cout << "erreur d'image" << std::endl;
    }
    sf::Sprite sprite; 
    sprite.setTexture(texture_sable);

    sf::Texture texture_bush;
    if (!texture_bush.loadFromFile("texture/bush.png"))
    {
        std::cout << "erreur d'image" << std::endl;
    }
    sf::Sprite sprite_b;
    sprite_b.setTexture(texture_bush);


    item axe("axe.png", 10, 10);
    player player("survivant.png",2 , 2);
    inventaire inv;


    while (this->window->isOpen())
    {
        this->window->clear();

        while (this->window->pollEvent(this->event))
        {
            if (this->event.type == sf::Event::Closed)
                this->window->close();

            if (this->event.type == sf::Event::KeyPressed)
            {
                player.move();
                if (this->event.key.code == sf::Keyboard::Escape)
                {
                    this->window->close();
                }

                if (this->event.key.code == sf::Keyboard::Tab)
                {
                    inv.statut++;
                    inv.statut = inv.statut % 2;
                    std::cout << inv.statut << std::endl;
                }

                if (this->event.key.code == sf::Keyboard::A)
                {
                    end = true;
                    while (end == true)
                    {
                        this->window->clear();
                        this->window->display();
                    }
                }
            }
        }
        //this->window->clear();
        for (int r = 0; r <= WINDOW_HEIGHT / 32; r++)
        {
            for (int n = 0; n <= WINDOW_WIDTH/32; n++)
            {
                if (r == 0 || r == 19)
                {
                    sprite_b.setPosition(n * 32, r * 32);
                    this->window->draw(sprite_b);
                }
                else
                {
                    sprite.setPosition(n * 32, r*32);
                    this->window->draw(sprite);
                }

            }
        }
        if (axe.interaction(player.x, player.y))
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
            {

            }
        }
        if (inv.statut >= 1)
        {
            this->window->draw(inv.affichage());
        }

        this->window->draw(player.sprite_player());
        this->window->draw(axe.item_sprite());
        this->window->display();

    }
}
