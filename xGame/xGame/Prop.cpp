#include "Prop.h"



Prop::Prop(String file, float x, float y, float xSprite, float ySprite, float h, float w):GameObject(file, x, y, xSprite, ySprite, h, w)
{
	sprite.setPosition(x, y);
}

