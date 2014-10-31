#include <GLFW/glfw3.h>
#include <iostream>
#include "GameWindow.h"
#include "Triangle.h"
#include "Ball.h"

void render();
void update(float dt);

using namespace std;

GameWindow *gameWindow;
float deltaTime = 0.0f;
float lastFrame = 0.0f;
Triangle *triangle;
Ball *ball;

int main(void)
{
	gameWindow = new GameWindow();
	triangle = new Triangle();
	ball = new Ball();

	/* Loop until the user closes the window */
	while (!gameWindow->windowShouldClose())
	{
		// Set frame time
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		update(deltaTime);
		render();
	}

	gameWindow->terminate();
	delete gameWindow;
	
	return 0;
}

void render()
{
	gameWindow->clear();
	//triangle->render();
	ball->render();
	gameWindow->render();
}

void update(float dt)
{
	//triangle->update(dt);
	ball->update(dt);
	gameWindow->update(dt);
}
