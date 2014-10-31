#include <GLFW/glfw3.h>
#include <iostream>

class Brick
{
public:
	Brick();
	void render();
	void update(float dt);
};