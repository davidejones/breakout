#ifndef VECTOR2_H
#define VECTOR2_H

#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>

class Vector2
{
public:
	Vector2(void);
	Vector2(float X, float Y);
	~Vector2(void);
	float Length();
	Vector2 Normalize();
	float X,Y;
};

#endif