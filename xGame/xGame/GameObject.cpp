#include "GameObject.h"

GameObject::GameObject(String file, float x, float y, float xSprite, float ySprite, float h, float w) : x(x), y(y), height(h), width(w), xSprite(xSprite), ySprite(ySprite)
{
	this->file = file;
	image.loadFromFile("images/" + this->file);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(this->xSprite, this->ySprite, height, width));
}


