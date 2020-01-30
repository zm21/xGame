#include "Hero.h"

Hero::Hero(String file, float x, float y, float xSprite, float ySprite, float h, float w) :Units(file, x, y, xSprite, ySprite, h, w), current_frame(0) , tempX(0), tempY(0), life(3)
{
	view.reset(FloatRect(x, y, 800, 600));
}

void Hero::update(float time, BushAllert &allert)
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
	tempX = x;
	tempY = y;
	x += dx * time;
	y += dy * time;
	CheckingOutLimits(tempX, tempY);
	ViewUpdate();
	speed = 0; //to stop the movement
	sprite.setPosition(x, y); //updating the position of the sprite
	allert.ReTask();
}

void Hero::Move(float time)
{
	float speed_setter=0.1;
	float frame_speed = 0.01;
	if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A))))
	{
		dir = left_dir;
		speed = speed_setter;

		current_frame += frame_speed *time;
		current_frame = (current_frame > 3) ? current_frame - 3 : current_frame;//Checking out for the 3rd frame of the animation
		sprite.setTextureRect(IntRect(0 + ((int)current_frame * 49), 47, 39, 46)); //setting texture from tile
	}

	if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D))))
	{
		dir = right_dir;
		speed = speed_setter;
		
		current_frame += frame_speed *time;
		
		current_frame = (current_frame > 3) ? current_frame - 3 : current_frame;//Checking out for the 3rd frame of the animation

		sprite.setTextureRect(IntRect(0 + ((int)current_frame * 49), 96, 37, 44)); //setting texture from tile
	}

	if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W))))
	{
		dir = up_dir;
		speed = speed_setter;

		current_frame += frame_speed *time;
		
		current_frame = (current_frame > 3) ? current_frame - 3 : current_frame;//Checking out for the 3rd frame of the animation

		sprite.setTextureRect(IntRect(0 + ((int)current_frame * 49), 145, 37, 41));//setting texture from tile
	}

	if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S))))
	{
		dir = down_dir;
		speed = speed_setter;

		current_frame += frame_speed *time;

		current_frame = (current_frame > 3) ? current_frame - 3 : current_frame;//Checking out for the 3rd frame of the animation

		sprite.setTextureRect(IntRect(0 + ((int)current_frame * 49), 0, 37, 44));//setting texture from tile
	}
}

void Hero::ViewUpdate()
{
	float viewX = x; float viewY = y;//считываем коорд игрока и проверяем их, чтобы убрать края

	//checking if the camera is out of the map
	if (x < view_left) //check or the camera did not go beyond the left border
		viewX = view_left;
	if (y < view_up) //checking or the camera did not go beyond the upper limit
		viewY = view_up;
	if (y > view_lower) //checking or the camera did not go beyond the lower border
		viewY = view_lower;
	if (x > view_right) //check or the camera did not go beyond the right border
		viewX = view_right;
	view.setCenter(viewX, viewY);//updating the camera
}

void Hero::CheckingOutLimits(float tempX, float tempY)
{
	//checking if the camera is out of the map
	if (x < hero_left) //check or the camera did not go beyond the left border
		x = tempX;
	if (y < hero_up) //checking or the camera did not go beyond the upper limit
		y = tempY;
	if (y > hero_lower) //checking or the camera did not go beyond the lower border
		y = tempY;
	if (x > hero_right) //check or the camera did not go beyond the right border
		x = tempX;	
}
