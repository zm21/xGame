#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

enum Direction
{
	right_dir, left_dir, down_dir, up_dir
};

class Units
{
protected:
	float x, y;//coordinates
	float dx, dy, speed;//direction and speed
	float xSprite, ySprite, height, width; //start points of the rectangle, its width and height
	int dir; //the direction of movement
	String file; //file name
	Image image; //sfml image file
	Texture texture; //sfml texture 
	Sprite sprite; //sfml sprite
public:
	Units(String file, float x, float y, float xSprite, float ySprite, float h, float w);
	//virtual ~Units() = 0;
	virtual void update(float time)
	{
		cout << "This update from class Units" << endl;
	}
	float GetCoordinateX() { return x; } //Get X position of unit
	float GetCoordinateY() { return y; } //Get Y position of unit
};
