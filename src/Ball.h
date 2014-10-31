#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>

class Ball
{
private:
	double ballXSpeed;
	double ballYSpeed;
	double x,y;
	float angle;
	void drawCircle(float cx, float cy, float r, int num_segments);
	void filledCircle();
public:
	Ball();
	void render();
	void update(float dt);
};