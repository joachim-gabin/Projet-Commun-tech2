#include "MainMenu.h"

MainMenu::MainMenu()
{
	if (!font.loadFromFile("font/HardGrunge.ttf")) {
		std::cout << "error";
	}
	//set color Font
	color = { 109, 7, 26 };
	//Play
	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(color);
	mainMenu[0].setString("Play");
	mainMenu[0].setCharacterSize(70);
	mainMenu[0].setPosition(205, 220);
	//Options
	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(Color::White);
	mainMenu[1].setString("Options");
	mainMenu[1].setCharacterSize(70);
	mainMenu[1].setPosition(205, 320);
	//Exit
	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(Color::White);
	mainMenu[2].setString("Exit");
	mainMenu[2].setCharacterSize(70);
	mainMenu[2].setPosition(205, 420);

	MainMenuSelected = 0;
}

sf::Sprite MainMenu::DrawBackground()
{
	if (!NameMenuTextureBackground.loadFromFile("texture/Background/BackgroundMenu.png"))
	{
		std::cout << "pas charger l'image" << std::endl;
	}

	NameMenuSpriteBackground.setTexture(NameMenuTextureBackground);
	NameMenuSpriteBackground.setPosition((WINDOW_WIDTH / 2) - (NameMenuSpriteBackground.getGlobalBounds().width / 2), (WINDOW_HEIGHT / 2) - (NameMenuSpriteBackground.getGlobalBounds().height / 2));

	return NameMenuSpriteBackground;
}

void MainMenu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < Max_main_menu; ++i) {
		window.draw(mainMenu[i]);
	}
}

void MainMenu::MoveUp()
{
	if (MainMenuSelected - 1 >= -1) {
		mainMenu[MainMenuSelected].setFillColor(Color::White);

		MainMenuSelected--;
		if (MainMenuSelected == -1) {
			MainMenuSelected = 2;
		}
		mainMenu[MainMenuSelected].setFillColor(color);
	}
}

void MainMenu::MoveDown()
{
	if (MainMenuSelected + 1 >= 0) {
		mainMenu[MainMenuSelected].setFillColor(Color::White);

		MainMenuSelected++;
		if (MainMenuSelected == 3) {
			MainMenuSelected = 0;
		}
		mainMenu[MainMenuSelected].setFillColor(color);
	}
}

MainMenu::~MainMenu()
{

}