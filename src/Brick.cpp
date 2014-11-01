#include "Brick.h"

Brick::Brick(int w, int h)
{
	width = w;
	height = h;
	visible = true;
	bounds = new BoundingBox(0, w, 0, h);
}

void Brick::render()
{
	if(visible)
	{
		glBegin(GL_QUADS);
			glColor3f(1.f, 0.f, 0.f);
			glVertex3f(0.f ,0.f , 0.f);
			glColor3f(0.f, 1.f, 0.f);
			glVertex3f(0.f ,height, 0.f);
			glColor3f(0.f, 0.f, 1.f);
			glVertex3f(width, height , 0.f);
			glColor3f(1.f, 0.f, 1.f);
			glVertex3f(width, 0.f , 0.f);
		glEnd();
	}
}

void Brick::update(float dt)
{
	
}

void Brick::collision()
{
	std::cout << "collision" << std::endl;
	visible = false;
}