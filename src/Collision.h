#ifndef COLLISION_H
#define COLLISION_H

#include "GameObject.h"
#include "GameSound.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

class Collision
{
public:
	Collision(GameObject* gObj, std::string nme, GameSound* gSnd);
	GameObject* gameObject;
	GameSound* gameSound;
	std::string name;
};

#endif