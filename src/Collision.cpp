#include "Collision.h"

using namespace std;

Collision::Collision(GameObject* gObj, string nme, GameSound* gSnd)
{
    this->gameObject = gObj;
    this->gameSound = gSnd;
    this->name = nme;
}