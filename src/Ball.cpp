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
	speed = 100.0f; // pixels per second
    bounds.minX = position.X - 10;
	bounds.maxX = position.X + 10;
	bounds.minY = position.Y - 10;
	bounds.maxY = position.Y + 10;
}

void Ball::render()
{
	glPushMatrix();
	glTranslated(position.X, position.Y, 0);
	//filledCircle();
	drawCircle(-1, 0, 10, 20);
	glPopMatrix();
}

void Ball::update(float dt)
{
	position.X += direction.X * speed * dt;
	position.Y += direction.Y * speed * dt;

	//update bounding box
	bounds.minX = position.X - 10;
	bounds.maxX = position.X + 10;
	bounds.minY = position.Y - 10;
	bounds.maxY = position.Y + 10;

	//if ball hits right side
	if(bounds.maxX >= 600)
	{
		direction.X *= -1;
	}

	//if ball hits left side
	if(bounds.minX <= 0)
	{
		direction.X *= -1;
	}

	//if ball hits the bottom
	if(bounds.maxY >= 600)
	{
		cout << "Life Lost.." << endl;

		//reset variables and ballpos
		speed = 100.0f;
		direction.X = 1;
		direction.Y = 1;
		position.X = 600 * 0.5;
    	position.Y = 600 * 0.5;
	}

	//if ball hits the top
	if(bounds.minY <= 0)
	{
		direction.Y *= -1;
	}
}

void Ball::drawCircle(float cx, float cy, float r, int num_segments)
{
    //glBegin(GL_LINE_LOOP);
    glBegin(GL_TRIANGLE_FAN);
    for(int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component

        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(x + cx, y + cy);//output vertex

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
	bounds.minX = position.X - 10;
	bounds.maxX = position.X + 10;
	bounds.minY = position.Y - 10;
	bounds.maxY = position.Y + 10;
}

void Ball::doBrickCollision(Brick *brick)
{
	//direction.Y = -direction.Y;
	//so determine which side of the brick we hit then reflect away

	//cout << direction.X << " " << direction.Y << endl;
	
	if(bounds.maxX < (brick->bounds->minX + 40) && bounds.maxX >= brick->bounds->minX) {
		cout << "left" << endl;
		position.X = bounds.minX-10;
		//direction.X = -direction.X;
	}

	if(bounds.minX > (brick->bounds->maxX - 40) && bounds.minX <= brick->bounds->maxX) {
		cout << "right" << endl;
		position.X = bounds.maxX-10;
		//direction.X = -direction.X;
	}

	//if less than center point and less than the miny 
	if(bounds.minY < (brick->bounds->minY + 10) && bounds.minY >= brick->bounds->minY) {
		cout << "top" << endl;
		position.Y = brick->bounds->minY-5;
		direction.Y = -direction.Y;
	}

	//if greater than center point but less than maxy - brick size 80/20 w/h
	if(bounds.minY > (brick->bounds->maxY - 10) && bounds.minY <= brick->bounds->maxY) {
		cout << "bottom" << endl;
		position.Y = brick->bounds->maxY+5;
		direction.Y = -direction.Y;
	}
}