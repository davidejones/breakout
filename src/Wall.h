#ifndef WALL_H
#define WALL_H

#include "Brick.h"
#include "BoundingBox.h"
#include <GLFW/glfw3.h>
#include <vector>
#include <iostream>

class Wall
{
private:
	int rows, cols;
public:	
	std::vector< std::vector<Brick> > bricks;
	Wall();
	Wall(std::vector< std::vector<double> > level);
	void render();
	void update(float dt);
	void setLevel(std::vector< std::vector<double> > level);
};

#endif