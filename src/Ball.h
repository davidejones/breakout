#ifndef BALL_H
#define BALL_H

#include "BoundingBox.h"
#include "Vector2.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>

class Ball
{
private:
	Vector2 direction, position;
	int speed, maxSpeed, speedIncrement;
	void drawCircle(float cx, float cy, float r, int num_segments);
	void filledCircle();
public:
	BoundingBox bounds;
	Ball();
	void render();
	void update(float dt);
	void doBrickCollision();
	void doPaddleCollision(BoundingBox paddlebounds);
};

#endif