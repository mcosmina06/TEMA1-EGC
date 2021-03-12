#include "Tema1.h"

#include <vector>
#include <iostream>

#include <Core/Engine.h>
#include "Transform2D.h"
#include "Object2D.h"

using namespace std;

Tema1::Tema1()
{
}

Tema1::~Tema1()
{
}

void Tema1 :: createMeshes() {

	glm::vec3 corner = glm::vec3(0, 0, 0);
	float squareSide = 100;
	float cx = corner.x + squareSide / 2;
	float cy = corner.y + squareSide / 2;

	Mesh* semicircle = Object2D::CreateSemiCircle("semicircle", glm::vec3(0, 0, 0), 10.0f, glm::vec3(0.6f, 0.25f, 0));
	AddMeshToList(semicircle);

	Mesh* triangle = Object2D::CreateTriangle("triangle", corner, 10, glm::vec3(0, 0, 1), true);
	AddMeshToList(triangle);

	Mesh* triangle_grey = Object2D::CreateTriangle("triangle_grey", corner, 10, glm::vec3(0.5, 0.5, 0.5), true);
	AddMeshToList(triangle_grey);

	Mesh* arrow = Object2D::CreateTriangleArrow("arrow", corner, squareSide, glm::vec3(0.6f, 0.25f, 0), true);
	AddMeshToList(arrow);

	Mesh* score = Object2D::CreateRectangle("score", corner, 5, 10, glm::vec3(0, 1, 0), true);
	AddMeshToList(score);

	Mesh* power_bar = Object2D::CreateRectangle("power_bar", corner, 1, 10, glm::vec3(0, 1, 0), true);
	AddMeshToList(power_bar);

	Mesh* rectangle = Object2D::CreateRectangle("rectangle", corner, squareSide, 20, glm::vec3(0.6f, 0.25f, 0), true);
	AddMeshToList(rectangle);

	Mesh* line_red = Object2D::CreateLine("line_red", corner, 20, glm::vec3(1, 0, 0));
	AddMeshToList(line_red);

	Mesh* line_yellow = Object2D::CreateLine("line_yellow", corner, 20, glm::vec3(1, 1, 0));
	AddMeshToList(line_yellow);

	Mesh* circle_red = Object2D::CreateCircle("circle_red", glm::vec3(0, 0, 0), 10.0f, glm::vec3(1, 0, 0));
	AddMeshToList(circle_red);

	Mesh* circle_yellow = Object2D::CreateCircle("circle_yellow", glm::vec3(0, 0, 0), 10.0f, glm::vec3(1, 1, 0), true);
	AddMeshToList(circle_yellow);

	Mesh* life = Object2D::CreateLife("life", glm::vec3(0, 0, 0), 5, glm::vec3(1, 0, 0), false);
	AddMeshToList(life);
}

void Tema1::initGame() {
	lifes = 3;
	gameObjects.clear();
	lifeObjects.clear();
	
	//adding lifes
	lifeObjects.push_back(new LifeObject(15, 670));
	lifeObjects.push_back(new LifeObject(45, 670)); 
	lifeObjects.push_back(new LifeObject(75, 670));

	//adding bow 
	gameObjects.push_back(new BowObject(100, 360, 6, 5)); // pe poztia 0

	//adding arrow
	gameObjects.push_back(new ArrowObject(210, 360, 200, 362, false)); // pe pozitia 1

	//adding scoreBar
	gameObjects.push_back(new ScoreBarObject(5, 710, 1, 1));

	//adding powerBar
	gameObjects.push_back(new PowerBarObject(100, 280, 0, 0.5));
	
	//adding a red balloons
	gameObjects.push_back(new BalloonObject(800, 20, 2.5, 3, 800, 0, true, 20, false));
	gameObjects.push_back(new BalloonObject(1100, 20, 2.5, 3, 1100, 0, true, 25, false));
	
	//adding a yellow balloons
	gameObjects.push_back(new BalloonObject(1200, 20, 2.5, 3, 1200, 0, false, 30, false));
	gameObjects.push_back(new BalloonObject(900, 20, 2.5, 3, 900, 0, false, 15, false));
	
	//adding a shurikens
	gameObjects.push_back(new ShurikenObject(1280, 300, 2.8, 2.8, 80, false));
	gameObjects.push_back(new ShurikenObject(1280, 600, 2.5, 2.5, 60, false));
	gameObjects.push_back(new ShurikenObject(1280, 100, 2.8, 2.8, 60, false));
	gameObjects.push_back(new ShurikenObject(1280, 700, 2.9, 2.9, 75, false));
}

void Tema1::Init() {

	glm::ivec2 resolution = window->GetResolution();
	auto camera = GetSceneCamera();
	camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
	camera->SetPosition(glm::vec3(0, 0, 50));
	camera->SetRotation(glm::vec3(0, 0, 0));
	camera->Update();
	GetCameraInput()->SetActive(false);

	createMeshes();
	initGame();
	
	translateXShuriken = 0;
	translateYBalloon = 0;
	translatePowerBar = 0;
	translateBow = 0;

	scaleX = 1;
	scaleY = 1;
	
	angularStep = 0;
	angularStepArrow = 0;
}

void Tema1::initLevel2()
{
	gameObjects.push_back(new BalloonObject(1050, 20, 2.5, 3, 1050, 0, false, 25, false));
	gameObjects.push_back(new BalloonObject(1100, 20, 2.5, 3, 1100, 0, true, 50, false));
	gameObjects.push_back(new BalloonObject(1200, 20, 2.5, 3, 1200, 0, false, 30, false));
	gameObjects.push_back(new BalloonObject(980, 20, 2.5, 3, 980, 0, false, 45, false));
	gameObjects.push_back(new BalloonObject(650, 20, 2.5, 3, 650, 0, true, 15, false));
	gameObjects.push_back(new BalloonObject(750, 20, 2.5, 3, 750, 0, false, 35, false));
	
	gameObjects.push_back(new ShurikenObject(1280, 350, 2.8, 2.8, 100, false));
	gameObjects.push_back(new ShurikenObject(1280, 670, 2.5, 2.5, 60, false));
	gameObjects.push_back(new ShurikenObject(1280, 500, 2.9, 2.9, 95, false));
	gameObjects.push_back(new ShurikenObject(1280, 400, 2.5, 2.5, 95, false));
	gameObjects.push_back(new ShurikenObject(1280, 200, 3, 3, 100, false));
}

void Tema1::FrameStart()
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::ivec2 resolution = window->GetResolution();
	glViewport(0, 0, resolution.x, resolution.y);
}

void Tema1::renderLife(LifeObject* life) {
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(life->posX, life->posY);
	modelMatrix *= Transform2D::Scale(1.5, 2);
	RenderMesh2D(meshes["life"], shaders["VertexColor"], modelMatrix);
}

void Tema1::renderScoreBar(ScoreBarObject* score) {
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(score->posX, score->posY);
	modelMatrix *= Transform2D::Rotate(RADIANS(180));
	modelMatrix *= Transform2D::Scale(score->scaleX, score->scaleY);
	RenderMesh2D(meshes["score"], shaders["VertexColor"], modelMatrix);
}

void Tema1::renderPowerBar(PowerBarObject* power) {
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(power->posX, power->posY);
	modelMatrix *= Transform2D::Rotate(RADIANS(180));
	modelMatrix *= Transform2D::Scale(power->scaleX, power->scaleY);
	RenderMesh2D(meshes["power_bar"], shaders["VertexColor"], modelMatrix);
}

void Tema1::renderBow(BowObject* bow) {
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(bow->posX, bow->posY);
	modelMatrix *= Transform2D::Scale(bow->scaleX, bow->scaleY);
	RenderMesh2D(meshes["semicircle"], shaders["VertexColor"], modelMatrix);
}

//sageata este formata dintr-un triunghi si un dreptunghi
void Tema1::renderArrow(ArrowObject* arrow) {
		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Translate(arrow->headX, arrow->headY);
		modelMatrix *= Transform2D::Scale(0.5, 0.2);
		RenderMesh2D(meshes["arrow"], shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Translate(arrow->tailX, arrow->tailY);
		modelMatrix *= Transform2D::Scale(0.75, 0.2);
		RenderMesh2D(meshes["rectangle"], shaders["VertexColor"], modelMatrix);
}

// shurikenul este format din 4 trinunghiuri care se afla in aceasi pozitie dar rotite cu
// unghiuri diferite
void Tema1::renderTriangleShuriken(ShurikenObject* shuriken, float angularStep, int rad) {
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(shuriken->posX, shuriken->posY);
	modelMatrix *= Transform2D::Rotate(RADIANS(rad));
	
	// daca shurikenul nu este lovit atunci isi continua miscarea de rotatie si va avea 
	// culoarea albastra
	if (!shuriken->isHit) {
		modelMatrix *= Transform2D::Rotate(RADIANS(angularStep));
	}
	modelMatrix *= Transform2D::Scale(shuriken->scaleX, shuriken->scaleY);
	if (!shuriken->isHit) {
		RenderMesh2D(meshes["triangle"], shaders["VertexColor"], modelMatrix);
	}
	// daca a fost lovit nu se mai roteste si devine gri
	else {
		RenderMesh2D(meshes["triangle_grey"], shaders["VertexColor"], modelMatrix);
	}
	
}

// crearea celor 4 triunghiuri pentru Shuriken
void Tema1::renderShuriken(ShurikenObject* shuriken, float deltaTimeSeconds) {
	angularStep += deltaTimeSeconds * shuriken->speed;
	
	renderTriangleShuriken(shuriken, angularStep, 45);
	renderTriangleShuriken(shuriken, angularStep, 135);
	renderTriangleShuriken(shuriken, angularStep, 225);
	renderTriangleShuriken(shuriken, angularStep, 315);
}

void Tema1::renderBalloon(BalloonObject* balloon)
{
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(balloon->posX, balloon->posY);
	modelMatrix *= Transform2D::Scale(balloon->scaleX, balloon->scaleY);
	if (balloon->color)
		RenderMesh2D(meshes["circle_red"], shaders["VertexColor"], modelMatrix);
	else
		RenderMesh2D(meshes["circle_yellow"], shaders["VertexColor"], modelMatrix);
	
	if (!balloon->isHit) {
		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Translate(balloon->lineX, balloon->lineY);
		modelMatrix *= Transform2D::Scale(0.5, 1);
		if (balloon->color)
			RenderMesh2D(meshes["line_red"], shaders["VertexColor"], modelMatrix);
		else
			RenderMesh2D(meshes["line_yellow"], shaders["VertexColor"], modelMatrix);
	}

}

// functie ce face update la obiectele din scena
void Tema1::updateObjects(float deltaTimeSeconds) {

	for (int i = 0; i < gameObjects.size(); i++) {
		GameObjects* obj = gameObjects.at(i);
		
		// daca scorul curent are una dintre valorile prestabilite 10, 15 sau -10
		// inseamna ca unul dintre obiecte a fost lovit si score bar-ul trebuie
		// actualizat conform cerintei
		if (ScoreBarObject* my_obj = dynamic_cast<ScoreBarObject*>(obj)) {
			if (current_score == 10) {
				my_obj->scaleX += 1;
			}
			else if (current_score == 15) {
				my_obj->scaleX += 1.5;
			}
			else if (current_score == -10) {
				if (my_obj->scaleX > 0) {
					my_obj->scaleX -= 1;
				}
			}
			renderScoreBar(my_obj);
		}

		// power bar-ul il pozotionez mereu sub arc, iar daca butonul mouse-ului
		// este apasat scalez dreptunghiul pana la un mazim de 100
		if (PowerBarObject* my_obj = dynamic_cast<PowerBarObject*>(obj)) {
			BowObject* bow = dynamic_cast<BowObject*>(gameObjects.at(0));
			my_obj->posX = bow->posX;
			my_obj->posY = bow->posY - 100;
			if (is_pressed) {
				if (my_obj->scaleX <= 100)
					my_obj->scaleX += translatePowerBar;
			} else {
				my_obj->scaleX = 0;
			}
			renderPowerBar(my_obj);
		}

		// arcul ramane in pozitia initiala atat timp cat W sau S nu sunt
		// apasate; iar daca sunt translatez arcul cu translateBow pe care
		// il actualizez in OnInputUpdate
		if (BowObject* my_obj = dynamic_cast<BowObject*>(obj)) {
			/*float dx = float(mouse_X - my_obj->posX);
			float dy = float(my_obj->posY - mouse_Y);
			angularStepArrow = atan(float(dy / dx));*/
			if (W_pressed) {
				my_obj->posY += translateBow;
			}
			if (S_pressed) {
				my_obj->posY -= translateBow;
			}
			renderBow(my_obj);
		}

		if (ArrowObject* my_obj = dynamic_cast<ArrowObject*>(obj)) {
			
			// daca nu s-a apasat pe buton atunci misca sageata impreuna cu arcul
			// daca da atunci lansez sageata pe traiectoria stabilita
			if (!my_obj->moving) {
				
				if (W_pressed) {
					my_obj->headY += translateBow;
					my_obj->tailY += translateBow;
				}
				if (S_pressed) {
					my_obj->headY -= translateBow;
					my_obj->tailY -= translateBow;
				}
			}
			else {
				my_obj->headX += deltaTimeSeconds * speedHold * 30;
				my_obj->tailX += deltaTimeSeconds * speedHold * 30;
			}

			renderArrow(my_obj);
		}

		if (BalloonObject* my_obj = dynamic_cast<BalloonObject*>(obj)) {

			// daca balonul a iesit din scena il sterg din vectorul de obiecte
			if (my_obj->posY >= 720) {
				gameObjects.erase(gameObjects.begin() + i);
				i--;
			}
			else {
				// daca nu este lovit isi continua miscarea in sus
				if (!my_obj->isHit) {
					my_obj->posY += deltaTimeSeconds * my_obj->speed;
					my_obj->lineY += deltaTimeSeconds * my_obj->speed;
				}
				// daca a fost lovit se va deplasa in jos pe Oy si va fi
				// scalat pana la disparitie si apoi sters din vector
				else {
					my_obj->posY -= deltaTimeSeconds * my_obj->speed;
					my_obj->lineY -= deltaTimeSeconds * my_obj->speed;
					if ((my_obj->scaleX < 0) || (my_obj->scaleY < 0)) {
						gameObjects.erase(gameObjects.begin() + i);
						i--;
					}
					else {
						my_obj->scaleX -= deltaTimeSeconds * 0.75;
						my_obj->scaleY -= deltaTimeSeconds * 0.75;
					}
				}
				renderBalloon(my_obj);
			}
		}

		// shurikenul are comportamentul asemanator cu balonul
		if (ShurikenObject* my_obj = dynamic_cast<ShurikenObject*>(obj)) {
			if (my_obj->posX <= 0) {
				gameObjects.erase(gameObjects.begin() + i);
				i--;
			}
			else {
				if (!my_obj->isHit) {
					my_obj->posX -= deltaTimeSeconds * my_obj->speed;
				}
				else {
					my_obj->posY -= deltaTimeSeconds * my_obj->speed;
					if ((my_obj->scaleX < 0) || (my_obj->scaleY < 0)) {
						gameObjects.erase(gameObjects.begin() + i);
						i--;
					}
					else {
						my_obj->scaleX -= deltaTimeSeconds * 0.75;
						my_obj->scaleY -= deltaTimeSeconds * 0.75;
					}
				}
				renderShuriken(my_obj, deltaTimeSeconds);
			}
		}

	}

	// vectorul de vieti reprezentate prin inimi
	for (int i = 0; i < lifeObjects.size(); i++) {
		renderLife(lifeObjects.at(i));
	}
}

// functia de verificare a coliziunilor
void Tema1::checkCollision(ArrowObject* arrow, BowObject* bow) {

	for (int i = 0; i < gameObjects.size(); i++) {
		GameObjects* obj = gameObjects.at(i);

		if (BalloonObject* my_obj = dynamic_cast<BalloonObject*>(obj)) {
			
			//coliziune sageata balon ( punct -> cerc )
			int dx = (int)(arrow->headX - my_obj->posX);
			int dy = (int)(arrow->headY - my_obj->posY);
			int distance = sqrt((dx * dx) + (dy * dy));
			
			if (distance <= (int)(10.0f * my_obj->scaleY)) {
				my_obj->isHit = true;
				
				//pun sageata la loc in functi de poztiile arcului
				arrow->headX = bow->posX + 110;
				arrow->headY = bow->posY;
				arrow->tailX = arrow->headX - 10;
				arrow->tailY = arrow->headY + 1;
				arrow->moving = false;
				speedHold = 0;

				// actualizez scorul curent
				if (my_obj->color) {
					current_score = 10;
				}
				else {
					current_score = -10;
				}
			}

			// actualizez scorul final
			score += current_score;
		}

		if (ShurikenObject* my_obj = dynamic_cast<ShurikenObject*>(obj)) {
			
			// coliziune shuriken sageata ( punct -> cerc )
			int dx = (int)(arrow->headX - my_obj->posX);
			int dy = (int)(arrow->headY - my_obj->posY);
			int distance = sqrt((dx * dx) + (dy * dy));
			
			if (distance <= (int)(10.0f * my_obj->scaleY)) {
				my_obj->isHit = true;
				current_score = 15;

				arrow->headX = bow->posX + 110;
				arrow->headY = bow->posY;
				arrow->tailX = arrow->headX - 10;
				arrow->tailY = arrow->headY + 1;
				arrow->moving = false;
				speedHold = 0;
			}

			// coliziune shuriken arc ( cerc -> cerc )
			dx = (int)(bow->posX - my_obj->posX);
			dy = (int)(bow->posY - my_obj->posY);
			distance = sqrt((dx * dx) + (dy * dy));

			if (distance <= ((int)(10.0f * my_obj->scaleY) + (int)(10.0f * bow->scaleY))) {
				// actualizez numarul de vieti si sterg o viata din vector
				lifes--;
				lifeObjects.erase(lifeObjects.begin() + lifes);
				gameObjects.erase(gameObjects.begin() + i);
				i--;
			}

			score += current_score;
		}
	}

}

void Tema1::Update(float deltaTimeSeconds)
{
	glLineWidth(2);

	// daca numarul de vieti a ajuns la 0 atunci jocatorul a pierdut
	if (lifes == 0) {
		gameObjects.clear();
		lifeObjects.clear();
		cout << "GAME OVER!" << endl;
		cout << "total points = " << score << endl;
		exit(0);
	}

	// daca s-a ajuns la "nivelul 3" atunci jucatorul a castigat
	else if (cnt == 3000) {
		gameObjects.clear();
		lifeObjects.clear();
		cout << "CONGRATULATIONS!" << endl;
		cout << "total points = " << score << endl;
		exit(0);
	}

	else {
		cnt++;
		if (cnt % 1000 == 0) {
			initLevel2();
		}

		BowObject* bow = dynamic_cast<BowObject*>(gameObjects.at(0));
		ArrowObject* arrow = dynamic_cast<ArrowObject*>(gameObjects.at(1));

		updateObjects(deltaTimeSeconds);
		current_score = 0;
		checkCollision(arrow, bow);

		// daca sageata a iesit din scena o readuc la arc
		if (arrow->headX >= 1280) {
			arrow->headX = bow->posX + 110;
			arrow->headY = bow->posY;
			arrow->tailX = arrow->headX - 10;
			arrow->tailY = arrow->headY + 1;
			arrow->moving = false;
			speedHold = 0;
		}
	}

}

void Tema1::FrameEnd()
{

}

void Tema1::OnInputUpdate(float deltaTime, int mods)
{
	if (window->KeyHold(GLFW_KEY_W)) {
		translateBow += deltaTime;
	}
	if (window->KeyHold(GLFW_KEY_S)) {
		translateBow += deltaTime;
	}

	if (window->MouseHold(GLFW_MOUSE_BUTTON_LEFT)) {
		speedHold++;
		translatePowerBar += deltaTime;
		is_pressed = true;
	}
}

void Tema1::OnKeyPress(int key, int mods)
{
	if (key == GLFW_KEY_W) {
		W_pressed = true;
	}

	if (key == GLFW_KEY_S) {
		S_pressed = true;
	}
}

void Tema1::OnKeyRelease(int key, int mods)
{
	if (key == GLFW_KEY_W) {
		W_pressed = false;
	}

	if (key == GLFW_KEY_S) {
		S_pressed = false;
	}
}

void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
	mouse_X = mouseX;
	mouse_Y = mouseY;
}

void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{	

}

void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
	// cand nu se mai tine apasat pe mouse actualizez varibila moving de la sageata
	if (!window->MouseHold(GLFW_MOUSE_BUTTON_LEFT)) {
		for (int i = 0; i < gameObjects.size(); i++) {

			GameObjects* obj = gameObjects.at(i);

			if (ArrowObject* my_obj = dynamic_cast<ArrowObject*>(obj)) {
				my_obj->moving = true;
			}
		}
		translatePowerBar = 0;
		is_pressed = false;
	}
}

void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}

void Tema1::OnWindowResize(int width, int height)
{
}
