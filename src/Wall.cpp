#include "Wall.h"

using namespace std;

Wall::Wall()
{

}

Wall::Wall(vector< vector<double> > level)
{
	setLevel(level);
}

void Wall::setLevel(vector< vector<double> > level)
{
	unsigned int color = 0xFF0000;
	int rowindex = 0;
	int colindex = 0;
	bool vis = true;
	int rowcount = 0;
	int colcount = 0;
	int bwidth = 0;
	int bheight = 0;
	int brickpadx = 10;
	int brickpady = 10;

	rowcount = level.size();
	colcount = level[0].size();
	bwidth = (2048 / colcount) - brickpadx;
	bheight = ( (1536/6) / rowcount) - brickpady;

	vector< vector<double> >::const_iterator row;
	vector<double>::const_iterator col;
	for (row = level.begin(); row != level.end(); ++row) 
	{
		if(rowindex == 0) color = 0xFF0000;
		if(rowindex == 1) color = 0x00FF00;
		if(rowindex == 2) color = 0x0000FF;
		if(rowindex == 3) color = 0xFF00FF;
		if(rowindex == 4) color = 0xFFFF00;
		vector<Brick> brick_vector;
		colindex = 0;
		for (col = row->begin(); col != row->end(); ++col) 
		{
			vis = *col;
			brick_vector.push_back(Brick(bwidth,bheight,(bwidth + brickpadx) * colindex + brickpadx, (bheight + brickpady) * rowindex + brickpady, color, vis));
			++colindex;
			vis = true;
		}
		bricks.push_back(brick_vector);
		++rowindex;
	}
}

void Wall::render()
{
	for (int i = 0; i < bricks.size(); ++i)
	{
		for (int j = 0; j < bricks[i].size(); ++j)
		{			
			if(bricks[i][j].visible)
			{
				bricks[i][j].render();
			}
		}
	}
}

void Wall::update()
{
	for (int i = 0; i < bricks.size(); ++i)
	{
		for (int j = 0; j < bricks[i].size(); ++j)
		{
			if(bricks[i][j].visible)
			{
				bricks[i][j].update();
			}
		}
	}
}

void Wall::onNotify(string eventname)
{
	if(eventname == "KEY_SPACE_DOWN")
	{
		//level complete
		for (int i = 0; i < bricks.size(); ++i)
		{
			for (int j = 0; j < bricks[i].size(); ++j)
			{
				bricks[i][j].visible = false;
			}
		}
	}
}