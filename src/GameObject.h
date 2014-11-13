#ifndef GAMEOBJ_H
#define GAMEOBJ_H

#include "BoundingBox.h"
//#include "Collision.h"
#include <GLFW/glfw3.h>
#include <iostream>

class GameObject
{
public:
	GameObject() { /* insert code here */ };
	//virtual void render() { /* insert code here */ };
	//virtual void update(float dt) { /* insert code here */ };
	//void OnCollisionEnter2D(Collision collision);
	//void OnCollisionExit2D(Collision collision);
	//void OnCollisionStay2D(Collision collision);
	BoundingBox bounds;
};

#endif