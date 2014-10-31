#include "Paddle.h"

Paddle::Paddle()
{
	posX = 0;
	posY = -1;
}

void Paddle::render()
{
	float w = 0.4f;
	float h = 0.05f;

	glPushMatrix();
	glTranslatef(posX,posY,0);

	glBegin(GL_QUADS);
		glColor3f(1.f, 0.f, 0.f);
		glVertex3f(0.f ,0.f , 0.f);
		glColor3f(0.f, 1.f, 0.f);
		glVertex3f(0.f ,h , 0.f);
		glColor3f(0.f, 0.f, 1.f);
		glVertex3f(w ,h , 0.f);
		glColor3f(1.f, 0.f, 1.f);
		glVertex3f(w ,0.f , 0.f);
	glEnd();

	glPopMatrix();
}

void Paddle::update(float dt)
{
	
}

void Paddle::moveLeft()
{
	if(posX*600 > -600)
	{
		posX -= 0.2;
	}
}

void Paddle::moveRight()
{
	if(posX*600 < 600 - 0.4*600)
	{
		posX += 0.2;
	}
}