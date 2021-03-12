#include "ArrowObject.h"

ArrowObject::ArrowObject(float headX, float headY, float tailX, float tailY, bool moving)
{
	this->headX = headX;
	this->headY = headY;
	this->tailX = tailX;
	this->tailY = tailY;
	this->moving = moving;
}

ArrowObject::~ArrowObject()
{

}