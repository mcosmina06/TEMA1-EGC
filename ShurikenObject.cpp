#include "ShurikenObject.h"

ShurikenObject::ShurikenObject(float posX, float posY, float scaleX, float scaleY, float speed, bool isHit)
{
	this->posX = posX;
	this->posY = posY;
	this->scaleX = scaleX;
	this->scaleY = scaleY;
	this->speed = speed;
	this->isHit = isHit;
}

ShurikenObject::~ShurikenObject()
{

}