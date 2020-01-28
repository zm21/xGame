#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class Backgroung
{
	String file; //file name
	Texture texture; //sfml texture 
	Sprite sprite; //sfml sprite
public:
	Backgroung(String file);
	Sprite GetSprite() { return sprite; }
};

