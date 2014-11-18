#include "Paddle.h"

using namespace std;

Paddle::Paddle(int w, int h): GameObject() {
	maxspeed = 10;
	vel = 1;
	dx = 0;
	dy = 0;
	width = w;
	height = h;

	//overwrite here for time being
	width = 2048/10;
	height = 1536/60;

	x = 2048/2;
	y = 1536 - height;
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
		if(x < 2048 - width)
		{
			vel += 1;
			if(vel >= maxspeed) {
				vel = maxspeed;
			}

			x += vel;
			GameObject::bounds.minX = x;
			GameObject::bounds.maxX = x + width;
		}
	} else {

		if(x >= 2048 - width)
		{
			x = 2048 - width;
		}

		if(x < 0)
		{
			x = 0;
		}

		GameObject::bounds.minX = x;
		GameObject::bounds.maxX = x + width;
		
	}
}

void Paddle::OnCollisionEnter2D(Collision collision)
{
	collision.gameSound->playSoundEffect("paddlehit");
	//cout << "paddle collision" << endl;
}

void Paddle::onNotify(string eventname)
{
	if(eventname == "KEY_LEFT_DOWN")
	{
		left = true;
		right = false;
	}

	if(eventname == "JOYSTICK_LEFT_DOWN")
	{
		x -= 10;
		GameObject::bounds.minX = x;
		GameObject::bounds.maxX = x + width;
	}

	if(eventname == "KEY_RIGHT_DOWN")
	{
		left = false;
		right = true;
	}

	if(eventname == "JOYSTICK_RIGHT_DOWN")
	{
		x += 10;
		GameObject::bounds.minX = x;
		GameObject::bounds.maxX = x + width;
	}

	if(eventname == "KEY_LEFT_UP" || eventname == "KEY_RIGHT_UP" || eventname == "RELEASE")
	{
		left = false;
		right = false;
	}
}