#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf; 
class GameObject
{
protected:
	float x; // position X of the game object
	float y; // position Y of the game object
	float xSprite, ySprite, height, width; //start points of the rectangle, its width and height
	String file; //file name
	Image image; //sfml image file
	Texture texture; //sfml texture 
	Sprite sprite; //sfml sprite
public:
	GameObject(String file, float x, float y, float xSprite, float ySprite, float h, float w);
	virtual void Draw() { cout << "Class GameObject draw"<<endl; };
	void SetXSprite(float xSprite) { this->xSprite = xSprite; }
	void SetYSprite(float ySprite) { this->ySprite = ySprite; }
	void SetHeight(float height) { this->height = height; }
	void SetWidth(float width) { this->ySprite = width; }
};

