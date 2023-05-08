#include "General.h"
using namespace sf;

#define Max_main_menu 3

class MainMenu
{
public:
	MainMenu();

	sf::Sprite DrawBackground();
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
	string NameBackground;

	Color color;
	Texture NameMenuTextureBackground;
	Sprite NameMenuSpriteBackground;
};