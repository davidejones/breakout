#include <GLFW/glfw3.h>
#include <iostream>

class GameWindow
{
private:
	GLFWwindow* _window;
	float _ratio;
public:
	bool windowShouldClose();

	GameWindow();

	void render();
	void update(float dt);
	void terminate();
	void clear();
};