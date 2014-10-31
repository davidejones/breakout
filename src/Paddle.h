#include <GLFW/glfw3.h>
#include <iostream>

class Paddle
{
private:
	float posX;
public:
	Paddle();
	void render();
	void update(float dt);
	void moveLeft();
	void moveRight();
};