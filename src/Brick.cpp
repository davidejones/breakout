#include "Brick.h"

Brick::Brick()
{

}

void Brick::render()
{
	float w = 0.3f;
	float h = 0.1f;

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
}

void Brick::update(float dt)
{
	
}