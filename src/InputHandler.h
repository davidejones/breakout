#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "Xbox360Controller.h"
#include "Subject.h"
#include <GLFW/glfw3.h>
#include <iostream>

class InputHandler: public Subject {
private:
	const bool* buttons;
	int numbuttons;
	const float* axes;
	int numaxes;
public:
	InputHandler();
	void checkInput();
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
};

#endif