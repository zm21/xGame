#include "Hero.h"
#include "Windows.h"
#include "Map.h"
#include "Menu.h"

void meenu(RenderWindow & window) {
	Texture play_button_texture, about_game_button, exit_game_button_texture, menuBackground;
	play_button_texture.loadFromFile("images/playbutton.png");
	about_game_button.loadFromFile("images/aboutgameButton.png");
	exit_game_button_texture.loadFromFile("images/buttonexit.png");
	menuBackground.loadFromFile("images/Menubackground.jpg");
	Sprite  menu2(play_button_texture), menu3(about_game_button), about(exit_game_button_texture), menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;
	menu2.setPosition(347, 220);
	menu3.setPosition(248, 340);
	about.setPosition(347, 464);
	menuBg.setPosition(0, 0);
	Event event;

	while (isMenu)
	{
		menu2.setColor(Color::White);
		menu3.setColor(Color::White);
		about.setColor(Color::White);
		menuNum = 0;
		window.clear(Color(0, 0, 0));

		if (IntRect(347, 220, 110, 40).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Blue); menuNum = 2; }
		if (IntRect(248, 340, 288, 38).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Blue); menuNum = 3; }
		if (IntRect(347, 464, 108, 28).contains(Mouse::getPosition(window))) { about.setColor(Color::Blue); menuNum = 3; }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			
			if (menuNum == 1) isMenu = false;
			if (menuNum == 2) { window.draw(about); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); }
			if (menuNum == 3) { window.close(); isMenu = false; }

		}
		window.draw(menuBg);
		window.draw(menu2);
		window.draw(menu3);
		window.draw(about);
		window.display();
		while (window.pollEvent(event)&& isMenu)
		{

			if (event.type == Event::Closed)
				window.close();
		}
	}
}


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "xGame");
	
	//window.setFramerateLimit(60);
	//menu(window);
	Menu menu("playbutton.png", 347, 220, 110, 40,
		"aboutgameButton.png", 248, 340, 288, 38,
		"buttonexit.png", 347, 464, 108, 28,
		"Menubackground.jpg", "aboutgame_screen.jpg");
	menu.ShowMenu(window);

	Hero hero("hero.png", 20, 50, 0, 0, 37, 44);
	Image map_image;
	map_image.loadFromFile("images/map.png");
	Texture map_texture;
	map_texture.loadFromImage(map_image);
	Sprite map_sprite;
	map_sprite.setTexture(map_texture);


	Texture start;
	start.loadFromFile("images/Start.png");
	Sprite s_start(start);
	s_start.setPosition(0, 0);
	Clock clock;

	Font font;
	font.loadFromFile("Fonts/BK0010.ttf");
	Text info("", font, 64);
	info.setFillColor(Color::Blue);
	info.setString("The game is in development...");

	float CurrentFrame{};
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds(); //get the elapsed time in micro seconds
		clock.restart();
		time = time / 1000; //game speed

		Event event;

		while (window.pollEvent(event))
		{

			if (event.type == Event::Closed)
				window.close();
		}
		info.setPosition(20, 50);

		

		window.setView(hero.GetView());
		window.clear();
		window.draw(hero.GetSprite());
		hero.Move(time);
		
		hero.update(time);

		
		for (int i = 0; i < HEIGHT_MAP; ++i)
		{
			for (int j = 0; j < WIDTH_MAP; ++j)
			{
				if (TileMap[i][j] == ' ')
				{
					map_sprite.setTextureRect(IntRect(0, 0, 32, 32));
				}
				else if (TileMap[i][j] == '0')
				{
					map_sprite.setTextureRect(IntRect(64, 0, 32, 32));
				}
				else if (TileMap[i][j] == 's')
				{
					map_sprite.setTextureRect(IntRect(32, 0, 32, 32));
				}
				map_sprite.setPosition(j * 32, i * 32);
				window.draw(map_sprite);
			}
		}
		window.draw(s_start);
		window.draw(info);
		window.draw(hero.GetSprite());
		window.display();

	}


	return 0;

}