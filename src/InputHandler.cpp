#include "InputHandler.h"

using namespace std;

InputHandler::InputHandler()
{
	
}

void InputHandler::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

    if(key == GLFW_KEY_A || key == GLFW_KEY_LEFT )
    {
    	//left
    	//paddle.moveLeft();
    }
    if(key == GLFW_KEY_D || key == GLFW_KEY_RIGHT)
    {
    	//right
    	//paddle.moveRight();
    }

    if(action == GLFW_RELEASE) 
    {
    	//paddle.moveStop();
    }
}

void InputHandler::checkInput()
{
	//let observers know
	//Subject::notify();
	/*
		EVENTS
		LEFT
		RIGHT
		PAUSE
	*/

	if (glfwJoystickPresent(GLFW_JOYSTICK_1) == GL_TRUE) 
	{
		buttons = (bool*)glfwGetJoystickButtons(GLFW_JOYSTICK_1, &numbuttons);
		axes = glfwGetJoystickAxes(GLFW_JOYSTICK_1, &numaxes);
		for (int i = 0; i < numbuttons; i++) 
		{
			if(buttons[i] == GL_TRUE)
			{
				//pressed
				//A = 0, X = 2, Y = 3, B = 1, 4 left shoulder, 5 right shoulder
				//cout << i << endl;
			}
		}

		//cout << axes[0] << endl;
		if(axes[0] < 0 && axes[0] <= -1.0f) {
			//paddle.moveLeft();
		} else if(axes[0] > 0 && axes[0] >= 1.0f) {
			//paddle.moveRight();
		} else {
			//paddle.moveStop();
		}
	}

}