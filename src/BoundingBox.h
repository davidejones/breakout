#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>

class BoundingBox
{
public:
	int minX, maxX, minY, maxY;
	BoundingBox(void);
	BoundingBox(int left, int right, int top, int bottom);
	bool checkIntersect(BoundingBox b);
};

#endif