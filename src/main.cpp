#include "GameWindow.h"
#include "Ball.h"
#include "Paddle.h"
#include "Wall.h"
#include "Collision.h"
#include "InputHandler.h"
#include <GLFW/glfw3.h>
#include <vector>
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
vector< vector<double> > level1;
vector< vector<double> > level2;
Wall wall;
InputHandler inputhandler;

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	inputhandler.key_callback(window, key, scancode, action, mods);
}

void setupLevels()
{
	level1.resize( 5 , vector<double>( 7 , 1 ) );
	level2.resize( 5 , vector<double>( 7 , 1 ) );

	level2[3] = vector<double>( 7 , 0 );

	wall.setLevel(level1);
}

int main(void)
{
	setupLevels();

	gameWindow = new GameWindow();
	gameWindow->setKeyCallback(key_callback);

	//add paddle to input handler so we can react on control input
	Observer* padobserver = &paddle;
	inputhandler.addObserver(padobserver);

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

	drawBoundBoxes();

	gameWindow->render();
}

void update(float dt)
{
	// checking inputs and fire events
	inputhandler.checkInput();

	checkCollisions();

	int iterationsPerFrame = 20;
	float iterationDelta = dt/iterationsPerFrame;

	for (int i = 0; i < iterationsPerFrame; ++i)
	{
		ball.update(iterationDelta);
		checkCollisions();
	}

	paddle.update(dt);
	wall.update(dt);

	//check if game is over	
	bool gameover = true;
	for (int i = 0; i < wall.bricks.size(); ++i)
	{
		for (int j = 0; j < wall.bricks[i].size(); ++j)
		{
			if(wall.bricks[i][j].visible)
			{
				gameover = false;
			}
		}
	}

	if(gameover) {
		wall.setLevel(level2);
	}

	gameWindow->update(dt);
}

void checkCollisions()
{
	//if ball collides with paddle, call onCollisionEnter2D on both objects
	//if ball collides with brick, call onCollisionEnter2D on both objects
	//if above collisions still occouring fire onCollisionStay2D on both
	//if collision is over fire onCollisionExit2D on both
	if(ball.bounds.checkIntersect(paddle.bounds))
	{
		Collision col1(&paddle,"paddle");
		ball.OnCollisionEnter2D(col1);
		Collision col2(&ball,"ball");
		paddle.OnCollisionEnter2D(col2);
	}

	for (int i = 0; i < wall.bricks.size(); ++i)
	{
		for (int j = 0; j < wall.bricks[i].size(); ++j)
		{
			if(wall.bricks[i][j].visible)
			{
				if(ball.bounds.checkIntersect(wall.bricks[i][j].bounds))
				{
					Collision col3(&wall.bricks[i][j], "brick");
					Collision col4(&ball, "ball");
					ball.OnCollisionEnter2D(col3);
					wall.bricks[i][j].OnCollisionEnter2D(col4);
				}
			}
		}
	}
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