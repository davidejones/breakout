#include "Brick.h"

Brick::Brick(int w, int h, int xpos, int ypos, unsigned int color)
{
	//split color
	R = color >> 16;
	G = color >> 8 & 0xFF;
	B = color & 0xFF;
	width = w;
	height = h;
	x = xpos;
	y = ypos;
	visible = true;
	bounds = new BoundingBox(x, x+w, y, y+h);
}

void Brick::render()
{
	if(visible)
	{
		glPushMatrix();
		glTranslatef(x,y,0);
		glBegin(GL_QUADS);
			glColor3f((double)R/255,(double)G/255,(double)B/255);
			//glColor3f(1.f, 0.f, 0.f);
			glVertex3f(0.f ,0.f , 0.f);
			//glColor3f(0.f, 1.f, 0.f);
			glVertex3f(0.f ,height, 0.f);
			//glColor3f(0.f, 0.f, 1.f);
			glVertex3f(width, height , 0.f);
			//glColor3f(1.f, 0.f, 1.f);
			glVertex3f(width, 0.f , 0.f);
		glEnd();
		glPopMatrix();
	}
}

void Brick::update(float dt)
{
	
}

void Brick::collision()
{
	visible = false;
}