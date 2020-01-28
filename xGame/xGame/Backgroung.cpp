#include "Backgroung.h"

Backgroung::Backgroung(String file):file(file)
{
	texture.loadFromFile("images/" + file); //load image for texture
	sprite.setTexture(texture); 
	sprite.setPosition(0, 0); 
}