#include "BalloonObject.h"

BalloonObject::BalloonObject(float posX, float posY, float scaleX, float scaleY, float lineX, float lineY, bool color, float speed, bool isHit)
{
	this->posX = posX;
	this->posY = posY;
	this->scaleX = scaleX;
	this->scaleY = scaleY;
	this->lineX = lineX;
	this->lineY = lineY;
	this->color = color;
	this->speed = speed;
	this->isHit = isHit;
}

BalloonObject::~BalloonObject()
{

}