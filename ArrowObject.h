#pragma once
#include "GameObjects.h"

class ArrowObject : public GameObjects
{
public:
	ArrowObject(float headX, float headY, float tailX, float tailY, bool moving);
	~ArrowObject();

	float headX;
	float headY;
	float tailX;
	float tailY;
	bool moving;

	void foo() {

	}
};