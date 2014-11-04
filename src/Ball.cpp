#include "Ball.h"

Ball::Ball()
{
	speedIncrement = 50;
	maxSpeed = 1000;
	direction.X = 1;
	direction.Y = 1;
	position.X = 600 * 0.5;
	position.Y = 600 * 0.5;
	speed = 250;
    bounds = new BoundingBox(position.X, 10, position.Y, 10);
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
		//ballYSpeed *= -1;
		std::cout << "Life Lost.." << std::endl;

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
	bounds->minX = position.X;
	bounds->maxX = position.X + 10;
	bounds->minY = position.Y;
	bounds->maxY = position.Y + 10;
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

void Ball::paddleCollision(Paddle paddle)
{
	direction.Y = -direction.Y;
    position.Y = paddle.bounds->minY - 10;

    //direction.X = ((float)Bounds.Center.X - paddle.Bounds.Center.X) / (paddle.Bounds.Width / 2);
    direction.X = ( position.X + 10 - (paddle.bounds->minX + (90/2)) ) / (90/2);   
    direction = direction.Normalize();

    // Increase the speed when the ball is hit
    speed += speedIncrement;
    speed = fmin(speed, maxSpeed);
}

void Ball::brickCollision()
{
	direction.Y = -direction.Y;
}