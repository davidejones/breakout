#include "GameWindow.h"
#include "Ball.h"
#include "Paddle.h"
#include "Wall.h"
#include "Collision.h"
#include "InputHandler.h"
#include <GLFW/glfw3.h>
#include <vector>
#include <string>
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

static void show_usage(string name)
{
    cerr << "Usage: " << name << " <option(s)>" << endl
              << "Options:\n"
              << "\t-h,--help\t\tShow this help message\n"
              << "\t-fullscreen\t\tOpen fullscreen window\n"
              << "\t-windowed\t\tOpen windowed\n"
              << "\t-640x480\t\t640x480 resolution in windowed mode\n"
              << "\t-800x600\t\t800x600 resolution in windowed mode\n"
              << "\t-1024x768\t\t1024x768 resolution in windowed mode\n"
              << "\t-1280x720\t\t1280x720 resolution in windowed mode\n"
              << "\t-1920x1080\t\t1920x1080 resolution in windowed mode\n"
              << "\t-noborder\t\tborderless window in windowed mode\n"
              << endl;
}

void setupLevels()
{
	level1.resize( 5 , vector<double>( 7 , 1 ) );
	level2.resize( 5 , vector<double>( 7 , 1 ) );

	level2[3] = vector<double>( 7 , 0 );

	wall.setLevel(level1);
}

int main(int argc, char *argv[])
{
	bool fullwindow = false;
	int winw = 0;
	int winh = 0;
	bool border = true;

	if(argc > 1)
	{
		for (int i = 0; i < argc; ++i)
		{
			string arg = argv[i];
			if ((arg == "-h") || (arg == "--help")) {
            	show_usage(argv[0]);
            	return 0;
	        } else if (arg == "-fullscreen") {
	        	//do code to make fullscreen window
	        	fullwindow = true;
			} else if (arg == "-windowed") {
				//do code to make windowed
				fullwindow = false;
				//loop over all args again and check for windowed resolutions
				for (int j = 0; j < argc; ++j)
				{
					string resarg = argv[j];

					if(resarg == "-noborder")
					{
						border=false;
					}

					if(resarg == "-640x480") {
						winw = 640;
						winh = 480;
					} else if(resarg == "-800x600") {
						winw = 800;
						winh = 600;
					} else if(resarg == "-1024x768") {
						winw = 1024;
						winh = 768;
					} else if(resarg == "-1280x720") {
						winw = 1280;
						winh = 720;
					} else if(resarg == "-1920x1080") {
						winw = 1920;
						winh = 1080;
					}
				}
			}
		} 
	}

	setupLevels();

	gameWindow = new GameWindow(winw, winh, fullwindow, border);
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