#pragma once
#include "General.h"

class DeathMenu
{
public :
	DeathMenu();
	~DeathMenu();

	void SetFont();
	void SetBackground();
	void Draw(sf::RenderWindow* window);
	void Interact();
	void Loop(sf::RenderWindow* window, sf::Event& event);

	int Choice = 0;
	int SetKey = 0;
	bool IsRunning = false;

protected:
	sf::Font font;
	sf::Text retry, quit;
	sf::Color ColorFont;
	sf::Texture NameDeathTextureBackground;
	sf::Sprite NameDeathSpriteBackground;

};
