#include "Wall.h"

using namespace std;

Wall::Wall(int levelarray[][10])
{
	rows =  5;
	cols = 10;

	//create bricks
	unsigned int col = 0xFF0000;
	for (int i = 0; i < rows; ++i)
	{
		if(i == 0) col = 0xFF0000;
		if(i == 1) col = 0x00FF00;
		if(i == 2) col = 0x0000FF;
		if(i == 3) col = 0xFF00FF;
		if(i == 4) col = 0xFFFF00;
		for (int j = 0; j < cols; ++j)
		{
			bricks[i][j] = new Brick(80,20,85 * j, 25 * i, col);
		}
	}
}

void Wall::render()
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			bricks[i][j]->render();
		}
	}
}

void Wall::update(float dt)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			bricks[i][j]->update(dt);
		}
	}
}

void Wall::checkCollisions(Ball &ball)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			if(bricks[i][j]->visible)
			{
				if(ball.bounds.checkIntersect(*bricks[i][j]->bounds))
				{
					ball.doBrickCollision(bricks[i][j]);
					bricks[i][j]->doCollision();
				}
			}
		}
	}
}