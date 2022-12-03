#include "Game.h"

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
    while (this->window->isOpen())
    {
        window->clear();

        while (this->window->pollEvent(this->event))
        {
            if (this->event.type == sf::Event::Closed)
                this->window->close();

            if (this->event.type == sf::Event::KeyPressed) {
                if (this->event.key.code == sf::Keyboard::Escape) {
                    this->window->close();
                }
            }

            if (this->event.type == sf::Event::KeyPressed) {
                if (this->event.key.code == sf::Keyboard::A) {
                    end = true;
                    while (end == true)
                    {
                        this->window->clear();
                        this->window->display();
                    }
                }
            }
        }
        this->window->clear();

        this->window->display();

    }
}
