#include "PauseMenu.h"

PauseMenu::PauseMenu()
{
	SetFont();
	SetBackground();
}

PauseMenu::~PauseMenu()
{
}

void PauseMenu::SetFont()
{
	if (!font.loadFromFile("font/HardGrunge.ttf")) {
		std::cout << "error";
	}
	ColorFont = { 109, 7, 26 };

	resume.setFont(font);
	resume.setFillColor(ColorFont);
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

void PauseMenu::SetBackground()
{
	if (!NamePauseTextureBackground.loadFromFile("texture/Background/BackgroundPauseMenu.png"))
	{
		std::cout << "pas charger l'image" << std::endl;
	}

	NamePauseSpriteBackground.setTexture(NamePauseTextureBackground);
	NamePauseSpriteBackground.setPosition((WINDOW_WIDTH / 5) - (NamePauseSpriteBackground.getGlobalBounds().width / 2), (WINDOW_HEIGHT / 2) - (NamePauseSpriteBackground.getGlobalBounds().height / 2));

}

void PauseMenu::Draw(sf::RenderWindow* window) {

	window->draw(NamePauseSpriteBackground);
	window->draw(resume);
	window->draw(option);
	window->draw(quit);
	
}

void PauseMenu::Interact()
{
	if (Choice < 0) {
		Choice = 2;
	}
	if (Choice > 2) {
		Choice = 0;
	}
	//Choice = LevelChoice;
	switch (Choice) {
	case 0:  //Resume choice
		resume.setFillColor(ColorFont);
		option.setFillColor(sf::Color::White);
		quit.setFillColor(sf::Color::White);
		break;
	case 1: //Option choice
		resume.setFillColor(sf::Color::White);
		option.setFillColor(ColorFont);
		quit.setFillColor(sf::Color::White);
		break;
	case 2: //Quit choice
		resume.setFillColor(sf::Color::White);
		option.setFillColor(sf::Color::White);
		quit.setFillColor(ColorFont);
		break;
	}


}

void PauseMenu::Loop(sf::RenderWindow* window, sf::Event& event)
{
	// PROBLEM reste tout le temps sur le bouton quitter ne veut pas aller sur les autres alors que la variable change
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window->close();
		}

		if (event.type == sf::Event::KeyPressed) {

			if (event.key.code == sf::Keyboard::Up) {
				Choice--;
				//SetControl();
				Interact();
			}
			if (event.key.code == sf::Keyboard::Down) {
				Choice++;
				//SetControl();
				Interact();
			}

			if (event.key.code == sf::Keyboard::Enter) {
				if (Choice == 0) {
					IsRunning = true;
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


