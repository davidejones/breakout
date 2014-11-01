#include "Paddle.h"

Paddle::Paddle(int w, int h)
{
	width = w;
	height = h;
	bounds = new BoundingBox(0, w, 0, h);
	posX = 300;
	posY = 600 - h;
}

void Paddle::render()
{
	glPushMatrix();
	glTranslatef(posX,posY,0);

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
	if(posX > 0)
	{
		posX -= 10;
	}
}

void Paddle::moveRight()
{
	if(posX < 600 - 90)
	{
		posX += 10;
	}
}