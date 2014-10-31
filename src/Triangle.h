#include <GLFW/glfw3.h>
#include <iostream>

class Triangle
{
private:
	float Rot;
public:
	Triangle();
	void render();
	void update(float dt);
};