#include "Hero.h"
#include "Windows.h"
#include "Map.h"
#include "Menu.h"
#include "Play.h"

int main()
{
	srand(time(0));
	sf::RenderWindow window(sf::VideoMode(800, 600), "Berry collector");
	

	Menu menu("playbutton.png", 347, 220, 110, 40,
		"aboutgameButton.png", 248, 340, 288, 38,
		"buttonexit.png", 347, 464, 108, 28,
		"Menubackground.jpg", "aboutgame_screen.jpg");
	menu.ShowMenu(window);

	while (window.isOpen())
	{

		Play(window);

		Event event;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == sf::Event::TextEntered)
			{	
			}
		}
	}

	return 0;

}