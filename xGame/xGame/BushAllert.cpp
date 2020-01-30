#include "BushAllert.h"



BushAllert::BushAllert(String file, float xSprite, float ySprite)
{
	texture.loadFromFile("images/" + file); 
	sprite.setTexture(texture);
	sprite.setPosition(xSprite, ySprite);
	font.loadFromFile("Fonts/BK0010.ttf");
	task.setFont(font);
	task.setScale(Vector2f(64,64));
	task.setFillColor(Color::Cyan);
}

void BushAllert::ReTask()
{
	task_str.clear();
	sprite.setPosition(x, y);
	task.setPosition(x + 32, y + 64);
	int digit1{}, digit2{};
	int min = 1, max = 9;
	digit1 = min + rand() % (max - min + 1);
	digit2 = min + rand() % (max - min + 1); 
	if (digit1 < digit2)
		swap(digit1, digit2);
	act = static_cast<MathAction>(sum + rand() % (rizn - sum + 1));
	switch (act)
	{
	case BushAllert::sum:
		answer = digit1 + digit2;
		task_str.push_back(digit1 + 48);
		task_str.push_back('+');
		task_str.push_back(digit2 + 48);
		break;
	case BushAllert::rizn:
		answer = digit1 - digit2;
		task_str.push_back(digit1 + 48);
		task_str.push_back('-');
		task_str.push_back(digit2 + 48);
		break;
	default:
		break;
	}
	task.setString(task_str);
}

bool BushAllert::Task(RenderWindow &window, Event &event)
{
	string str;
	window.draw(sprite);
	task.setScale(Vector2f(64, 64));
	task.setFillColor(Color::Cyan);
	task.setPosition(800 / 2, 600 / 2);
	window.draw(task);
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			window.close();
		if (event.type == sf::Event::TextEntered)
		{
			while (!event.KeyPressed == sf::Keyboard::Escape)
			{
				if (event.KeyPressed == sf::Keyboard::BackSpace && str.size() != 0) {
					str.pop_back();
					cout << str << std::endl;
				}
				else if (event.text.unicode < 128) {
					str.push_back((char)event.text.unicode);
					cout << str << endl;
				}
			}
		}
	}
	if(str.size()>2)
		return false;
	if(str.size()==1)
	{
		if(answer==str[0]-48)
			return true;
	}
	else
	{
		switch (act)
		{
		case '+':
			if (answer == (str[0] - 48) + (str[1] - 48))
				return true;
			break;
		case '-':
			if (answer == (str[0] - 48) - (str[1] - 48))
				return true;
			break;
		default:
			return false;
			break;
		}
	}
	return false;
}


