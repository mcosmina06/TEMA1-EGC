#pragma once

#include <string>

#include <include/glm.h>
#include <Core/GPU/Mesh.h>

namespace Object2D
{
	Mesh* CreateSemiCircle(std::string name, glm::vec3 circleCenter, float radius, glm::vec3 color, bool fill = false);
	Mesh* CreateRectangle(std::string name, glm::vec3 leftBottomCorner, float width, float height, glm::vec3 color, bool fill = false);
	Mesh* CreateTriangle(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false);
	Mesh* CreateTriangleArrow(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill);
	Mesh* CreateCircle(std::string name, glm::vec3 circleCenter, float radius, glm::vec3 color, bool fill = false);
	Mesh* CreateLine(std::string name, glm::vec3 leftBottomCorner, float height, glm::vec3 color, bool fill = false);
	Mesh* CreateLife(std::string name, glm::vec3 leftBottomCorner, float height, glm::vec3 color, bool fill = false);
}

