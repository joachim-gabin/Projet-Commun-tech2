#include "MapEditor.h"
#include "Game.h"

using recursive_directory_iterator = std::filesystem::recursive_directory_iterator;

// A ne pas utiliser tant que pas 100% fonctionnel

MapEditor::MapEditor()
{
    this->Init();
    this->Loop();
}

MapEditor::~MapEditor()
{

}

void MapEditor::Init()
{
	this->window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH + 160, WINDOW_HEIGHT), "Last Man Editor");
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
}

void MapEditor::Loop()
{
    sf::Font font;
    if (!font.loadFromFile("font/arial.ttf"))
    {
        std::cout << "erreur de police" << std::endl;
    }
    sf::Text text;
    text.setFont(font);
    text.setString("Current");
    text.setCharacterSize(24);
    text.setOrigin(44, 12);
    text.setPosition(160 / 2, WINDOW_HEIGHT / 2 + 32);
    /*text.setFillColor(sf::Color::Red);*/

    sf::Sprite sprites[10];
    sf::Texture textures[10];

    int i = 0;
    for (const auto& dirEntry : recursive_directory_iterator("texture/tiles/")) 
    {
        std::cout << dirEntry.path().string() << std::endl;
        sf::Texture texture;
        textures[i] = texture;
        if (!textures[i].loadFromFile(dirEntry.path().string()))
        {
            std::cout << "erreur d'image" << std::endl;
        }
        sf::Sprite sprite;
        sprites[i] = sprite;
        sprites[i].setTexture(textures[i]);
        i++;
    }

    /*sf::Texture texture_sable;
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
    sf::Sprite sprite_bar;
    sprite_bar.setTexture(texture_baril);

    sf::Texture texture_bush;
    if (!texture_bush.loadFromFile("texture/bush.png"))
    {
        std::cout << "erreur d'image" << std::endl;
    }
    sf::Sprite sprite_b;
    sprite_b.setTexture(texture_bush);*/



    while (this->window->isOpen())
    {
        this->window->clear();

        while (this->window->pollEvent(this->event))
        {
            if (this->event.type == sf::Event::Closed)
            {
                this->Save();
                this->window->close();
                Game game;
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2i localPosition = sf::Mouse::getPosition(*window);
                if (localPosition.x > 160 && localPosition.x < WINDOW_WIDTH + 160 && localPosition.y > 0 && localPosition.y < WINDOW_HEIGHT)
                {
                    map[(localPosition.y - localPosition.y % 32) / 32][((localPosition.x - 160) - (localPosition.x - 160) % 32) / 32] = this->actualTexture;
                }
                if (localPosition.x < 160 && localPosition.x > 0 && localPosition.y > 0 && localPosition.y < WINDOW_HEIGHT)
                {
                    int inMenu = 1;
                    while (inMenu == 1) {
                        this->window->clear();

                        while (this->window->pollEvent(this->event))
                        {
                            if (this->event.type == sf::Event::Closed)
                            {
                                this->window->close();
                                Game game;
                            }
                            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                            {
                                sf::Vector2i localPosition2 = sf::Mouse::getPosition(*window);
                                if (localPosition2.x > 160 && localPosition2.x < WINDOW_WIDTH + 160 && localPosition2.y > 0 && localPosition2.y < WINDOW_HEIGHT)
                                {
                                    this->actualTexture = (((localPosition2.y - (localPosition2.y % 128)) / 128) * 5) + ((localPosition2.x - 160) - (localPosition2.x - 160) % 128) / 128;
                                    cout << this->actualTexture;
                                    inMenu = 0;
                                }
                            }
                        }

                        sprites[actualTexture].setPosition(160 / 2 - 16, WINDOW_HEIGHT / 2 - 16);
                        this->window->draw(sprites[actualTexture]);

                        /*if (this->actualTexture == 1) {
                            sprite_b.setPosition(160 / 2 - 16, WINDOW_HEIGHT / 2 - 16);
                            this->window->draw(sprite_b);
                        }
                        else if (this->actualTexture == 2) {
                            sprite_bar.setPosition(160 / 2 - 16, WINDOW_HEIGHT / 2 - 16);
                            this->window->draw(sprite_bar);
                        }
                        else
                        {
                            sprite.setPosition(160 / 2 - 16, WINDOW_HEIGHT / 2 - 16);
                            this->window->draw(sprite);
                        }*/

                        window->draw(text);

                        for (int i = 0; i < 3; i++)
                            sprites[actualTexture].setPosition(128 * (i + 1) - 64 - 16 + 160, 128 * 1 - 64 - 16);

                        /*sprite.setPosition(128 * 1 - 64 - 16 + 160, 128 * 1 - 64 - 16);
                        this->window->draw(sprite);

                        sprite_b.setPosition(128 * 2 - 64 - 16 + 160, 128 * 1 - 64 - 16);
                        this->window->draw(sprite_b);

                        sprite_bar.setPosition(128 * 3 - 64 - 16 + 160, 128 * 1 - 64 - 16);
                        this->window->draw(sprite_bar);*/

                        this->window->display();
                    }
                }
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
            {

                sf::Vector2i localPosition = sf::Mouse::getPosition(*window);
                if (localPosition.x > 160 && localPosition.x < WINDOW_WIDTH + 160 && localPosition.y > 0 && localPosition.y < WINDOW_HEIGHT)
                {
                    map[(localPosition.y - localPosition.y % 32) / 32][((localPosition.x - 160) - (localPosition.x - 160) % 32) / 32] = 0;
                }
            }
        }

        sprites[actualTexture].setPosition(160 / 2 - 16, WINDOW_HEIGHT / 2 - 16);
        this->window->draw(sprites[actualTexture]);
        
        /*if (this->actualTexture == 1) {
            sprite_b.setPosition(160 / 2 - 16, WINDOW_HEIGHT / 2 - 16);
            this->window->draw(sprite_b);
        }
        else if (this->actualTexture == 2) {
            sprite_bar.setPosition(160 / 2 - 16, WINDOW_HEIGHT / 2 - 16);
            this->window->draw(sprite_bar);
        }
        else
        {
            sprite.setPosition(160 / 2 - 16, WINDOW_HEIGHT / 2 - 16);
            this->window->draw(sprite);
        }*/

        window->draw(text);

        for (int r = 0; r < WINDOW_HEIGHT / 32; r++)
        {
            for (int n = 0; n < WINDOW_WIDTH / 32; n++)
            {
                sprites[map[r][n]].setPosition(n * 32 + 160, r * 32);
                this->window->draw(sprites[map[r][n]]);

                /*if (map[r][n] == 1) {
                    sprite_b.setPosition(n * 32 + 160, r * 32);
                    this->window->draw(sprite_b);
                }
                else if (map[r][n] == 2) {
                    sprite_bar.setPosition(n * 32 + 160, r * 32);
                    this->window->draw(sprite_bar);
                }
                else
                {
                    sprite.setPosition(n * 32 + 160, r * 32);
                    this->window->draw(sprite);
                }*/
            }
        }
        this->window->display();
    }
}

void MapEditor::Save()
{
    fstream newfile;
    newfile.open("map.txt", ios::out);
    if (newfile.is_open()) 
    {
        for (int i = 0; i < WINDOW_HEIGHT / 32; i++)
        {
            for (int j = 0; j < WINDOW_WIDTH / 32; j++)
            {
                newfile << map[i][j];
            }
            newfile << "\n";
        }
        newfile.close();
    }
}
