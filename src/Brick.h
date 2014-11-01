#include <GLFW/glfw3.h>
#include <iostream>
#include "BoundingBox.h"

class Brick
{
private:
	int width, height;
	bool visible;
public:
	BoundingBox *bounds;
	Brick(int w, int h);
	void render();
	void update(float dt);
	void collision();
};