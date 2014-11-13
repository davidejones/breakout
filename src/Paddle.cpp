#include "Paddle.h"

using namespace std;

Paddle::Paddle(int w, int h): GameObject() {
	maxspeed = 10;
	vel = 1;
	dx = 0;
	dy = 0;
	width = w;
	height = h;
	x = 300;
	y = 600 - h;
	GameObject::bounds.minX = x;
	GameObject::bounds.maxX = x + width;
	GameObject::bounds.minY = y;
	GameObject::bounds.maxY = y + height;
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
	if(left)
	{
		if(x > 0)
		{
			vel += 1;
			if(vel >= maxspeed) {
				vel = maxspeed;
			}
			x -= vel;
			GameObject::bounds.minX = x;
			GameObject::bounds.maxX = x + width;
		}
	} else if(right) {
		if(x < 600 - width)
		{
			vel += 1;
			if(vel >= maxspeed) {
				vel = maxspeed;
			}

			x += vel;
			GameObject::bounds.minX = x;
			GameObject::bounds.maxX = x + width;
		}
	}	
}

void Paddle::moveLeft()
{
	left = true;
	right = false;
}

void Paddle::moveRight()
{
	left = false;
	right = true;
}

void Paddle::moveStop() 
{
	left = false;
	right = false;
}

void Paddle::OnCollisionEnter2D(Collision collision)
{
	//cout << "paddle collision" << endl;
}