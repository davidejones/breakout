#include <GLFW/glfw3.h>
#include <iostream>

class GameWindow
{
private:
	GLFWwindow* _window;
	float _ratio;
public:
	bool windowShouldClose();
	void setKeyCallback(GLFWkeyfun key_callback);

	GameWindow();

	void render();
	void update(float dt);
	void terminate();
	void clear();
};