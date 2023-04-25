#include "General.h"
#include "Game.h"
#include "MainMenu.h"
#include <SFML/Graphics.hpp>


int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 640), "Main Menu", Style::Default);
    MainMenu mainMenu;

    bool start = false;
    bool battle = false;

    while (window.isOpen())
    {
        window.clear();
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
            if (event.type == Event::KeyReleased)
            {
                if (event.key.code == Keyboard::Up)
                {
                    mainMenu.MoveUp();
                    break;
                }

                if (event.key.code == Keyboard::Down)
                {
                    mainMenu.MoveDown();
                    break;
                }

                if (event.key.code == Keyboard::Return)
                {



                    int x = mainMenu.MainMenuPressed();
                    if (x == 0)
                    {
                        window.close();
                        Game game;
                    }

                    if (x == 1)
                    {
                        //RenderWindow Options(VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "Options");
                        //while (Options.isOpen())
                        //{
                        //    Event event;
                        //    while (Options.pollEvent(event))
                        //    {
                        //        Event event;
                        //        switch (event.type) {
                        //        case Event::Closed :                                    
                        //                Options.close();  
                        //                break;
                        //        case Event::KeyPressed :
                        //                if (event.key.code == Keyboard::Escape) {
                        //                    Options.close();
                        //                }
                        //        default :
                        //            break;
                        //        }
                        //        //Play.close();
                        //        Options.clear();
                        //        Options.display();
                        //    }
                        //}

                    }
                    if (x == 2)
                    {
                        window.close();
                        break;
                    }

                }
            }
        }

        window.draw(mainMenu.DrawBackground());
        mainMenu.draw(window);
        window.display();
    }
	return 0;
}