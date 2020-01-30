#include "Hero.h"
#include "Windows.h"
#include "Map.h"
#include "Menu.h"
#include "Play.h"

int main()
{
	srand(time(0));
	sf::RenderWindow window(sf::VideoMode(800, 600), "Berry collector");
	
	//window.setFramerateLimit(60);
	//menu(window);
	Menu menu("playbutton.png", 347, 220, 110, 40,
		"aboutgameButton.png", 248, 340, 288, 38,
		"buttonexit.png", 347, 464, 108, 28,
		"Menubackground.jpg", "aboutgame_screen.jpg");
	menu.ShowMenu(window);

	/*Hero hero("hero.png", 512, 512, 0, 0, 37, 44);
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

	Backgroung map_bg("mapbg.jpg");

	Map test_map("bushs.png");

	float CurrentFrame{};
	Music mus;
	mus.openFromFile("audio/GameMusic.ogg");
	mus.play();
	mus.setLoop(true);

	std::string s;*/

	while (window.isOpen())
	{
		//float time = clock.getElapsedTime().asMicroseconds(); //get the elapsed time in micro seconds
		//clock.restart();
		//time = time / 1000; //game speed

		Play(window);

		Event event;

		while (window.pollEvent(event))
		{

			if (event.type == Event::Closed)
				window.close();
			if (event.type == sf::Event::TextEntered)
			{
					/*if (event.KeyPressed == sf::Keyboard::BackSpace && s.size() != 0) {
						s.pop_back();
						std::cout << s << std::endl;
					}
					else if (event.text.unicode < 128) {
						s.push_back((char)event.text.unicode);
						std::cout << s << std::endl;
					}*/
			}
		}
	//	info.setPosition(20, 50);
		
		

		/*window.setView(hero.GetView());
	    window.clear();
		window.draw(hero.GetSprite());
		hero.Move(time);
		test_map.DrawBushes(window);
		hero.update(time);
		window.draw(map_bg.GetSprite());*/
		/*for (int i = 0; i < HEIGHT_MAP; ++i)
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
		}*/


		/*test_map.DrawBushes(window);
		window.draw(s_start);
		window.draw(info);
		window.draw(hero.GetSprite());
		window.display();*/

	menu.ShowMenu(window);
	}

	return 0;

}