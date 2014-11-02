#include "Paddle.h"

Paddle::Paddle(int w, int h)
{
	width = w;
	height = h;
	x = 300;
	y = 600 - h;
	bounds = new BoundingBox(x, x + width, y, y + height);
}

void Paddle::render()
{
	glPushMatrix();
	glTranslatef(x,y,0);

	glBegin(GL_QUADS);
		glColor3f(1.f, 0.f, 0.f);
		glVertex3f(0.f ,0.f , 0.f);
		glColor3f(0.f, 1.f, 0.f);
		glVertex3f(0.f ,height, 0.f);
		glColor3f(0.f, 0.f, 1.f);
		glVertex3f(width, height, 0.f);
		glColor3f(1.f, 0.f, 1.f);
		glVertex3f(width,0.f , 0.f);
	glEnd();

	glPopMatrix();
}

void Paddle::update(float dt)
{

}

void Paddle::moveLeft()
{
	if(x > 0)
	{
		x -= 10;
		bounds->minX = x;
		bounds->maxX = x + width;
	}
}

void Paddle::moveRight()
{
	if(x < 600 - width)
	{
		x += 10;
		bounds->minX = x;
		bounds->maxX = x + width;
	}
}