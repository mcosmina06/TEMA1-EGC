#pragma once
#include "GameObjects.h"

class LifeObject : public GameObjects
{
public:
	LifeObject(float posX, float posY);
	~LifeObject();

	float posX;
	float posY;

	void foo() {

	}
};