#include "GameWindow.h"

using namespace std;

GameWindow::GameWindow(int w, int h, bool fullscreen, bool border)
{
    /* Initialize the library */
    glfwInit();

    /*
    //get monitory size and create window to that
    const GLFWvidmode * mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    _window = glfwCreateWindow(mode->width, mode->height, "Breakout", NULL, NULL);
    */

    const GLFWvidmode * mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

    if(w == 0 && h == 0)
    {
    	width = mode->width;
    	height = mode->height;
    } else {
		width = w;
    	height = h;
    }

    if(!border) {
    	glfwWindowHint(GLFW_DECORATED, GL_FALSE);
    }

    glfwWindowHint(GLFW_SAMPLES, 0);
    //glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing

    /* Create a windowed mode window and its OpenGL context */
    _window = glfwCreateWindow(width, height, "Breakout", fullscreen ? glfwGetPrimaryMonitor() : NULL, NULL);   
    if (!_window)
    {
        glfwTerminate();
    }

    //glfwSetWindowPos(_window, (mode->width * 0.5) - (width * 0.5) , (mode->height * 0.5) - (height * 0.5) );


    int widthMM, heightMM;
    glfwGetMonitorPhysicalSize(glfwGetPrimaryMonitor(), &widthMM, &heightMM);
    const double dpi = mode->width / (widthMM / 25.4);
    const char* name = glfwGetMonitorName(glfwGetPrimaryMonitor());
    cout << name << " - " << dpi << "dpi" << endl;

    /* Make the window's context current */
	glfwMakeContextCurrent(_window);
}

void GameWindow::projection()
{
	glfwGetFramebufferSize(_window, &width, &height);
	_ratio = width / (float) height;

    // This is your target virtual resolution for the game, the size you built your game to
    int virtual_width=1920;
    int virtual_height=1080;
     
    float targetAspectRatio = virtual_width/virtual_height;
     
    // figure out the largest area that fits in this resolution at the desired aspect ratio
    /*
    int myw = width ;
    int myh = (int)(myw / targetAspectRatio + 0.5f);
     
    if (myh > height )
    {
       //It doesn't fit our height, we must switch to pillarbox then
        myh = height ;
        myw = (int)(myh * targetAspectRatio + 0.5f);
    }
    */

    //as we are using 16:9 we want to always match width first over height
    int myw = width;
    int myh = (virtual_height * height) / virtual_width;

    // set up the new viewport centered in the backbuffer
    int vp_x = (width  / 2) - (myw / 2);
    int vp_y = (height / 2) - (myh/ 2);
   
    glViewport(vp_x,vp_y,myw,myh);
	
	//glViewport(0, 0, width, height);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(0.0, 600, 600, 0.0, -1.0, 1.0);
	glOrtho(0.0, (float)width, (float)height, 0.0, -1.0, 1.0);
	//glOrtho(-_ratio, _ratio, -1.f, 1.f, 1.f, -1.f);
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity();


    //Now to calculate the scale considering the screen size and virtual size
    float scale_x = (float)((float)width / (float)virtual_width);
    float scale_y = (float)((float)height / (float)virtual_height);
    glScalef(scale_x, scale_y, 1.0f);
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