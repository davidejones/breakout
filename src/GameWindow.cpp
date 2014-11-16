#include "GameWindow.h"

using namespace std;

GameWindow::GameWindow(int w, int h, bool fullscreen, bool border)
{
    /* Initialize the library */
    glfwInit();

    /*
    //get monitory size and create window to that
    const GLFWvidmode * mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    _window = glfwCreateWindow(mode->width, mode->height, "Breakout", NULL, NULL);
    */

    if(w == 0 && h == 0)
    {
    	const GLFWvidmode * mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    	width = mode->width;
    	height = mode->height;
    } else {
		width = w;
    	height = w;
    }

    if(!border) {
    	glfwWindowHint(GLFW_DECORATED, GL_FALSE);
    }

    /* Create a windowed mode window and its OpenGL context */
    _window = glfwCreateWindow(width, height, "Breakout", fullscreen ? glfwGetPrimaryMonitor() : NULL, NULL);   
    if (!_window)
    {
        glfwTerminate();
    }

    /* Make the window's context current */
	glfwMakeContextCurrent(_window);
}

void GameWindow::projection()
{
	glfwGetFramebufferSize(_window, &width, &height);
	_ratio = width / (float) height;
	
	glViewport(0, 0, width, height);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(0.0, 600, 600, 0.0, -1.0, 1.0);
	glOrtho(0.0, width, height, 0.0, -1.0, 1.0);
	//glOrtho(-_ratio, _ratio, -1.f, 1.f, 1.f, -1.f);
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity();
}

bool GameWindow::windowShouldClose() 
{
	return glfwWindowShouldClose(_window);
}

void GameWindow::setKeyCallback(GLFWkeyfun key_callback)
{
	glfwSetKeyCallback(_window, key_callback);
}

void GameWindow::render()
{
	glfwSwapBuffers(_window);
    glfwPollEvents();
}

void GameWindow::update(float dt)
{
	
}

void GameWindow::terminate()
{
	glfwTerminate();
}

void GameWindow::clear()
{
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}