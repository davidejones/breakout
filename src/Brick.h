#include <GLFW/glfw3.h>
#include <iostream>
#include "BoundingBox.h"

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
	void collision();
};