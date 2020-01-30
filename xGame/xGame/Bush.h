#pragma once
#include "GameObject.h"
class Bush 
{
public:
	enum Stage
	{
		dark_green, green, yellowed, dry
	};
private:
	Stage stage;
	float x; // position X of the game object
	float y; // position Y of the game object
	float xSprite, ySprite, height, width; //start points of the rectangle, its width and height
	String file; //file name
	Image image; //sfml image file
	Texture texture; //sfml texture 
	Sprite sprite; //sfml sprite
public:
	Bush();
	Bush(String file, float x, float y);
	Sprite GetSprite() { return sprite; }
	void SetX(float x) { this->x = x; }
	void SetY(float y) { this->y = y; }
	float GetX() { return x; }
	float GetY() { return y; }
};

