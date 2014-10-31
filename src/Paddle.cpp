#include "Paddle.h"

Paddle::Paddle()
{
	posX = 0;
}

void Paddle::render()
{
	float w = 0.5f;
	float h = 0.1f;

	glPushMatrix();
	glTranslatef(posX,0,0);

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
	posX -= 0.2;
}

void Paddle::moveRight()
{
	posX += 0.2;
}