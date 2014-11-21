#ifndef PADDLE_H
#define PADDLE_H

#include "BoundingBox.h"
#include "Ball.h"
#include "GameObject.h"
#include "Observer.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

class Paddle: public GameObject, public Observer
{
private:
	int width, height;
	int x, y;
	int maxspeed, dx, dy;
	int vel;
	bool left, right;
public:
	//BoundingBox bounds;
	Paddle(int w, int h);
	void render();
	void update();
	void checkCollisions(Ball &ball);
	void OnCollisionEnter2D(Collision collision);
	void onNotify(std::string eventname);
};

#endif