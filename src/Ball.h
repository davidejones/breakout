#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>
#include "BoundingBox.h"
#include "Paddle.h"
#include "Vector2.h"

class Ball
{
private:
	Vector2 direction, position;
	int speed, maxSpeed, speedIncrement;
	void drawCircle(float cx, float cy, float r, int num_segments);
	void filledCircle();
public:
	BoundingBox *bounds;
	Ball();
	void render();
	void update(float dt);
	void brickCollision();
	void paddleCollision(Paddle paddle);
};