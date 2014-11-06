#include "Ball.h"

using namespace std;

Ball::Ball()
{
	speedIncrement = 50;
	maxSpeed = 1000;
	direction.X = 1;
	direction.Y = 1;
	position.X = 600 * 0.5;
	position.Y = 600 * 0.5;
	speed = 300;
    bounds.minX = position.X;
    bounds.maxX = 10;
    bounds.minY = position.Y;
    bounds.maxY = 10;
}

void Ball::render()
{
	glPushMatrix();
	glTranslated(position.X, position.Y, 0);
	filledCircle();
	glPopMatrix();
}

void Ball::update(float dt)
{
	position.X = position.X + direction.X * (speed * dt);
	position.Y = position.Y + direction.Y * (speed * dt);

	//if ball hits right side
	if(position.X >= 600)
	{
		direction.X *= -1;
	}

	//if ball hits left side
	if(position.X <= 0)
	{
		direction.X *= -1;
	}

	//if ball hits the bottom
	if(position.Y >= 600)
	{
		cout << "Life Lost.." << endl;

		//reset variables and ballpos
		speed = 250;
		position.X = 600 * 0.5;
    	position.Y = 600 * 0.5;
	}

	//if ball hits the top
	if(position.Y <= 0)
	{
		direction.Y *= -1;
	}

	//update bounding box
	bounds.minX = position.X;
	bounds.maxX = position.X + 10;
	bounds.minY = position.Y;
	bounds.maxY = position.Y + 10;
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


void Ball::doPaddleCollision(BoundingBox paddlebounds)
{
	direction.Y = -direction.Y;
    position.Y = paddlebounds.minY - 10;

    //direction.X = ((float)Bounds.Center.X - paddle.Bounds.Center.X) / (paddle.Bounds.Width / 2);
    direction.X = ( position.X + 10 - (paddlebounds.minX + (90/2)) ) / (90/2);   
    direction = direction.Normalize();

    // Increase the speed when the ball is hit
    speed += speedIncrement;
    speed = fmin(speed, maxSpeed);

    //update bounding box
	bounds.minX = position.X;
	bounds.maxX = position.X + 10;
	bounds.minY = position.Y;
	bounds.maxY = position.Y + 10;
}

void Ball::doBrickCollision(Brick *brick)
{
	//direction.Y = -direction.Y;
	//so determine which side of the brick we hit then reflect away

	if((bounds.maxX-5) <= brick->bounds->minX) {
		//cout << "left" << endl;
		position.X = brick->bounds->minX - 5;
		direction.X = -direction.X;
	}

	if((bounds.minX+5) >= (brick->bounds->maxX)) {
		//cout << "right" << endl;
		position.X = brick->bounds->maxX + 5;
		direction.X = -direction.X;
	}

	if((bounds.minY-5) <= brick->bounds->minY) {
		//cout << "top" << endl;
		position.Y = brick->bounds->minY - 5;
		direction.Y = -direction.Y;
	}

	if((bounds.minY+5) >= (brick->bounds->maxY)) {
		//cout << "bottom" << endl;
		position.Y = brick->bounds->maxY + 5;
		direction.Y = -direction.Y;
	}

}