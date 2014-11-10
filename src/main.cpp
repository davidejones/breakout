#include "GameWindow.h"
#include "Ball.h"
#include "Paddle.h"
#include "Wall.h"
#include <GLFW/glfw3.h>
#include <iostream>

void render();
void update(float dt);
void checkCollisions();
void drawBoundBoxes();

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
const bool* buttons;
int numbuttons;
const float* axes;
int numaxes;

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

    if(key == GLFW_KEY_A || key == GLFW_KEY_LEFT )
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
				paddle.moveLeft();
			} else if(axes[0] > 0 && axes[0] >= 1.0f) {
				paddle.moveRight();
			} else {
				paddle.moveStop();
			}
		}

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

	drawBoundBoxes();

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

void drawBoundBoxes()
{
	/*
    //glPushMatrix();
	//glTranslatef(ball.bounds.minX,ball.bounds.minY,0);
	glBegin(GL_LINE_LOOP);
		glColor3f(0.f, 1.f, 0.f);
		glVertex3f(ball.bounds.minX, ball.bounds.minY , 0.f);
		glVertex3f(ball.bounds.minX, ball.bounds.maxY, 0.f);
		glVertex3f(ball.bounds.maxX, ball.bounds.maxY, 0.f);
		glVertex3f(ball.bounds.maxX, ball.bounds.minY , 0.f);
	glEnd();
	//glPopMatrix();

	glBegin(GL_LINE_LOOP);
		glColor3f(0.f, 1.f, 0.f);
		glVertex3f(paddle.bounds.minX, paddle.bounds.minY , 0.f);
		glVertex3f(paddle.bounds.minX, paddle.bounds.maxY, 0.f);
		glVertex3f(paddle.bounds.maxX, paddle.bounds.maxY, 0.f);
		glVertex3f(paddle.bounds.maxX, paddle.bounds.minY , 0.f);
	glEnd();

	//wall bounds
	*/	
}