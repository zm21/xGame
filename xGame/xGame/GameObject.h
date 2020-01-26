#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf; 
class GameObject
{
protected:
	float x;
	float y;
	float xSprite, ySprite, height, width; //start points of the rectangle, its width and height
	String file; //file name
	Image image; //sfml image file
	Texture texture; //sfml texture 
	Sprite sprite; //sfml sprite
public:
	GameObject(String file, float x, float y, float xSprite, float ySprite, float h, float w);
	//virtual ~GameObject()=0;
};

