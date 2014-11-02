#include <GLFW/glfw3.h>
#include <iostream>
#include "BoundingBox.h"

class Paddle
{
private:
	int width, height;
	int x, y;
	int maxspeed, dx, dy;
	int vel;
	bool left, right;
public:
	BoundingBox *bounds;
	Paddle(int w, int h);
	void render();
	void update(float dt);
	void moveLeft();
	void moveRight();
	void moveStop();
};