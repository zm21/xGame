#pragma once
#include "GameObject.h"
class Prop : public GameObject
{
public:
	Prop(String file, float x, float y, float xSprite, float ySprite, float h, float w);
	virtual void Draw() { cout << "Class Prop: GameObject draw" << endl; };
};

