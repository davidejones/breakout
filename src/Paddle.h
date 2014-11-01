#include <GLFW/glfw3.h>
#include <iostream>
#include "BoundingBox.h"

class Paddle
{
private:
	float posX;
	float posY;
	int width, height;
public:
	BoundingBox *bounds;
	Paddle(int w, int h);
	void render();
	void update(float dt);
	void moveLeft();
	void moveRight();
};