#include "General.h"

class PauseMenu {
public: 

	PauseMenu();
	~PauseMenu();

	void Draw(sf::RenderWindow* window);
	void Init(int LevelChoice);
	void SetControl();

	int Choice = 0;
	int SetKey = 1;

protected :
	sf::Font font;
	sf::Text resume, option, quit;
};