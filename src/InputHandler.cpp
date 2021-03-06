#include "InputHandler.h"

using namespace std;

InputHandler::InputHandler()
{
	wireframe = false;
}

void InputHandler::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

	if(action == GLFW_PRESS)
	{
		if(key == GLFW_KEY_A || key == GLFW_KEY_LEFT )
		{
			Subject::notify("KEY_LEFT_DOWN");
		}
	    if(key == GLFW_KEY_D || key == GLFW_KEY_RIGHT)
	    {
	    	Subject::notify("KEY_RIGHT_DOWN");
	    }
	    if(key == GLFW_KEY_SPACE)
	    {
	    	Subject::notify("KEY_SPACE_DOWN");
	    }
	    if(key == GLFW_KEY_TAB)
	    {
	    	wireframe = !wireframe;
	    	glPolygonMode( GL_FRONT_AND_BACK, wireframe ? GL_LINE : GL_FILL );
	    }
	} else if(action == GLFW_RELEASE) {
		if(key == GLFW_KEY_A || key == GLFW_KEY_LEFT )
		{
			Subject::notify("KEY_LEFT_UP");
		}
		if(key == GLFW_KEY_D || key == GLFW_KEY_RIGHT)
	    {
	    	Subject::notify("KEY_RIGHT_UP");
	    }
	} else if(action == GLFW_REPEAT) {
		if(key == GLFW_KEY_A || key == GLFW_KEY_LEFT )
		{
			Subject::notify("KEY_LEFT_DOWN");
		}
	    if(key == GLFW_KEY_D || key == GLFW_KEY_RIGHT)
	    {
	    	Subject::notify("KEY_RIGHT_DOWN");
	    }
	}
}

void InputHandler::checkInput()
{
	if (glfwJoystickPresent(GLFW_JOYSTICK_1) == GL_TRUE) 
	{
		buttons = (bool*)glfwGetJoystickButtons(GLFW_JOYSTICK_1, &numbuttons);
		axes = glfwGetJoystickAxes(GLFW_JOYSTICK_1, &numaxes);
		for (int i = 0; i < numbuttons; i++) 
		{
			if(buttons[i] == GL_TRUE)
			{
				if(i == XBOX360_A)
				{
					cout << "A Button" << endl;
				}
				if(i == XBOX360_B)
				{
					cout << "B Button" << endl;
				}
				if(i == XBOX360_X)
				{
					cout << "X Button" << endl;
				}
				if(i == XBOX360_Y)
				{
					cout << "Y Button" << endl;
				}
				if(i == XBOX360_START)
				{
					Subject::notify("TOGGLE_PAUSE");
				}
			}
		}

		//cout << axes[0] << endl;
		if(axes[0] < 0 && axes[0] <= -1.0f) 
		{
			//position = axes[0] * speed;
			//position *= deltaTime;
			Subject::notify("JOYSTICK_LEFT_DOWN");
		} else if(axes[0] > 0 && axes[0] >= 1.0f) {
			Subject::notify("JOYSTICK_RIGHT_DOWN");
		} else if(axes[0] == 1.0f) {
			Subject::notify("RELEASE");
		}
	}
}