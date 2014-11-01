#include "GameWindow.h"

GameWindow::GameWindow()
{
    /* Initialize the library */
    glfwInit();

    /* Create a windowed mode window and its OpenGL context */
    _window = glfwCreateWindow(600, 600, "Breakout", NULL, NULL);
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