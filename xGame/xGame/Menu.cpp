#include "Menu.h"
Menu::Menu(String file_p, float xSprite_p, float ySprite_p, float height_p, float width_p, String file_a, float xSprite_a, float ySprite_a, float height_a, float width_a,
	String file_e, float xSprite_e, float ySprite_e, float height_e, float width_e,
	String file_bg_m, String file_bg_ab)
	:
	play(file_p, xSprite_p, ySprite_p, height_p, width_p), //ctor of button play
	about_game(file_a, xSprite_a, ySprite_a, height_a, width_a), //ctor of button  about of game
	exit_game(file_e, xSprite_e, ySprite_e, height_e, width_e), //ctor of button exit of game
	menu(file_bg_m), ab_info(file_bg_ab), open(false) {} //ctor's of background

void Menu::ShowMenu(RenderWindow & window)
{
	int action{};
	open = true; //status of menu
	while (window.isOpen() && open)
	{
		play.GetSprite().setColor(Color::White); //turn the normal color of the button (the state of the button not pressed)
		about_game.GetSprite().setColor(Color::White); //turn the normal color of the button (the state of the button not pressed)
		exit_game.GetSprite().setColor(Color::White); //turn the normal color of the button (the state of the button not pressed)
		action = not_selected; //resetting the action to not selected
		window.clear();

		//check whether the mouse position matches the position of one of the buttons. if so, set a new color for the button (imitate the cursor hovering over the button) and set the selected action
		if (IntRect(play.GetxSprite(), play.GetySprite(), play.GetHeight(), play.GetWidth()).contains(Mouse::getPosition(window))) { play.GetSprite().setColor(Color::Blue); action = play_act; }
		if (IntRect(about_game.GetxSprite(), about_game.GetySprite(), about_game.GetHeight(), about_game.GetWidth()).contains(Mouse::getPosition(window))) { about_game.GetSprite().setColor(Color::Blue); action = about_game_act; }
		if (IntRect(exit_game.GetxSprite(), exit_game.GetySprite(), exit_game.GetHeight(), exit_game.GetWidth()).contains(Mouse::getPosition(window))) { exit_game.GetSprite().setColor(Color::Blue); action = exit_game_act; }

		//if the left mouse button is pressed we check the selected action
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			switch (action)
			{
			case play_act:
				open = false;
				break;
			case about_game_act:
				window.draw(ab_info.GetSprite());
				window.display();
				while (!Keyboard::isKeyPressed(Keyboard::Escape));
				break;
			case exit_game_act:
				window.close();
				open = false;
				break;
			default:
				break;
			}

		}
		window.draw(menu.GetSprite());
		window.draw(play.GetSprite());
		window.draw(about_game.GetSprite());
		window.draw(exit_game.GetSprite());
		window.display();

		Event event;

		while (window.pollEvent(event))
		{

			if (event.type == Event::Closed)
				window.close();
		}
	}
}