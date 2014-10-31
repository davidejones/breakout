#include <GLFW/glfw3.h>
#include <iostream>

class Paddle
{
private:
	float posX;
	float posY;
public:
	Paddle();
	void render();
	void update(float dt);
	void moveLeft();
	void moveRight();
};