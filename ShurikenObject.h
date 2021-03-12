#pragma once
#include "GameObjects.h"

class ShurikenObject : public GameObjects
{
public:
	ShurikenObject(float posX, float posY, float scaleX, float scaleY, float speed, bool isHit);
	~ShurikenObject();

	float posX;
	float posY;
	float scaleX;
	float scaleY;
	float speed;
	bool isHit;

	void foo() {

	}
};
