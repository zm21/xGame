#include "Backgroung.h"

Backgroung::Backgroung(String file):file(file)
{
	texture.loadFromFile("images/" + file);
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);
}