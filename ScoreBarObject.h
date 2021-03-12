#pragma once
#include "GameObjects.h"

class ScoreBarObject : public GameObjects
{
public:
	ScoreBarObject(float posX, float posY, float scaleX, float scaleY);
	~ScoreBarObject();

	float posX;
	float posY;
	float scaleX;
	float scaleY;

	void foo() {

	}
};