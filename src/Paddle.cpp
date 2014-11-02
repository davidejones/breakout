#include "Paddle.h"

Paddle::Paddle(int w, int h)
{
	maxspeed = 10;
	vel = 1;
	dx = 0;
	dy = 0;
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
	if(left)
	{
		if(x > 0)
		{
			vel += 1;
			if(vel >= maxspeed) {
				vel = maxspeed;
			}
			x -= vel;
			bounds->minX = x;
			bounds->maxX = x + width;
		}
	} else if(right) {
		if(x < 600 - width)
		{
			vel += 1;
			if(vel >= maxspeed) {
				vel = maxspeed;
			}

			x += vel;
			bounds->minX = x;
			bounds->maxX = x + width;
		}
	}	
}

void Paddle::moveLeft()
{
	/*
	if(x > 0)
	{
		vel += 5;
		if(vel >= maxspeed) {
			vel = maxspeed;
		}

		x -= vel;
		bounds->minX = x;
		bounds->maxX = x + width;
	}
	*/
	left = true;
	right = false;
}

void Paddle::moveRight()
{
	/*
	if(x < 600 - width)
	{
		vel += 5;
		if(vel >= maxspeed) {
			vel = maxspeed;
		}

		x += vel;
		bounds->minX = x;
		bounds->maxX = x + width;
	}
	*/
	left = false;
	right = true;
}

void Paddle::moveStop() 
{
	left = false;
	right = false;
}