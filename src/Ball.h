#ifndef BALL_H
#define BALL_H

#include "BoundingBox.h"
#include "Vector2.h"
#include "Brick.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>

class Ball
{
private:
	Vector2 direction, position;
	int maxSpeed, speedIncrement;
	float speed;
	void drawCircle(float cx, float cy, float r, int num_segments);
public:
	BoundingBox bounds;
	Ball();
	void render();
	void update(float dt);
	void doBrickCollision(Brick *brick);
	void doPaddleCollision(BoundingBox paddlebounds);
};

#endif