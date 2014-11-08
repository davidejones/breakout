#ifndef WALL_H
#define WALL_H

#include "Brick.h"
#include "Ball.h"
#include "BoundingBox.h"
#include <GLFW/glfw3.h>
#include <iostream>

class Wall
{
private:
	Brick *bricks[5][10];
	int rows, cols;
public:
	Wall(int levelarray[][10]);
	void render();
	void update(float dt);
	void checkCollisions(Ball &ball);
};

#endif