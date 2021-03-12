#pragma once
#include "GameObjects.h"

class PowerBarObject : public GameObjects
{
public:
	PowerBarObject(float posX, float posY, float scaleX, float scaleY);
	~PowerBarObject();

	float posX;
	float posY;
	float scaleX;
	float scaleY;

	void foo() {

	}
};