#pragma once
#include "Units.h"
#include "Border.h"
#include "Map.h"
#include "BushAllert.h"
class Hero : public Units
{
	int life;
	View view;
	float current_frame;
	float tempX, tempY;
public:
	Hero(String file, float x, float y, float xSprite, float ySprite, float h, float w);
	virtual void update(float time, BushAllert &allert);
	void Move(float time);
	Sprite& GetSprite() { return sprite; }
	View& GetView() { return view; }
	void ViewUpdate();
	void ResetView() { view.setCenter(800/2, 600/2); };
	void ZeroView() { view.setCenter(0, 0); };
	void CheckingOutLimits(float tempX, float tempY);
	float GetTempX() { return tempX; }
	float GetTempY() { return tempY; }
	float& GetXWithAddress() { return x; } //Get X position of unit
	float& GetYWithAddress() { return y; } //Get Y position of unit
	float GetDx() { return dx; }
	float GetDy() { return dy; }
};