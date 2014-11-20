#ifndef WALL_H
#define WALL_H

#include "Brick.h"
#include "BoundingBox.h"
#include "Observer.h"
#include <GLFW/glfw3.h>
#include <vector>
#include <iostream>
#include <string>

class Wall: public Observer
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
	void onNotify(std::string eventname);
};

#endif