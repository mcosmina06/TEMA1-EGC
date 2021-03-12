#pragma once
#include "GameObjects.h"

class BowObject : public GameObjects
{
public:
	BowObject(float posX, float posY, float scaleX, float scaleY);
	~BowObject();

	float posX;
	float posY;
	float scaleX;
	float scaleY;

	void foo() {

	}
};

