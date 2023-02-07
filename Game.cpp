#include "Game.h"
#include "item.h"
#include "Player.h"
#include "playground.h"
#include "inventaire.h"
#include "BasicEnnemy.h"

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
    float deltaTime = 0.0f;
    sf::Clock clock;
    deltaTime = clock.restart().asSeconds();

    sf::Texture texture_sable;
    if (!texture_sable.loadFromFile("texture/sable.png"))
    {
        std::cout << "erreur d'image" << std::endl;
    }
    sf::Sprite sprite; 
    sprite.setTexture(texture_sable);

    sf::Texture texture_baril;
    if (!texture_baril.loadFromFile("texture/baril.png"))
    {
        std::cout << "erreur d'image" << std::endl;
    }
    sf::Sprite sprite_baril;
    sprite_baril.setTexture(texture_baril);

    sf::Texture texture_bush;
    if (!texture_bush.loadFromFile("texture/bush.png"))
    {
        std::cout << "erreur d'image" << std::endl;
    }
    sf::Sprite sprite_b;
    sprite_b.setTexture(texture_bush);

    sf::Texture texture_tank;
    if (!texture_tank.loadFromFile("texture/tank3.png"))
    {
        std::cout << "erreur d'image" << std::endl;
    }
    sf::Sprite sprite_tank;
    sprite_tank.setTexture(texture_tank);
    sprite_tank.setPosition(400, 200);
    sprite_tank.rotate(-20.0f);
   
    BasicEnnemy ennemy;
    ennemy.ListBasicEnnemy(1);

    sf::Texture playerTexture;
    playerTexture.loadFromFile("texture/Survivant11.png");
    Player player(&playerTexture, sf::Vector2u(2, 4), 0.2f, 32.0f);

    item axe("axe.png", 10, 10, 1);
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

                player.Move(deltaTime);
                
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
                else if (r == 7 && n == 12)
                {
                    sprite_baril.setPosition(n * 32, r * 32);
                    this->window->draw(sprite_baril);
                }
                else
                {
                    sprite.setPosition(n * 32, r*32);
                    this->window->draw(sprite);
                }

            }
        }

        if (axe.interaction(this->window, player.GetPosition().x, player.GetPosition().y))
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
            {
                inv.ajout(axe.num_obj);
                //axe.~item();
            }
        }
        if (inv.statut >= 1)
        {
            (inv.affichage(this->window));
        }
        
        this->window->draw(player.sprite_player());

        player.Draw(window);
        this->window->draw(axe.item_sprite());
        this->window->draw(sprite_tank);
        this->window->draw(ennemy.SpriteEntitiesLoader());
        this->window->display();

    }
    player.Move(deltaTime);
}
