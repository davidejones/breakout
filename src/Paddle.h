#include <GLFW/glfw3.h>
#include <iostream>
#include "BoundingBox.h"

class Paddle
{
private:
	int width, height;
	int x, y;
public:
	BoundingBox *bounds;
	Paddle(int w, int h);
	void render();
	void update(float dt);
	void moveLeft();
	void moveRight();
};