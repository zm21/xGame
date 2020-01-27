#pragma once
#include "Prop.h"
class Grass : public Prop
{
public:
	Grass(String file, float x, float y, float xSprite, float ySprite, float h, float w);
	Sprite& GetSprite() { return sprite; }
};

