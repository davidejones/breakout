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
Triangle triangle;
Ball ball;
Paddle paddle(90,10);
//Brick *brick;
int Level1[5][10] = {
	{1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1}
};
Brick *bricks[5][10];

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
	//triangle = new Triangle();
	//ball = new Ball();
	//paddle = new Paddle(90,10);
	//brick = new Brick(100,10);

	//create bricks
	unsigned int col = 0xFF0000;
	for (int i = 0; i < 5; ++i)
	{
		if(i == 0) col = 0xFF0000;
		if(i == 1) col = 0x00FF00;
		if(i == 2) col = 0x0000FF;
		if(i == 3) col = 0xFF00FF;
		if(i == 4) col = 0xFFFF00;
		for (int j = 0; j < 10; ++j)
		{
			bricks[i][j] = new Brick(80,20,85 * i, 25 * j, col);
		}
	}

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
	triangle.render();
	ball.render();
	paddle.render();
	
	//brick->render();
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			bricks[i][j]->render();
		}
	}

	gameWindow->render();
}

void update(float dt)
{
	checkCollisions();
	triangle.update(dt);
	ball.update(dt);
	paddle.update(dt);
	
	//brick->update(dt);
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			bricks[i][j]->update(dt);
		}
	}

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

	/*
	if(ball->bounds->checkIntersect(*brick->bounds))
	{
		brick->collision();
		//delete brick;
	}
	*/
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			if(bricks[i][j]->visible)
			{
				if(ball.bounds->checkIntersect(*bricks[i][j]->bounds))
				{
					ball.brickCollision();
					bricks[i][j]->collision();
				}
			}
		}
	}

	//if ball hit paddle then we need to adjust ball trajectory
	if(ball.bounds->checkIntersect(*paddle.bounds))
	{
		ball.paddleCollision();
	}
}