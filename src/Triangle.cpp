#include "Triangle.h"

Triangle::Triangle()
{
    
}

void Triangle::render()
{
	glPushMatrix();
	glRotatef(Rot, 0, 0, 1.0);

	glBegin(GL_TRIANGLES);
		glColor3f(1.f, 0.f, 0.f);
		glVertex3f(-0.6f, -0.4f, 0.f);
		glColor3f(0.f, 1.f, 0.f);
		glVertex3f(0.6f, -0.4f, 0.f);
		glColor3f(0.f, 0.f, 1.f);
		glVertex3f(0.f, 0.6f, 0.f);
	glEnd();

	glPopMatrix();
}

void Triangle::update(float dt)
{
	Rot += 1;
}