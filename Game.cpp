#include "Game.h"
#include "item.h"
#include "Player.h"
#include "playground.h"
#include "inventaire.h"
#include "Hud.h"
#include "MapEditor.h"
#include "Enemy.h"
#include "MainMenu.h"

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
    inventaire inv;
    hud playerHud;
    item knife("knife2.png", 8, 10, 3);
    item axe("axe.png", 10, 10, 4);
    item gas("gas_masque.png", 12, 10, 5);
    sf::Clock clock;
    sf::Texture playerTexture;


    float deltaTime = 0.f;
    playerTexture.loadFromFile("texture/Survivant11.png");
    Player player(&playerTexture, sf::Vector2u(2, 4), 0.2f, 2000.f);


    Enemy enemy(1);
    while (this->window->isOpen())
    {
        deltaTime = clock.restart().asSeconds();
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

                if (this->event.key.code == sf::Keyboard::Space)
                {
                    this->window->close();
                    MapEditor edit;
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

        if (inv.statut_knife == 0)
        {
            if (knife.interaction(this->window, player.GetPosition().x, player.GetPosition().y))
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))    //ajoute la hache a l'inventaire et d�truit l'objet 'axe'
                {
                    inv.ajout(knife.num_obj);
                    inv.statut_knife = 1;
                    knife.~item();
                }
            }
        }
        if (inv.statut_knife == 0)
        {
            this->window->draw(knife.item_sprite());
        }


        if (inv.statut_axe == 0)
        {
            if (axe.interaction(this->window, player.GetPosition().x, player.GetPosition().y))
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))    //ajoute la hache a l'inventaire et d�truit l'objet 'axe'
                {
                    inv.ajout(axe.num_obj);
                    inv.statut_axe = 1;
                    axe.~item();
                }
            }
        }
        if (inv.statut_axe == 0)
        {
            this->window->draw(axe.item_sprite());
        }

        if (inv.statut_gas == 0)
        {
            if (gas.interaction(this->window, player.GetPosition().x, player.GetPosition().y))
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))    //ajoute la hache a l'inventaire et d�truit l'objet 'axe'
                {
                    inv.ajout(gas.num_obj);
                    inv.statut_gas = 1;
                    gas.~item();
                }
            }
        }
        if (inv.statut_gas == 0)
        {
            this->window->draw(gas.item_sprite());
        }

        if (inv.statut >= 1)
        {
           inv.affichage(this->window);
           inv.select(this->event);
        }

        enemy.MoveUpdate();
        playerHud.affichage(this->window,inv);
        player.Collision();
        player.Draw(this->window);

        this->window->draw(enemy.SpriteEntitiesLoader());
        this->window->display();

    }
}