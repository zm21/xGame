#include "Button.h"

Button::Button(String file, float xSprite, float ySprite ,float height, float width): height(height), width(width), xSprite(xSprite), ySprite(ySprite)
{
	texture.loadFromFile("images/" + file); //load image of button for texture
	sprite.setTexture(texture);
	sprite.setPosition(xSprite, ySprite);
}