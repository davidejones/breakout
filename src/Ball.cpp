#include "Ball.h"

using namespace std;

Ball::Ball(): GameObject() {
	speedIncrement = 50;
	maxSpeed = 1000;
	direction.X = 1;
	direction.Y = 1;
	position.X = 1920 * 0.5;
	position.Y = 1080 * 0.5;
	speed = 300.0f; // pixels per second
    GameObject::bounds.minX = position.X - 10;
	GameObject::bounds.maxX = position.X + 10;
	GameObject::bounds.minY = position.Y - 10;
	GameObject::bounds.maxY = position.Y + 10;
	iterationsPerFrame = 10;
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
	GameObject::bounds.minX = position.X - 10;
	GameObject::bounds.maxX = position.X + 10;
	GameObject::bounds.minY = position.Y - 10;
	GameObject::bounds.maxY = position.Y + 10;

	//if ball hits right side
	if(GameObject::bounds.maxX >= 1920)
	{
		direction.X *= -1;
	}

	//if ball hits left side
	if(GameObject::bounds.minX <= 0)
	{
		direction.X *= -1;
	}

	//if ball hits the bottom
	if(GameObject::bounds.maxY >= 1080)
	{
		cout << "Life Lost.." << endl;

		//reset variables and ballpos
		//speed = 100.0f;
		direction.X = 1;
		direction.Y = 1;
		position.X = 1920 * 0.5;
		position.Y = 1080 * 0.5;
	}

	//if ball hits the top
	if(GameObject::bounds.minY <= 0)
	{
		direction.Y *= -1;
	}

	// check collision
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

void Ball::OnCollisionEnter2D(Collision collision)
{
	//if gameobject is paddle
	if(collision.name == "paddle")
	{
		direction.Y = -direction.Y;
	    position.Y = collision.gameObject->bounds.minY - 10;

	    //direction.X = ((float)Bounds.Center.X - paddle.Bounds.Center.X) / (paddle.Bounds.Width / 2);
	    direction.X = ( position.X + 10 - (collision.gameObject->bounds.minX + (90/2)) ) / (90/2);   
	    direction = direction.Normalize();

	    // Increase the speed when the ball is hit
	    //speed += speedIncrement;
	    //speed = fmin(speed, maxSpeed);

	    //update bounding box
		GameObject::bounds.minX = position.X - 10;
		GameObject::bounds.maxX = position.X + 10;
		GameObject::bounds.minY = position.Y - 10;
		GameObject::bounds.maxY = position.Y + 10;

	} else if(collision.name == "brick") {

		if(GameObject::bounds.maxX <= collision.gameObject->bounds.minX) {
			//cout << "left" << endl;
			position.X = collision.gameObject->bounds.minX - 11;
			direction.X = -direction.X;
		}
		if(GameObject::bounds.minX >= collision.gameObject->bounds.maxX) {
			//cout << "right" << endl;
			position.X = collision.gameObject->bounds.maxX + 11;
			direction.X = -direction.X;
		}
		//if less than center point and less than the miny
		if(GameObject::bounds.maxY <= collision.gameObject->bounds.minY) {
			//cout << "top" << endl;
			position.Y = collision.gameObject->bounds.minY - 11;
			direction.Y = -direction.Y;
		}
		//if greater than center point but less than maxy - brick size 80/20 w/h
		if(GameObject::bounds.minY >= collision.gameObject->bounds.maxY) {
			//cout << "bottom" << endl;
			position.Y = collision.gameObject->bounds.maxY + 11;
			direction.Y = -direction.Y;
		}
		
	}
}