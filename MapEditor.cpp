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


//Initialise la fenêtre 
void MapEditor::Init()
{
	this->window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH + 320, WINDOW_HEIGHT), "Last Man Editor");
    actualMapX, actualMapY = 0;
    Open();
}

void MapEditor::Open() 
{
    cout << "map/tiles/tiles" + to_string(actualMapX + actualMapY * (WINDOW_WIDTH / 32)) + ".txt";

    //Lis le fichier map.txt
    fstream newfile;
    newfile.open("map/map.txt", ios::in);
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

    //Lis le fichier map.txt
    newfile.open("map/tiles/tiles" + to_string(actualMapX + actualMapY * (WINDOW_WIDTH / 32)) + ".txt", ios::in);
    if (newfile.is_open())
    {
        string tp;
        int x = 0;
        while (getline(newfile, tp))
        {
            int y = 0;
            for (char& c : tp)
            {
                tiles[x][y] = (int)c - 48;
                y += 1;
            }
            x += 1;

        }
        newfile.close();
    }


    //Lis le fichier items.txt
    newfile.open("map/items/items" + to_string(actualMapX + actualMapY * (WINDOW_WIDTH / 32)) + ".txt", ios::in);
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

    //Lis le fichier Entities.txt
    newfile.open("map/entities/Entities" + to_string(actualMapX + actualMapY * (WINDOW_WIDTH / 32)) + ".txt", ios::in);
    if (newfile.is_open())
    {
        string tp;
        int x = 0;
        while (getline(newfile, tp))
        {
            int y = 0;
            for (char& c : tp)
            {
                Entities[x][y] = (int)c - 48;
                y += 1;
            }
            x += 1;

        }
        newfile.close();
    }
}


//Boucle de l'éditeur
void MapEditor::Loop()
{

    //Load les font et text
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

    sf::Text textTiles;
    textTiles.setFont(font);
    textTiles.setString("Tiles");
    textTiles.setCharacterSize(24);
    textTiles.setOrigin(44, 12);
    textTiles.setPosition(160 / 2, 32);

    sf::Text textItems;
    textItems.setFont(font);
    textItems.setString("Items");
    textItems.setCharacterSize(24);
    textItems.setOrigin(44, 12);
    textItems.setPosition(160 / 2, WINDOW_HEIGHT - 32);

    sf::Text textEntities;
    textEntities.setFont(font);
    textEntities.setString("Entities");
    textEntities.setCharacterSize(24);
    textEntities.setOrigin(44, 12);
    textEntities.setPosition(160 / 2, 32 + 64);

    sf::Text textAddAbove;
    textAddAbove.setFont(font);
    textAddAbove.setString("Add Above");
    textAddAbove.setCharacterSize(24);
    textAddAbove.setOrigin(44, 12);
    textAddAbove.setPosition(WINDOW_WIDTH + 160 + 160 / 2, 32);
    /*text.setFillColor(sf::Color::Red);*/

    sf::Text textAddBelow;
    textAddBelow.setFont(font);
    textAddBelow.setString("Add Below");
    textAddBelow.setCharacterSize(24);
    textAddBelow.setOrigin(44, 12);
    textAddBelow.setPosition(WINDOW_WIDTH + 160 + 160 / 2, 32 + 64);

    sf::Text textAddRight;
    textAddRight.setFont(font);
    textAddRight.setString("Add Right");
    textAddRight.setCharacterSize(24);
    textAddRight.setOrigin(44, 12);
    textAddRight.setPosition(WINDOW_WIDTH + 160 + 160 / 2, 32 + 128);

    sf::Text textAddLeft;
    textAddLeft.setFont(font);
    textAddLeft.setString("Add Left");
    textAddLeft.setCharacterSize(24);
    textAddLeft.setOrigin(44, 12);
    textAddLeft.setPosition(WINDOW_WIDTH + 160 + 160 / 2, 32 + 192);

    sf::Text textActualMap;
    textActualMap.setFont(font);
    textActualMap.setString("X = " + to_string(actualMapX) + " | Y = " + to_string(actualMapY));
    textActualMap.setCharacterSize(18);
    textActualMap.setOrigin(44, 12);
    textActualMap.setPosition(WINDOW_WIDTH + 160 + 160 / 2, WINDOW_HEIGHT / 2 + 32);

    //Initialise les array de texture et de sprite des tiles
    sf::Sprite sprites[3][100];
    sf::Texture textures[3][100];


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

    //load les texture et les sprite du dossier entities 
    int nbEntities = 0;
    for (const auto& dirEntry : recursive_directory_iterator("texture/Entities/"))
    {
        sf::Texture texture;
        textures[2][nbEntities] = texture;
        if (!textures[2][nbEntities].loadFromFile(dirEntry.path().string()))
        {
            std::cout << "erreur d'image" << std::endl;
        }
        sf::Sprite sprite;
        sprites[2][nbEntities] = sprite;
        sprites[2][nbEntities].setTexture(textures[2][nbEntities]);
        nbEntities++;
    }

    while (this->window->isOpen())
    {
        this->window->clear();

        while (this->window->pollEvent(this->event))
        {


            //Retour à l'écran du jeu lors de la fermeture de l'éditeur
            if (this->event.type == sf::Event::Closed)
            {
                this->Save();
                this->window->close();
                Game game;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                this->Save();
                this->window->close();
                Game game;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && actualMapY != 0)
            {
                if (map[actualMapY - 1][actualMapX] == 1) {
                    this->Save();
                    actualMapY--;
                    this->Open();
                    textActualMap.setString("X = " + to_string(actualMapX) + " | Y = " + to_string(actualMapY));
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && actualMapY != WINDOW_HEIGHT / 32 - 1)
            {
                if (map[actualMapY + 1][actualMapX] == 1) {
                    this->Save();
                    actualMapY++;
                    this->Open();
                    textActualMap.setString("X = " + to_string(actualMapX) + " | Y = " + to_string(actualMapY));
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && actualMapX != WINDOW_HEIGHT / 32 - 1)
            {
                if (map[actualMapY][actualMapX + 1] == 1) {
                    this->Save();
                    actualMapX++;
                    this->Open();
                    textActualMap.setString("X = " + to_string(actualMapX) + " | Y = " + to_string(actualMapY));
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && actualMapX != 0)
            {
                if (map[actualMapY][actualMapX - 1] == 1) {
                    this->Save();
                    actualMapX--;
                    this->Open();
                    textActualMap.setString("X = " + to_string(actualMapX) + " | Y = " + to_string(actualMapY));
                }
            }


            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {


                //Récupère la position de la souris et change la tile
                sf::Vector2i localPosition = sf::Mouse::getPosition(*window);
                if (localPosition.x > 160 && localPosition.x < WINDOW_WIDTH + 160 && localPosition.y > 0 && localPosition.y < WINDOW_HEIGHT)
                {
                    if (typeOfSprite == 0)
                        tiles[(localPosition.y - localPosition.y % 32) / 32][((localPosition.x - 160) - (localPosition.x - 160) % 32) / 32] = this->actualTexture;
                    if (typeOfSprite == 1)
                        items[(localPosition.y - localPosition.y % 32) / 32][((localPosition.x - 160) - (localPosition.x - 160) % 32) / 32] = this->actualTexture;
                    if (typeOfSprite == 2)
                        Entities[(localPosition.y - localPosition.y % 32) / 32][((localPosition.x - 160) - (localPosition.x - 160) % 32) / 32] = this->actualTexture;
                }


                //Test d'entrée dans le choix de tile ou d'items
                if (localPosition.x < 160 && localPosition.x > 0 && localPosition.y > 0 && localPosition.y < 64)
                {
                    inMenu = 1;
                    typeOfSprite = 0;
                }
                if (localPosition.x < 160 && localPosition.x > 0 && localPosition.y > 64 && localPosition.y < 128)
                {
                    inMenu = 1;
                    typeOfSprite = 2;
                }
                if (localPosition.x < 160 && localPosition.x > 0 && localPosition.y > WINDOW_HEIGHT - 64 && localPosition.y < WINDOW_HEIGHT)
                {
                    inMenu = 1;
                    typeOfSprite = 1;
                }
                

                while (inMenu == 1) {
                    this->window->clear();

                    while (this->window->pollEvent(this->event))
                    {


                        //Retour à l'écran du jeu lors de la fermeture de l'éditeur
                        if (this->event.type == sf::Event::Closed)
                        {
                            this->window->close();
                            Game game;
                        }


                        //Test de choix de la tile
                        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                        {
                            sf::Vector2i localPosition2 = sf::Mouse::getPosition(*window);
                            if (localPosition2.x > 160 && localPosition2.x < WINDOW_WIDTH + 160 && localPosition2.y > 0 && localPosition2.y < WINDOW_HEIGHT)
                            {
                                this->actualTexture = (((localPosition2.y - (localPosition2.y % 128)) / 128) * 5) + ((localPosition2.x - 160) - (localPosition2.x - 160) % 128) / 128;
                                inMenu = 0;
                            }
                        }
                    }


                    //Dessin du menu de choix de tile
                    sprites[typeOfSprite][actualTexture].setPosition(160 / 2 - 16, WINDOW_HEIGHT / 2 - 16);
                    this->window->draw(sprites[typeOfSprite][actualTexture]);

                    window->draw(text);

                    int i;
                    if (typeOfSprite == 0)
                        i = nbTiles;
                    else if (typeOfSprite == 1)
                        i = nbItems;
                    else if (typeOfSprite == 2)
                        i = nbEntities;
                    
                    for (int j = 0; j < i; j++) {
                        /*if (textures[typeOfSprite][j].getSize().x != 32 || textures[typeOfSprite][j].getSize().y != 32)
                            sprites[typeOfSprite][j].setScale(32 / textures[typeOfSprite][j].getSize().x, 32 / textures[typeOfSprite][j].getSize().y);*/
                        sprites[typeOfSprite][j].setPosition(128 * ((j % 5) + 1) - 64 - 16 + 160, 128 * ((j - (j % 5)) / 5 + 1) - 64 - 16);
                        this->window->draw(sprites[typeOfSprite][j]);
                    }

                    this->window->display();
                }

                if (localPosition.x < WINDOW_WIDTH + 320 && localPosition.x > WINDOW_WIDTH + 160 && localPosition.y > 0 && localPosition.y < 64)
                {
                    if (actualMapY != 0)
                    {
                        if (map[actualMapY - 1][actualMapX] != 1)
                        {
                            map[actualMapY - 1][actualMapX] = 1;
                            this->Save();
                        }
                    }
                }
                if (localPosition.x < WINDOW_WIDTH + 320 && localPosition.x > WINDOW_WIDTH + 160 && localPosition.y > 64 && localPosition.y < 128)
                {
                    if (actualMapY != WINDOW_HEIGHT / 32 - 1)
                    {
                        if (map[actualMapY + 1][actualMapX] != 1)
                        {
                            map[actualMapY + 1][actualMapX] = 1;
                            this->Save();
                        }
                    }
                }
                if (localPosition.x < WINDOW_WIDTH + 320 && localPosition.x > WINDOW_WIDTH + 160 && localPosition.y > 128 && localPosition.y < 192)
                {
                    if (actualMapX != WINDOW_WIDTH / 32 - 1)
                    {
                        if (map[actualMapY][actualMapX + 1] != 1)
                        {
                            map[actualMapY][actualMapX + 1] = 1;
                            this->Save();
                        }
                    }
                }
                if (localPosition.x < WINDOW_WIDTH + 320 && localPosition.x > WINDOW_WIDTH + 160 && localPosition.y > 192 && localPosition.y < 256)
                {
                    if (actualMapX != 0)
                    {
                        if (map[actualMapY][actualMapX - 1] != 1)
                        {
                            map[actualMapY][actualMapX - 1] = 1;
                            this->Save();
                        }
                    }
                }
            }


            //Test de suppression de la tile
            if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
            {

                sf::Vector2i localPosition = sf::Mouse::getPosition(*window);
                if (localPosition.x > 160 && localPosition.x < WINDOW_WIDTH + 160 && localPosition.y > 0 && localPosition.y < WINDOW_HEIGHT)
                {
                    tiles[(localPosition.y - localPosition.y % 32) / 32][((localPosition.x - 160) - (localPosition.x - 160) % 32) / 32] = 0;
                    items[(localPosition.y - localPosition.y % 32) / 32][((localPosition.x - 160) - (localPosition.x - 160) % 32) / 32] = 0;
                    Entities[(localPosition.y - localPosition.y % 32) / 32][((localPosition.x - 160) - (localPosition.x - 160) % 32) / 32] = 0;
                }
            }
        }


        //Dessine la tile actuelle
        sprites[typeOfSprite][actualTexture].setPosition(160 / 2 - 16, WINDOW_HEIGHT / 2 - 16);
        this->window->draw(sprites[typeOfSprite][actualTexture]);

        window->draw(text);
        window->draw(textTiles);
        window->draw(textItems);
        window->draw(textEntities);
        window->draw(textAddAbove);
        window->draw(textAddBelow);
        window->draw(textAddRight);
        window->draw(textAddLeft);
        window->draw(textActualMap);


        //Dessine la map
        for (int r = 0; r < WINDOW_HEIGHT / 32; r++)
        {
            for (int n = 0; n < WINDOW_WIDTH / 32; n++)
            {
                sprites[0][tiles[r][n]].setPosition(n * 32 + 160, r * 32);
                this->window->draw(sprites[0][tiles[r][n]]);
                sprites[1][items[r][n]].setPosition(n * 32 + 160, r * 32);
                this->window->draw(sprites[1][items[r][n]]);
                sprites[2][Entities[r][n]].setPosition(n * 32 + 160, r * 32);
                this->window->draw(sprites[2][Entities[r][n]]);
            }
        }
        this->window->display();
    }
}


//Sauvegarde de la map et les items lorsqu'on quitte l'éditeur
void MapEditor::Save()
{
    fstream newfile;
    newfile.open("map/map.txt", ios::out);
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


    newfile.open("map/tiles/tiles" + to_string(actualMapX + actualMapY * (WINDOW_WIDTH / 32)) + ".txt", ios::out);
    if (newfile.is_open()) 
    {
        for (int i = 0; i < WINDOW_HEIGHT / 32; i++)
        {
            for (int j = 0; j < WINDOW_WIDTH / 32; j++)
            {
                newfile << tiles[i][j];
            }
            newfile << "\n";
        }
        newfile.close();
    }


    newfile.open("map/items/items" + to_string(actualMapX + actualMapY * (WINDOW_WIDTH / 32)) + ".txt", ios::out);
    if (newfile.is_open())
    {
        for (int i = 0; i < WINDOW_HEIGHT / 32; i++)
        {
            for (int j = 0; j < WINDOW_WIDTH / 32; j++)
            {
                newfile << items[i][j];
            }
            newfile << "\n";
        }
        newfile.close();
    }

    newfile.open("map/entities/Entities" + to_string(actualMapX + actualMapY * (WINDOW_WIDTH / 32)) + ".txt", ios::out);
    if (newfile.is_open())
    {
        for (int i = 0; i < WINDOW_HEIGHT / 32; i++)
        {
            for (int j = 0; j < WINDOW_WIDTH / 32; j++)
            {
                newfile << Entities[i][j];
            }
            newfile << "\n";
        }
        newfile.close();
    }
}
