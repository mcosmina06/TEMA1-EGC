#pragma once
#include "GameObjects.h"

class BalloonObject : public GameObjects
{
public:
	BalloonObject(float posX, float posY, float scaleX, float scaleY, float lineX, float lineY, bool color, float speed, bool isHit);
	~BalloonObject();

	float posX;
	float posY;
	float scaleX;
	float scaleY;
	float lineX;
	float lineY;
	bool color;
	float speed;
	bool isHit;

	void foo() {

	}
};