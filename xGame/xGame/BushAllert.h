#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;
using namespace sf;
class BushAllert
{
public:
	enum MathAction
	{
		sum, rizn
	};
private:
	float x,  y;
	Texture texture; //button texture
	String file; //file name 
	Sprite sprite; //button sprite
	float xSprite, ySprite;//start points of the rectangle
	Font font;
	Text task;
	string task_str;
	MathAction act;
	int answer;
public:
	BushAllert() {}
	BushAllert(String file, float xSprite, float ySprite);
	void SetX(float x) { this->x = x; }
	void SetY(float y) { this->y = y; }
	void ReTask();
	void SetPos() { sprite.setPosition(sf::Vector2f(800 / 2.0f, 600 / 2.0f)); }
	bool Task(RenderWindow &window, Event &event);
};

