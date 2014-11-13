#include "Collision.h"

using namespace std;

Collision::Collision(GameObject* gObj, string nme)
{
    this->gameObject = gObj;
    this->name = nme;
}