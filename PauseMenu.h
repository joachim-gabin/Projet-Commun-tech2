#include "General.h"

class PauseMenu {
public:

	PauseMenu();
	~PauseMenu();

	void SetFont();
	void SetBackground();
	int SetSound();
	void Draw(sf::RenderWindow* window);
	void Interact();
	void Loop(sf::RenderWindow* window, sf::Event& event);

	int Choice = 0;
	int SetKey = 0;
	bool IsRunning = false;
	bool IsDead = false;

protected:
	sf::Font font;
	sf::Text resume, option, quit, retry;
	sf::Color ColorFont;

	sf::Texture NamePauseTextureBackground;
	sf::Sprite NamePauseSpriteBackground;

};