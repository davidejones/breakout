#include "Ball.h"

Ball::Ball()
{
    ballXSpeed = 5;
    ballYSpeed = 5;
    x = 0;
    y = 0;
    angle = 0;

    //starting ball position center of window
    x = 600 * 0.5;
    y = 600 * 0.5;

    bounds = new BoundingBox(x, 10, y, 10);
}

void Ball::render()
{
	//drawCircle(0.5, 0.5, 0.2, 20);
	glPushMatrix();
    //glRotatef(angle, 0, 0.5, 1);
    //glTranslatef(x, y, 0);
    glTranslated(x, y, 0);
	filledCircle();
	glPopMatrix();
}

void Ball::update(float dt)
{
	x = x + ballXSpeed;
	y = y + ballYSpeed;

	//std::cout << x << std::endl;
	//std::cout << y << std::endl;

	//if ball hits right side
	if(x >= 600)
	{
		ballXSpeed *= -1;
	}

	//if ball hits left side
	if(x <= 0)
	{
		ballXSpeed *= -1;
	}

	//if ball hits the bottom
	if(y >= 600)
	{
		ballYSpeed *= -1;
	}

	//if ball hits the top
	if(y <= 0)
	{
		ballYSpeed *= -1;
	}

	//update bounding box
	bounds->minX = x;
	bounds->maxX = x + 10;
	bounds->minY = y;
	bounds->maxY = y + 10;
}

void Ball::drawCircle(float cx, float cy, float r, int num_segments)
{
    glBegin(GL_LINE_LOOP);
    for(int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component

        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(x + cx, y + cy);//output vertex

    }
    glEnd();
}

void Ball::filledCircle()
{
	float x1,y1,x2,y2;
	float angle;
	double radius=10;

	x1=0,y1=0;
	glColor3f(0.0,0.0,1.0);

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x1,y1);

	for (angle=1.0f;angle<361.0f;angle+=0.2)
	{
		x2 = x1+sin(angle)*radius;
		y2 = y1+cos(angle)*radius;
		glVertex2f(x2,y2);
	}

	glEnd();
} 