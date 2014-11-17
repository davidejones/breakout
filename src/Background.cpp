#include "Background.h"

using namespace std;

Background::Background()
{
    
}

void Background::render()
{
	int width = 2048;
	int height = 1536;

	glBegin(GL_QUADS);
		glColor3f(0.114f, 0.114f, 0.114f); //1d1d1d
		glVertex3f(0.f ,0.f , 0.f);
		glVertex3f(0.f ,height, 0.f);
		glVertex3f(width, height, 0.f);
		glVertex3f(width,0.f , 0.f);
	glEnd();
}

void Background::update(float dt)
{

}