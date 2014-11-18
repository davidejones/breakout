#include "Brick.h"

using namespace std;

Brick::Brick(int w, int h, int xpos, int ypos, unsigned int color, bool visibility): GameObject() {
	//split color
	R = color >> 16;
	G = color >> 8 & 0xFF;
	B = color & 0xFF;
	width = w;
	height = h;
	x = xpos;
	y = ypos;
	visible = visibility;
	GameObject::bounds.minX = x;
	GameObject::bounds.maxX = x+w;
	GameObject::bounds.minY = y;
	GameObject::bounds.maxY = y+h;
	//bounds = new BoundingBox(x, x+w, y, y+h);
}

void Brick::render()
{
	if(visible)
	{
		glPushMatrix();
		glTranslatef(x,y,0);
		glBegin(GL_QUADS);
			glColor3f((double)R/255,(double)G/255,(double)B/255);
			glVertex3f(0.f ,0.f , 0.f);
			glVertex3f(0.f ,height, 0.f);			
			glVertex3f(width, height , 0.f);
			glVertex3f(width, 0.f , 0.f);
		glEnd();
		glPopMatrix();
	}
}

void Brick::update(float dt)
{
	if(visible)
	{
		GameObject::bounds.minX = x;
		GameObject::bounds.maxX = x+width;
		GameObject::bounds.minY = y;
		GameObject::bounds.maxY = y+height;
	}
}

void Brick::OnCollisionEnter2D(Collision collision)
{
	if(collision.name == "ball")
	{
		visible = false;
		collision.gameSound->playSoundEffect("brickbreak");
	}
}