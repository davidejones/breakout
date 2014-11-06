#include "GameWindow.h"
#include "Ball.h"
#include "Paddle.h"
#include "Wall.h"
#include <GLFW/glfw3.h>
#include <iostream>

void render();
void update(float dt);
void checkCollisions();

using namespace std;

GameWindow *gameWindow;
float deltaTime = 0.0f;
float lastFrame = 0.0f;
Ball ball;
Paddle paddle(90,10);
int Level1[5][10] = {
	{1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1}
};
int Level2[5][10] = {
	{0,0,0,1,1,1,1,0,0,0},
	{0,0,1,1,1,1,1,1,0,0},
	{1,1,1,1,1,1,1,1,1,1},
	{0,1,1,1,1,1,1,1,0,0},
	{0,0,0,1,1,1,1,0,0,0}
};
int Level3[5][10] = {
	{0,1,0,1,0,1,0,1,0,1},
	{0,1,0,1,0,1,0,1,0,1},
	{0,1,0,1,0,1,0,1,0,1},
	{0,1,0,1,0,1,0,1,0,1},
	{0,1,0,1,0,1,0,1,0,1}
};
int Level4[5][10] = {
	{1,0,1,0,1,0,1,0,1,0},
	{0,1,0,1,0,1,0,1,0,1},
	{1,0,1,0,1,0,1,0,1,0},
	{0,1,0,1,0,1,0,1,0,1},
	{1,0,1,0,1,0,1,0,1,0}
};
Wall wall(Level1);

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);

    if(key == GLFW_KEY_A || key == GLFW_KEY_LEFT)
    {
    	//left
    	paddle.moveLeft();
    }
    if(key == GLFW_KEY_D || key == GLFW_KEY_RIGHT)
    {
    	//right
    	paddle.moveRight();
    }

    if(action == GLFW_RELEASE) 
    {
    	paddle.moveStop();
    }
}

int main(void)
{
	gameWindow = new GameWindow();
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
	
	ball.render();
	paddle.render();
	wall.render();

	gameWindow->render();
}

void update(float dt)
{
	checkCollisions();

	ball.update(dt);
	paddle.update(dt);
	wall.update(dt);

	gameWindow->update(dt);
}

void checkCollisions()
{
	wall.checkCollisions(ball);
	paddle.checkCollisions(ball);
}