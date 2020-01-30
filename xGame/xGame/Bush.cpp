#include "Bush.h"

Bush::Bush():file("images/bush.png"){}

Bush::Bush(String file, float x, float y)
{
	this->file = file;
	image.loadFromFile("images/" + this->file);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	stage =static_cast<Stage>(dark_green + rand() % (green - dark_green + 1));
	switch (stage)
	{
	case Bush::dark_green:
		xSprite = 32;
		ySprite = 0;
		height = 32;
		width = 64;
		break;
	case Bush::green:
		xSprite = 0;
		ySprite = 0;
		height = 32;
		width = 32;
		break;
	default:
		break;
	}
	sprite.setTextureRect(IntRect(xSprite, ySprite, height, width));
	sprite.setPosition(x, y);
}

//case Bush::dark_green:
//	SetXSprite(32);
//	SetYSprite(0);
//	SetHeight(64);
//	SetWidth(32);
//	break;
//case Bush::green:
//	SetXSprite(0);
//	SetYSprite(0);
//	SetHeight(32);
//	SetWidth(32);
//	break;
//default:
//	break;