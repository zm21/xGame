#include "Play.h"

void Play(RenderWindow &window)
{
	Hero hero("hero.png", 512, 512, 0, 0, 37, 44);
	Image map_image;
	map_image.loadFromFile("images/map.png");
	Texture map_texture;
	map_texture.loadFromImage(map_image);
	Sprite map_sprite;
	map_sprite.setTexture(map_texture);

	Backgroung map_bg("mapbg.jpg");
	Map game_map("bushs.png");

	Music game_music;
	game_music.openFromFile("audio/GameMusic.ogg");
	game_music.play();
	game_music.setLoop(true);

	Clock clock;
	BushAllert allert("allert.jpg", 512, 512);
	allert.SetX(0);
	allert.SetY(0);
	Event event;
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



		window.setView(hero.GetView());
		window.clear();
		window.draw(hero.GetSprite());
		hero.Move(time);
		game_map.DrawBushes(window);
		hero.update(time, allert);
		window.draw(map_bg.GetSprite());

		game_map.DrawBushes(window);
		window.draw(hero.GetSprite());

		if (game_map.CheckHeroOnBush(hero.GetCoordinateX(), hero.GetCoordinateY()))
		{
			hero.ResetView();
			allert.Task(window, event);
		}
		window.display();
	}
	window.clear();
	hero.ZeroView();
}
