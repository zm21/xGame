#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Bush.h"
#include <algorithm>
#include <string>


using namespace sf;
class Map 
{
public:
	enum Content
	{
		empty_=' ', bush_='b'
	};
private:
	std::vector<string> tile_map;
	std::vector<Bush> bushes;
	String file_bush;
	int count;
	int size;
public:
	Map(String file_bush);
	void InitMap();
	void InitBushes();
	void DrawBushes(RenderWindow &window);
	void CheckCollisionWithoObject(float hero_tempX, float hero_tempY, float & hero_x, float & hero_y, float dx, float dy);
	bool CheckHeroOnBush(float x, float y);
};

