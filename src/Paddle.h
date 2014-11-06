#ifndef PADDLE_H
#define PADDLE_H

#include "BoundingBox.h"
#include "Ball.h"
#include <GLFW/glfw3.h>
#include <iostream>

class Paddle
{
private:
	int width, height;
	int x, y;
	int maxspeed, dx, dy;
	int vel;
	bool left, right;
public:
	BoundingBox bounds;
	Paddle(int w, int h);
	void render();
	void update(float dt);
	void moveLeft();
	void moveRight();
	void moveStop();
	void checkCollisions(Ball &ball);
};

#endif