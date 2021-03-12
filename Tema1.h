#pragma once

#include <Component/SimpleScene.h>
#include <string>
#include <math.h>
#include <chrono>
#include <Core/Engine.h>
#include "GameObjects.h"
#include "BowObject.h"
#include "ArrowObject.h"
#include "ShurikenObject.h"
#include "BalloonObject.h"
#include "ScoreBarObject.h"
#include "LifeObject.h"
#include "PowerBarObject.h"

class Tema1 : public SimpleScene
{
	public:
		Tema1();
		~Tema1();

		void Init() override;

	private:
		void FrameStart() override;
		void Update(float deltaTimeSeconds) override;
		void FrameEnd() override;

		void initGame();
		void initLevel2();
		void createMeshes();
		void updateObjects(float deltaTimeSeconds);
		void renderScoreBar(ScoreBarObject* score);
		void renderPowerBar(PowerBarObject* power);
		void renderBow(BowObject* bow);
		void renderArrow(ArrowObject* arrow);
		void renderTriangleShuriken(ShurikenObject* shuriken, float angularStep, int rad);
		void renderShuriken(ShurikenObject* shuriken, float deltaTimeSeconds);
		void renderBalloon(BalloonObject* balloon);
		void renderLife(LifeObject* life);
		void checkCollision(ArrowObject* arrow, BowObject* bow);

		void OnInputUpdate(float deltaTime, int mods) override;
		void OnKeyPress(int key, int mods) override;
		void OnKeyRelease(int key, int mods) override;
		void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
		void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
		void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
		void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
		void OnWindowResize(int width, int height) override;

	protected:
		glm::mat3 modelMatrix;
		std::vector<GameObjects*> gameObjects;
		std::vector<LifeObject*> lifeObjects;

		float translateXShuriken;
		float translateYBalloon;
		float translateBow;
		float translatePowerBar;
		float scaleX, scaleY;
		float angularStep;
		float angularStepArrow;
		int lifes;
		int mouse_X;
		int mouse_Y;
		int score = 0; //10p - balon rosu, -10p balon galben, +15p shuriken
		int current_score = 0;
		int cnt = 0;
		int speedHold = 0;
		bool is_pressed = false;
		bool W_pressed = false;
		bool S_pressed = false;

};
