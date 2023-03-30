#include "Game.h"
#include "item.h"
#include "Player.h"
#include "playground.h"
#include "inventaire.h"
#include "Hud.h"
#include "MapEditor.h"
#include "Enemy.h"
#include "MainMenu.h"

using recursive_directory_iterator = std::filesystem::recursive_directory_iterator;

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

    //Lis le fichier map.txt
    fstream newfile;
    newfile.open("map.txt", ios::in);
    if (newfile.is_open())
    {
        string tp;
        int x = 0;
        while (getline(newfile, tp))
        {
            int y = 0;
            for (char& c : tp)
            {
                map[x][y] = (int)c - 48;
                y += 1;
            }
            x += 1;

        }
        newfile.close();
    }


    //Lis le fichier items.txt
    newfile.open("items.txt", ios::in);
    if (newfile.is_open())
    {
        string tp;
        int x = 0;
        while (getline(newfile, tp))
        {
            int y = 0;
            for (char& c : tp)
            {
                items[x][y] = (int)c - 48;
                y += 1;
            }
            x += 1;

        }
        newfile.close();
    }
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
    Player player(&playerTexture, sf::Vector2u(2, 4), 0.01f, 2000.f, 20,5);


    //Initialise les array de texture et de sprite des tiles
    sf::Sprite sprites[2][100];
    sf::Texture textures[2][100];


    //Load les textures et les sprites du dossier tiles
    int nbTiles = 0;
    for (const auto& dirEntry : recursive_directory_iterator("texture/tiles/"))
    {
        std::cout << dirEntry.path().string() << std::endl;
        sf::Texture texture;
        textures[0][nbTiles] = texture;
        if (!textures[0][nbTiles].loadFromFile(dirEntry.path().string()))
        {
            std::cout << "erreur d'image" << std::endl;
        }
        sf::Sprite sprite;
        sprites[0][nbTiles] = sprite;
        sprites[0][nbTiles].setTexture(textures[0][nbTiles]);
        nbTiles++;
    }


    //Load les textures et les sprites du dossier items
    int nbItems = 0;
    for (const auto& dirEntry : recursive_directory_iterator("texture/items/"))
    {
        sf::Texture texture;
        textures[1][nbItems] = texture;
        if (!textures[1][nbItems].loadFromFile(dirEntry.path().string()))
        {
            std::cout << "erreur d'image" << std::endl;
        }
        sf::Sprite sprite;
        sprites[1][nbItems] = sprite;
        sprites[1][nbItems].setTexture(textures[1][nbItems]);
        nbItems++;
    }


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

        //Dessine la map
        for (int r = 0; r < WINDOW_HEIGHT / 32; r++)
        {
            for (int n = 0; n < WINDOW_WIDTH / 32; n++)
            {
                sprites[0][map[r][n]].setPosition(n * 32, r * 32);
                this->window->draw(sprites[0][map[r][n]]);
                sprites[1][items[r][n]].setPosition(n * 32, r * 32);
                this->window->draw(sprites[1][items[r][n]]);
            }
        }

        enemy.MoveUpdate();
        playerHud.affichage(this->window,inv);
        player.Collision();
        player.Draw(this->window);
        player.Sprint(2000.f);

        this->window->draw(enemy.SpriteEntitiesLoader());
        this->window->display();

    }
}