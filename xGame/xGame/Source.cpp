#include "Hero.h"
#include "Windows.h"
#include "Map.h"
#include "Menu.h"

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