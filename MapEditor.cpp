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
	this->window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH + 160, WINDOW_HEIGHT), "Last Man Editor");


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


            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {


                //Récupère la position de la souris et change la tile
                sf::Vector2i localPosition = sf::Mouse::getPosition(*window);
                if (localPosition.x > 160 && localPosition.x < WINDOW_WIDTH + 160 && localPosition.y > 0 && localPosition.y < WINDOW_HEIGHT)
                {
                    if (typeOfSprite == 0)
                        map[(localPosition.y - localPosition.y % 32) / 32][((localPosition.x - 160) - (localPosition.x - 160) % 32) / 32] = this->actualTexture;
                    if (typeOfSprite == 1)
                        items[(localPosition.y - localPosition.y % 32) / 32][((localPosition.x - 160) - (localPosition.x - 160) % 32) / 32] = this->actualTexture;
                }


                //Test d'entrée dans le choix de tile ou d'items
                if (localPosition.x < 160 && localPosition.x > 0 && localPosition.y > 0 && localPosition.y < 64)
                {
                    inMenu = 1;
                    typeOfSprite = 0;
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
                    
                    for (int j = 0; j < i; j++) {
                        if (textures[typeOfSprite][j].getSize().x != 32 || textures[typeOfSprite][j].getSize().y != 32)
                            sprites[typeOfSprite][j].setScale(32 / textures[typeOfSprite][j].getSize().x, 32 / textures[typeOfSprite][j].getSize().y);
                        sprites[typeOfSprite][j].setPosition(128 * ((j % 5) + 1) - 64 - 16 + 160, 128 * ((j - (j % 5)) / 5 + 1) - 64 - 16);
                        this->window->draw(sprites[typeOfSprite][j]);
                    }

                    this->window->display();
                }
            }


            //Test de suppression de la tile
            if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
            {

                sf::Vector2i localPosition = sf::Mouse::getPosition(*window);
                if (localPosition.x > 160 && localPosition.x < WINDOW_WIDTH + 160 && localPosition.y > 0 && localPosition.y < WINDOW_HEIGHT)
                {
                    map[(localPosition.y - localPosition.y % 32) / 32][((localPosition.x - 160) - (localPosition.x - 160) % 32) / 32] = 0;
                    items[(localPosition.y - localPosition.y % 32) / 32][((localPosition.x - 160) - (localPosition.x - 160) % 32) / 32] = 0;
                }
            }
        }


        //Dessine la tile actuelle
        sprites[typeOfSprite][actualTexture].setPosition(160 / 2 - 16, WINDOW_HEIGHT / 2 - 16);
        this->window->draw(sprites[typeOfSprite][actualTexture]);

        window->draw(text);
        window->draw(textTiles);
        window->draw(textItems);


        //Dessine la map
        for (int r = 0; r < WINDOW_HEIGHT / 32; r++)
        {
            for (int n = 0; n < WINDOW_WIDTH / 32; n++)
            {
                sprites[0][map[r][n]].setPosition(n * 32 + 160, r * 32);
                this->window->draw(sprites[0][map[r][n]]);
                sprites[1][items[r][n]].setPosition(n * 32 + 160, r * 32);
                this->window->draw(sprites[1][items[r][n]]);
            }
        }
        this->window->display();
    }
}


//Sauvegarde de la map et les items lorsqu'on quitte l'éditeur
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


    newfile.open("items.txt", ios::out);
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
}
