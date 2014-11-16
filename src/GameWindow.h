#include <GLFW/glfw3.h>
#include <iostream>

class GameWindow
{
private:
	GLFWwindow* _window;
	float _ratio;
	int width, height;
public:
	bool windowShouldClose();
	void setKeyCallback(GLFWkeyfun key_callback);
	void projection();

	GameWindow(int w, int h, bool fullscreen=true, bool border=true);

	void render();
	void update(float dt);
	void terminate();
	void clear();
};