 #include "Object2D.h"

#include <Core/Engine.h>

Mesh* Object2D::CreateRectangle(std::string name, glm::vec3 leftBottomCorner, float width, float height, glm::vec3 color, bool fill)
{
	glm::vec3 corner = leftBottomCorner;

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(corner, color),
		VertexFormat(corner + glm::vec3(-width, 0, 0), color),
		VertexFormat(corner + glm::vec3(-width, -height, 0), color),
		VertexFormat(corner + glm::vec3(0, -height, 0), color)

	};

	Mesh* rectangle = new Mesh(name);
	std::vector<unsigned short> indices = { 0, 1, 2, 3 };

	if (!fill) {
		rectangle->SetDrawMode(GL_LINE_LOOP);
	}
	else {
		indices.push_back(0);
		indices.push_back(2);
	}

	rectangle->InitFromData(vertices, indices);
	return rectangle;
}

Mesh* Object2D::CreateLine(std::string name, glm::vec3 leftBottomCorner, float height, glm::vec3 color, bool fill)
{
	glm::vec3 corner = leftBottomCorner;

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(corner, color),
		VertexFormat(corner + glm::vec3(0, -height/2, 0), color),
		VertexFormat(corner + glm::vec3(height/2, -height, 0), color), 
		VertexFormat(corner + glm::vec3(0, -1.5 * height, 0), color),
		VertexFormat(corner + glm::vec3(height/2, -2 * height, 0), color),
	};

	Mesh* line = new Mesh(name);
	std::vector<unsigned short> indices = { 0, 1, 2, 3, 4 };

	if (!fill) {
		line->SetDrawMode(GL_LINE_STRIP);
	}
	else {
		indices.push_back(0);
		indices.push_back(2);
	}

	line->InitFromData(vertices, indices);
	return line;
}

Mesh* Object2D::CreateSemiCircle(std::string name, glm::vec3 circleCenter, float radius, glm::vec3 color, bool fill)
{
	std::vector<VertexFormat> vertices;
	std::vector<unsigned short> indices;
	glm::vec3 center = circleCenter;


	for (int i = -90; i < 90; i++) {
		float i_rad = i * 3.14159 / 180;
		vertices.push_back(VertexFormat(center + glm::vec3(radius * cos(i_rad), radius * sin(i_rad), 0), color));
	}

	indices.push_back(0);

	for (unsigned short i = 1; i < 180; i++)
		indices.push_back(i);

	indices.push_back(1);

	Mesh* semicircle = new Mesh(name);


	if (!fill) {
		semicircle->SetDrawMode(GL_LINE_LOOP);
	}
	else {
		indices.push_back(0);
		indices.push_back(2);
	}

	semicircle->InitFromData(vertices, indices);
	return semicircle;
}

Mesh* Object2D::CreateTriangle(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill)
{
	glm::vec3 corner = leftBottomCorner;

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(corner, color),
		VertexFormat(corner + glm::vec3(0, length, 0), color),
		VertexFormat(corner + glm::vec3(length / 2, length / 2, 0), color),
	};

	Mesh* triangle = new Mesh(name);
	std::vector<unsigned short> indices = { 0, 1, 2 };

	if (!fill) {
		triangle->SetDrawMode(GL_LINE_LOOP);
	}
	else {
		indices.push_back(0);
	}

	triangle->InitFromData(vertices, indices);
	return triangle;
}

Mesh* Object2D::CreateTriangleArrow(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill)
{
	glm::vec3 corner = leftBottomCorner;

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(corner, color),
		VertexFormat(corner + glm::vec3(-length / 2, length / 2, 0), color),
		VertexFormat(corner + glm::vec3(-length / 2, -length / 2, 0), color)
	};

	Mesh* triangle = new Mesh(name);
	std::vector<unsigned short> indices = { 0, 1, 2 };

	if (!fill) {
		triangle->SetDrawMode(GL_LINE_LOOP);
	}
	else {
		indices.push_back(0);
	}

	triangle->InitFromData(vertices, indices);
	return triangle;
}

Mesh* Object2D::CreateCircle(std::string name, glm::vec3 circleCenter, float radius, glm::vec3 color, bool fill)
{
	std::vector<VertexFormat> vertices;
	std::vector<unsigned short> indices;
	glm::vec3 center = circleCenter;

	for (int i = 0; i < 360; i++) {
		float i_rad = i * 3.14159 / 180;
		vertices.push_back(VertexFormat(center + glm::vec3(radius * cos(i_rad), radius * sin(i_rad), 0), color));
	}

	indices.push_back(0);

	for (unsigned short i = 1; i < 360; i++)
		indices.push_back(i);

	Mesh* circle = new Mesh(name);

	if (!fill) {
		circle->SetDrawMode(GL_LINE_LOOP);
	}
	else {
		indices.push_back(0);
		indices.push_back(2);
	}

	circle->InitFromData(vertices, indices);
	circle->SetDrawMode(GL_TRIANGLE_FAN);
	return circle;
}

Mesh* Object2D::CreateLife(std::string name, glm::vec3 leftBottomCorner, float height, glm::vec3 color, bool fill)
{
	glm::vec3 corner = leftBottomCorner;

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(corner, color),
		VertexFormat(corner + glm::vec3(1.75 * height, height, 0), color),
		VertexFormat(corner + glm::vec3(height, 2 * height, 0), color),
		VertexFormat(corner + glm::vec3(0.25 * height, 2 * height, 0), color),
		VertexFormat(corner + glm::vec3(0, 1.75 * height, 0), color),
		VertexFormat(corner + glm::vec3(-0.25 * height, 2 * height, 0), color),
		VertexFormat(corner + glm::vec3(-height, 2 * height, 0), color),
		VertexFormat(corner + glm::vec3(-1.75 * height, height, 0), color)
	};

	Mesh* line = new Mesh(name);
	std::vector<unsigned short> indices = { 0, 1, 2, 3, 4, 5, 6, 7 };

	if (!fill) {
		line->SetDrawMode(GL_LINE_LOOP);
	}
	else {
		indices.push_back(0);
		indices.push_back(2);
	}

	line->InitFromData(vertices, indices);
	return line;
}
