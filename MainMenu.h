#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

#define Max_main_menu 3

class MainMenu
{
public:
	MainMenu();

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();

	int MainMenuPressed() {
		return MainMenuSelected;
	}
	~MainMenu();

private:

	int MainMenuSelected;
	Font font;
	Text mainMenu[Max_main_menu];

};