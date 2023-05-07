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

void PauseMenu::Init()
{
	//Choice = LevelChoice;
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

	if (Choice < 0) {
		Choice = 2;
	}
	if (Choice > 2) {
		Choice = 0;
	}
}

void PauseMenu::SetControl()
{
	//set controls 
	//if (SetKey == 0 || SetKey > 2) {
	//	Init(0);
	//}	
	//if (SetKey == 1) {
	//	Init(1);
	//}	
	//if (SetKey == 2 || SetKey < 0) {
	//	Init(2);
	//}

	//switch (SetKey) {
	//	case 1:
	//		Init(0);
	//	case 2:
	//		Init(1);
	//	case 3:
	//		Init(2);
	//}

	//if variable is out of the limit

}

void PauseMenu::Loop(sf::RenderWindow* window, sf::Event& event)
{
	// PROBLEM reste tout le temps sur le bouton quitter ne veut pas aller sur les autres alors que la variable change
	while (window->pollEvent(event)) {

		if (event.type == sf::Event::KeyPressed) {

			if (event.type == sf::Event::Closed) {
				window->close();
			}

			if (event.key.code == sf::Keyboard::Up) {
				Choice--;
				//SetControl();
				Init();
				cout << Choice << endl;
			}
			if (event.key.code == sf::Keyboard::Down) {
				Choice++;
				//SetControl();
				Init();
				cout << Choice << endl;
			}

			if (event.key.code == sf::Keyboard::Enter) {
				if (Choice == 0) {
					IsRunning = true;
					//break;
					//this->window->clear();
				}
				if (Choice == 1) {
					//Open option menu
				}
				if (Choice == 2) {
					window->close();
				}
			}

			if (event.key.code == sf::Keyboard::Escape)
				IsRunning = true;

		}
	}
}
