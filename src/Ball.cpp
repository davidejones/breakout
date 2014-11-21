#include "Ball.h"

using namespace std;

Ball::Ball(GameSound* gSnd): GameObject() {
	this->gameSound = gSnd;
	speedIncrement = 0.1;
	maxSpeed = 1000;
	direction.X = 0;
	direction.Y = 1;
	position.X = 2048 * 0.5;
	position.Y = 1536 * 0.5;
	speed = 1; // pixels per second
	ballwidth = 2048/120;
    GameObject::bounds.minX = position.X - ballwidth;
	GameObject::bounds.maxX = position.X + ballwidth;
	GameObject::bounds.minY = position.Y - ballwidth;
	GameObject::bounds.maxY = position.Y + ballwidth;
	doFading = true;
	fadeIn = true;
	fadeOut = false;
	fadecount = 0;
}

void Ball::reset()
{
	//reset variables and ballpos
	speed = 1;
	direction.X = 0;
	direction.Y = 1;
	position.X = 2048 * 0.5;
	position.Y = 1536 * 0.5;
	//update bounding box
	GameObject::bounds.minX = position.X - ballwidth;
	GameObject::bounds.maxX = position.X + ballwidth;
	GameObject::bounds.minY = position.Y - ballwidth;
	GameObject::bounds.maxY = position.Y + ballwidth;
	alpha = 1.0f;
	doFading = true;
	fadeIn = true;
	fadeOut = false;
	fadecount = 0;
}

void Ball::waitMode()
{

}

void Ball::render()
{
	if(doFading) {

		if(fadeIn)
		{
			alpha += 0.1f;
			if(alpha >= 1.0f) {
				fadeIn = false;
				fadeOut = true;
			}
		} else if(fadeOut) {
			alpha -= 0.1f;
			if(alpha <= 0.0f)
			{
				fadeIn = true;
				fadeOut = false;
				fadecount++;
			}
		}

	} else {
		alpha = 1.0f;
	}

	glPushMatrix();
	glTranslated(position.X, position.Y, 0);
	//filledCircle();
	drawCircle(-1, 0, ballwidth, 20);
	glPopMatrix();
}

void Ball::update()
{
	if(fadecount >= 5) {
		doFading = false;
		fadeIn = false;
		fadeOut = false;
		fadecount = 0;
	}

	if(!doFading)
	{
		position.X += direction.X * speed;
		position.Y += direction.Y * speed;

		//update bounding box
		GameObject::bounds.minX = position.X - ballwidth;
		GameObject::bounds.maxX = position.X + ballwidth;
		GameObject::bounds.minY = position.Y - ballwidth;
		GameObject::bounds.maxY = position.Y + ballwidth;

		//if ball hits right side
		if(GameObject::bounds.maxX >= 2048)
		{
			gameSound->playSoundEffect("paddlehit");
			direction.X *= -1;
		}

		//if ball hits left side
		if(GameObject::bounds.minX <= 0)
		{
			gameSound->playSoundEffect("paddlehit");
			direction.X *= -1;
		}

		//if ball hits the bottom
		if(GameObject::bounds.maxY >= 1536)
		{
			//cout << "Life Lost.." << endl;
			gameSound->playSoundEffect("lostlife");
			reset();
		}

		//if ball hits the top
		if(GameObject::bounds.minY <= 0)
		{
			gameSound->playSoundEffect("paddlehit");
			direction.Y *= -1;
		}
		// check collision
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

        //glColor3f(0.0f, 0.0f, 1.0f);
        glColor4f (0.0f, 0.0f, 1.0f, alpha);
        glVertex2f(x + cx, y + cy);//output vertex

    }
    glEnd();
}

void Ball::OnCollisionEnter2D(Collision collision)
{
	//if gameobject is paddle
	if(collision.name == "paddle")
	{
		int paddlewidth = 2048/10;
		int paddleheight = 1536/60;

		direction.Y = -direction.Y;
	    position.Y = collision.gameObject->bounds.minY - ballwidth * 2;

	    //direction.X = ((float)Bounds.Center.X - paddle.Bounds.Center.X) / (paddle.Bounds.Width / 2);
	    direction.X = ( position.X + ballwidth - (collision.gameObject->bounds.minX + (paddlewidth/2)) ) / (paddlewidth/2);   
	    direction = direction.Normalize();

	    // Increase the speed when the ball is hit
	    speed += speedIncrement;
	    speed = fmin(speed, maxSpeed);

	    //update bounding box
		GameObject::bounds.minX = position.X - ballwidth;
		GameObject::bounds.maxX = position.X + ballwidth;
		GameObject::bounds.minY = position.Y - ballwidth;
		GameObject::bounds.maxY = position.Y + ballwidth;

	} else if(collision.name == "brick") {

		if(GameObject::bounds.maxX <= collision.gameObject->bounds.minX) {
			//cout << "left" << endl;
			position.X = collision.gameObject->bounds.minX - ballwidth * 2;
			direction.X = -direction.X;
		}
		if(GameObject::bounds.minX >= collision.gameObject->bounds.maxX) {
			//cout << "right" << endl;
			position.X = collision.gameObject->bounds.maxX + ballwidth * 2;
			direction.X = -direction.X;
		}
		//if less than center point and less than the miny
		if(GameObject::bounds.maxY <= collision.gameObject->bounds.minY) {
			//cout << "top" << endl;
			position.Y = collision.gameObject->bounds.minY - ballwidth * 2;
			direction.Y = -direction.Y;
		}
		//if greater than center point but less than maxy - brick size 80/20 w/h
		if(GameObject::bounds.minY >= collision.gameObject->bounds.maxY) {
			//cout << "bottom" << endl;
			position.Y = collision.gameObject->bounds.maxY + ballwidth * 2;
			direction.Y = -direction.Y;
		}
		
	}
}