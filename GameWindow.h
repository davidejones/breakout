#include <GLFW/glfw3.h>
#include <iostream>

class GameWindow
{
private:
	GLFWwindow* _window;
public:
	bool windowShouldClose();

	GameWindow();

	void render();
	void update();
	void terminate();
};