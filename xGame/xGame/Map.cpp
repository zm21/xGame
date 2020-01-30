#include "Map.h"

Map::Map(String file_bush):size(35), count(0), file_bush(file_bush)
{
	tile_map.resize(size);
	for (int i = 0; i < size; i++)
	{
		tile_map[i].resize(35);
	}
	bushes.resize(5);
	InitMap();
}

void Map::InitMap()
{
	int row{}, coll{};

	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			tile_map[i][j] = empty_;

	for (int i = 0; i < 10; ++i)
	{
		if (i % 2 == 0)
		{			
		row = 5 + rand() % (30 - 5 + 1);
		coll = 5 + rand() % (30 - 5 + 1);
		tile_map[row][coll]=bush_;
		}
	} 
	InitBushes();
}

void Map::InitBushes()
{
	int index_bush{};
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (tile_map[i][j] == bush_)
			{
				bushes[index_bush].Bush::Bush(file_bush, i * 32.f, j * 32.f);
				bushes[index_bush].SetX(i * 32);
				bushes[index_bush++].SetY(j * 32);
			}
		}
	}
	cout << "init" << endl;
}

void Map::DrawBushes(RenderWindow &window)
{
	for (auto i = bushes.begin(); i!= bushes.end(); i++)
	{
		window.draw(i->GetSprite());
	}
}

void Map::CheckCollisionWithoObject(float hero_tempX, float hero_tempY, float & hero_x, float & hero_y, float dx, float dy) 
{
	for (auto i = bushes.begin(); i != bushes.end(); i++)
	{
		if (dx > 0.f)
		{
			if (i->GetX()-64 > hero_x)
			{
				cout << " (i->GetX()-64 > hero_x)" << endl;
				if (i->GetX() < hero_x + 32)
					hero_x = hero_tempX;
			}
			cout << "dx>0  " << i->GetX() << endl;
		}
		else if (dx < 0.f)
		{
			if (i->GetX() + 64 < hero_x)
			{
				if (i->GetX() > hero_x-64)
					hero_x = hero_tempX;
			}
		}
		if (dy > 0.f)
		{
			if (i->GetY() - 32 > hero_y)
			{
				if (i->GetY() < hero_y + 32)
					hero_y = hero_tempY;
			}
		}
		else if (dx < 0.f)
		{
			if (i->GetY() + 64 < hero_y)
			{
				if (i->GetY() > hero_y - 64)
					hero_y = hero_tempY;
			}
		}
	}
}

bool Map::CheckHeroOnBush(float x, float y)
{
		//cout << "X: " << x << "  Y: " << y << endl;
	for (int i = 0; i < bushes.size(); i++)
	{
	//	cout << "i->GetX()" << bushes[i].GetX() << "  i->GetY()  " << bushes[i].GetY() << endl;
		//if((bushes[i].GetX() <= x-30 || bushes[i].GetX()-30 >= x) && (bushes[i].GetY() >= y-30 || bushes[i].GetY() + 30 >= y))
		//cout << "bushes[i].GetX() : " << bushes[i].GetX() << "   bushes[i].GetY" << bushes[i].GetY() << endl;
		if (x-16 < bushes[i].GetX()+64 && x >bushes[i].GetX())
		{
			if(y-16 < bushes[i].GetY() && y > bushes[i].GetY())
				return true;
		}
			
	}
	return false;
}

