#ifndef COLLISION_H
#define COLLISION_H

#include "GameObject.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

class Collision
{
public:
	Collision(GameObject* gObj, std::string nme);
	GameObject* gameObject;
	std::string name;
};

#endif