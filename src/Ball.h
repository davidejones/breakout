#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>
#include "BoundingBox.h"

class Ball
{
private:
	int ballXSpeed;
	int ballYSpeed;
	float angle;
	void drawCircle(float cx, float cy, float r, int num_segments);
	void filledCircle();
public:
	int x,y;
	BoundingBox *bounds;
	Ball();
	void render();
	void update(float dt);
};