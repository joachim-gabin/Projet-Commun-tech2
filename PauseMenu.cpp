#include "PauseMenu.h"

PauseMenu::PauseMenu()
{
	if (!font.loadFromFile("font/HardGrunge.ttf")) {
		std::cout << "error";
	}

	resume.setFont(font);
	resume.setFillColor(sf::Color::Blue);
	resume.setString("Resume");
	resume.setCharacterSize(70);
	resume.setPosition(205, 120);

	option.setFont(font);
	option.setFillColor(sf::Color::White);
	option.setString("Option");
	option.setCharacterSize(70);
	option.setPosition(205, 220);

	quit.setFont(font);
	quit.setFillColor(sf::Color::White);
	quit.setString("Quit");
	quit.setCharacterSize(70);
	quit.setPosition(205, 320);
}

PauseMenu::~PauseMenu()
{
}

void PauseMenu::Draw(sf::RenderWindow* window) {

	window->draw(resume);
	window->draw(option);
	window->draw(quit);
}

void PauseMenu::Init(int LevelChoice)
{
	Choice = LevelChoice;
	switch (Choice) {
	case 0:  //Resume choice
		resume.setFillColor(sf::Color::Blue);
		option.setFillColor(sf::Color::White);
		quit.setFillColor(sf::Color::White);
	case 1: //Option choice
		resume.setFillColor(sf::Color::White);
		option.setFillColor(sf::Color::Blue);
		quit.setFillColor(sf::Color::White);
	case 2: //Quit choice
		resume.setFillColor(sf::Color::White);
		option.setFillColor(sf::Color::White);
		quit.setFillColor(sf::Color::Blue);
	}
}

void PauseMenu::SetControl()
{
	//set controls 
	if (SetKey == 1) {
		Init(0);
	}	
	if (SetKey == 2) {
		Init(1);
	}	
	if (SetKey == 3) {
		Init(2);
	}

	//switch (SetKey) {
	//	case 1:
	//		Init(0);
	//	case 2:
	//		Init(1);
	//	case 3:
	//		Init(2);
	//}

	//if variable is out of the limit
	if (SetKey < 1) {
		SetKey = 3;
	}
	else if (SetKey > 3) {
		SetKey = 1;
	}
}
