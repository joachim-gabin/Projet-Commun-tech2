#include "DeathMenu.h"

DeathMenu::DeathMenu()
{
	
}

DeathMenu::~DeathMenu()
{

}

void DeathMenu::SetFont()
{
	if (!font.loadFromFile("font/HardGrunge.ttf"))
	{
		std::cout << "error";
	}
	ColorFont = { 109, 7, 26 };

	retry.setFont(font);
	retry.setFillColor(ColorFont);
	retry.setString("Retry");
	retry.setCharacterSize(70);
	retry.setPosition(205, 120);

	quit.setFont(font);
	quit.setFillColor(sf::Color::White);
	quit.setString("Quit");
	quit.setCharacterSize(70);
	quit.setPosition(205, 220);
}

void DeathMenu::SetBackground()
{

}