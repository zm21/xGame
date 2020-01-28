#pragma once
#include "Button.h"
#include "Backgroung.h"
class Menu
{
	Button play;
	Button about_game;
	Button exit_game;
	Backgroung menu;
	Backgroung ab_info; //about game info screen
	bool open;
public:
	enum Action
	{
		not_selected=-1, exit_game_act, play_act, about_game_act
	};
	Menu(String file_p, float xSprite_p, float ySprite_p, float height_p, float width_p, String file_a, float xSprite_a, float ySprite_a, float height_a, float width_a,
		String file_e, float xSprite_e, float ySprite_e, float height_e, float width_e, 
		String file_bg_m, String file_bg_ab);
	void ShowMenu(RenderWindow & window);
};

