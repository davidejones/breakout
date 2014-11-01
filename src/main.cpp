#include <GLFW/glfw3.h>
#include <iostream>
#include "GameWindow.h"
#include "Triangle.h"
#include "Ball.h"
#include "Paddle.h"
#include "Brick.h"

void render();
void update(float dt);
void checkCollisions();

using namespace std;

GameWindow *gameWindow;
float deltaTime = 0.0f;
float lastFrame = 0.0f;
Triangle *triangle;
Ball *ball;
Paddle *paddle;
Brick *brick;

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);

    if(key == GLFW_KEY_A || key == GLFW_KEY_LEFT)
    {
    	//left
    	paddle->moveLeft();
    }
    if(key == GLFW_KEY_D || key == GLFW_KEY_RIGHT)
    {
    	//right
    	paddle->moveRight();
    }
}

int main(void)
{
	gameWindow = new GameWindow();
	triangle = new Triangle();
	ball = new Ball();
	paddle = new Paddle(90,10);
	brick = new Brick(100,10);

	gameWindow->setKeyCallback(key_callback);

	/* Loop until the user closes the window */
	while (!gameWindow->windowShouldClose())
	{
		// Set frame time
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		gameWindow->projection();

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
	triangle->render();
	ball->render();
	paddle->render();
	brick->render();
	gameWindow->render();
}

void update(float dt)
{
	checkCollisions();
	triangle->update(dt);
	ball->update(dt);
	paddle->update(dt);
	brick->update(dt);
	gameWindow->update(dt);
}

void checkCollisions()
{
	/*
		if we have some level with an array of bricks
		we would loop over each brick and check ball bounds in relation to brick bounds
		if there is overlap then collision has occoured and trigger event on brick
		e.g destroyed fade out, or perhaps some bricks take 2 or 3 collisions before destruction etc.
	*/
	if(ball->bounds->checkIntersect(*brick->bounds))
	{
		brick->collision();
	}
}