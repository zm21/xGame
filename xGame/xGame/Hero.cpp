#include "Hero.h"

Hero::Hero(String file, float x, float y, float xSprite, float ySprite, float h, float w) :Units(file, x, y, xSprite, ySprite, h, w), current_frame(0) 
{
	view.reset(FloatRect(x, y, 800, 600));
}

void Hero::update(float time)
{
	switch ((Direction)dir)
	{
		//on the x, the positive speed, on the y 0 - movement only to the right
	case right_dir:
	{
		dx = speed;
		dy = 0;
		break;
	}
	//on the x, negative speed, on the y 0 - movement only to the left
	case left_dir:
	{
		dx = -speed;
		dy = 0;
		break;
	}
	//the speed is 0 on the x, positive on the y - the movement is only down
	case down_dir:
	{
		dx = 0;
		dy = speed;
		break;
	}
	//x speed 0, y negative - movement only up
	case up_dir:
	{
		dx = 0;
		dy = -speed;
		break;
	}
	}

	//the velocity x and y at the time we get the displacement of the sprite depending on the direction
	x += dx * time;
	y += dy * time;

	speed = 0; //to stop the movement
	sprite.setPosition(x, y); //updating the position of the sprite
}

void Hero::Move(float time)
{
	if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A))))
	{
		dir = left_dir;
		speed = 0.1;

		current_frame += 0.005*time;
		current_frame = (current_frame > 3) ? current_frame - 3 : current_frame;//Checking out for the 3rd frame of the animation

		sprite.setTextureRect(IntRect(0 + ((int)current_frame * 49), 47, 39, 46)); //setting texture from tile
	}

	if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D))))
	{
		dir = right_dir;
		speed = 0.1;
		
		current_frame += 0.005*time;
		
		current_frame = (current_frame > 3) ? current_frame - 3 : current_frame;//Checking out for the 3rd frame of the animation

		sprite.setTextureRect(IntRect(0 + ((int)current_frame * 49), 96, 37, 44)); //setting texture from tile
	}

	if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W))))
	{
		dir = up_dir;
		speed = 0.1;

		current_frame += 0.005*time;
		
		current_frame = (current_frame > 3) ? current_frame - 3 : current_frame;//Checking out for the 3rd frame of the animation

		sprite.setTextureRect(IntRect(0 + ((int)current_frame * 49), 145, 37, 41));//setting texture from tile
	}

	if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S))))
	{
		dir = down_dir;
		speed = 0.1;

		current_frame += 0.005*time;

		current_frame = (current_frame > 3) ? current_frame - 3 : current_frame;//Checking out for the 3rd frame of the animation

		sprite.setTextureRect(IntRect(0 + ((int)current_frame * 49), 0, 37, 44));//setting texture from tile
	}
	view.setCenter(x + 100, y);//updating the camera view +100 for side view
}