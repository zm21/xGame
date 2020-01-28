#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class Button
{
	Texture texture; //button texture
	String file; //file name 
	Sprite sprite; //button sprite
	float xSprite, ySprite, height, width; //start points of the rectangle, its width and height
public:
	Button(String file, float xSprite, float ySprite, float height, float width);
	Sprite& GetSprite() { return sprite; } //get button sprite
	float GetxSprite() { return xSprite; } //get x poss 
	float GetySprite() { return ySprite; } //get y poss
	float GetHeight() { return height; } //get height of button
	float GetWidth() { return width; } //get width of button
};

