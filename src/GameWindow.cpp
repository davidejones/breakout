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

    _ratio = 600 / 600;

    glViewport(0, 0, 600, 600);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0f, 600, 600, 0.0f, -1.0f, 1.0f);
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity();

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

void GameWindow::clear()
{
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}