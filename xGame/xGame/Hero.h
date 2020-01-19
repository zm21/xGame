#pragma once
#include "Units.h"

class Hero : public Units
{
	View view;
	float current_frame;
public:
	Hero(String file, float x, float y, float xSprite, float ySprite, float h, float w);
	virtual void update(float time);
	void Move(float time);
	Sprite& GetSprite() { return sprite; }
	View& GetView() { return view; }
};