#include "General.h"

class PauseMenu {
public: 

	PauseMenu();
	~PauseMenu();

	void Draw(sf::RenderWindow* window);
	void Init();
	void SetControl();
	void Loop(sf::RenderWindow* window, sf::Event& event);

	int Choice = 0;
	int SetKey = 0;
	bool IsRunning = false;

protected :
	sf::Font font;
	sf::Text resume, option, quit;
};