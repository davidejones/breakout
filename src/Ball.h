#ifndef BALL_H
#define BALL_H

#include "BoundingBox.h"
#include "Vector2.h"
#include "Brick.h"
#include "GameObject.h"
#include "Collision.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>

class Ball: public GameObject
{
private:
	Vector2 direction, position;
	int maxSpeed, speedIncrement, speed, ballwidth, fadecount;
	float alpha;
	bool doFading, fadeIn, fadeOut;
	void drawCircle(float cx, float cy, float r, int num_segments);
public:
	//BoundingBox bounds;
	Ball(GameSound* gSnd);
	GameSound* gameSound;
	void render();
	void update();
	void OnCollisionEnter2D(Collision collision);
	void reset();
	void waitMode();
};

#endif