#ifndef BRICK_H
#define BRICK_H

#include "BoundingBox.h"
#include <GLFW/glfw3.h>
#include <iostream>

class Brick
{
private:
	int width, height, x, y;
	unsigned int R,G,B;
public:
	bool visible;
	BoundingBox *bounds;
	Brick(int w, int h, int xpos, int ypos, unsigned int color);
	void render();
	void update(float dt);
	void doCollision();
};

#endif