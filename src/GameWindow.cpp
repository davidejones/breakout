#include "GameWindow.h"

GameWindow::GameWindow()
{
    /* Initialize the library */
    glfwInit();

    /* Create a windowed mode window and its OpenGL context */
    _window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!_window)
    {
        glfwTerminate();
    }

    /* Make the window's context current */
	glfwMakeContextCurrent(_window);
}

bool GameWindow::windowShouldClose() 
{
	return glfwWindowShouldClose(_window);
}

void GameWindow::render()
{
	glfwSwapBuffers(_window);
	/* Poll for and process events */
    glfwPollEvents();
}

void GameWindow::update(float dt)
{
	
}

void GameWindow::terminate()
{
	glfwTerminate();
}