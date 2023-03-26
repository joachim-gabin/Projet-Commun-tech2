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


    //Dessine la map par rapport au fichier map.txt
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


    //Dessine les items par rapport au fichier items.txt
    newfile;
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
                map[x][y] = (int)c - 48;
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

    //Load la font et le texte
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


    //Initialise les array de texture et de sprite des tiles
    sf::Sprite sprites[4];
    sf::Texture textures[4];


    //Load les textures et les sprites du dossier tiles
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

    //Initialise les array de texture et de sprite des items
    sf::Sprite sprites_items[4];
    sf::Texture textures_items[4];


    //Load les textures et les sprites du dossier items
    i = 0;
    for (const auto& dirEntry : recursive_directory_iterator("texture/tiles/"))
    {
        std::cout << dirEntry.path().string() << std::endl;
        sf::Texture texture;
        textures_items[i] = texture;
        if (!textures_items[i].loadFromFile(dirEntry.path().string()))
        {
            std::cout << "erreur d'image" << std::endl;
        }
        sf::Sprite sprite;
        sprites_items[i] = sprite;
        sprites_items[i].setTexture(textures[i]);
        i++;
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
                    map[(localPosition.y - localPosition.y % 32) / 32][((localPosition.x - 160) - (localPosition.x - 160) % 32) / 32] = this->actualTexture;
                }


                //Test d'entrée dans le choix de tile
                if (localPosition.x < 160 && localPosition.x > 0 && localPosition.y > 0 && localPosition.y < WINDOW_HEIGHT)
                {
                    int inMenu = 1;
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
                                    cout << this->actualTexture;
                                    inMenu = 0;
                                }
                            }
                        }


                        //Dessin du menu de choix de tile
                        sprites[actualTexture].setPosition(160 / 2 - 16, WINDOW_HEIGHT / 2 - 16);
                        this->window->draw(sprites[actualTexture]);

                        window->draw(text);

                        for (int i = 0; i < 3; i++) {
                            sprites[i].setPosition(128 * (i + 1) - 64 - 16 + 160, 128 * 1 - 64 - 16);
                            this->window->draw(sprites[i]);
                        }

                        this->window->display();
                    }
                }
            }


            //Test de suppression de la tile
            if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
            {

                sf::Vector2i localPosition = sf::Mouse::getPosition(*window);
                if (localPosition.x > 160 && localPosition.x < WINDOW_WIDTH + 160 && localPosition.y > 0 && localPosition.y < WINDOW_HEIGHT)
                {
                    map[(localPosition.y - localPosition.y % 32) / 32][((localPosition.x - 160) - (localPosition.x - 160) % 32) / 32] = 0;
                }
            }
        }


        //Dessine la tile actuelle
        sprites[actualTexture].setPosition(160 / 2 - 16, WINDOW_HEIGHT / 2 - 16);
        this->window->draw(sprites[actualTexture]);

        window->draw(text);


        //Dessine la map
        for (int r = 0; r < WINDOW_HEIGHT / 32; r++)
        {
            for (int n = 0; n < WINDOW_WIDTH / 32; n++)
            {
                sprites[map[r][n]].setPosition(n * 32 + 160, r * 32);
                this->window->draw(sprites[map[r][n]]);
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


    newfile;
    newfile.open("items.txt", ios::out);
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
