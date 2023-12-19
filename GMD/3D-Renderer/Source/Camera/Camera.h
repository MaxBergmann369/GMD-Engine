#ifndef CAMERA_CLASS_H
#define CAMERA_CLASS_H

#include <Libs/GLEW/glew.h>
#include <Libs/GLFW/glfw3.h>
#include<Libs/glm/glm.hpp>
#include<Libs/glm/gtc/matrix_transform.hpp>
#include<Libs/glm/gtc/type_ptr.hpp>
#include<Libs/glm/gtx/rotate_vector.hpp>
#include<Libs/glm/gtx/vector_angle.hpp>

#include"Core/ShaderClass.h"

class Camera
{
public:
	// Stores the main vectors of the camera
	glm::vec3 Position;
	glm::vec3 Orientation = glm::vec3(0.0f, 0.0f, -0.05f);
	glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);

	// Prevents the camera from jumping around when first clicking left click
	bool firstClick = true;

	// Stores the width and height of the window
	int width;
	int height;

	// Adjust the speed of the camera and it's sensitivity when looking around
	float speed = 0.1f;
	float sensitivity = 100.0f;

	// Camera constructor to set up initial values
	Camera(int width, int height, glm::vec3 position);

	// Updates and exports the camera matrix to the Vertex Shader
	void Matrix(float FOVdeg, float nearPlane, float farPlane, Shader& shader, const char* uniform);
	// Handles camera inputs
	void Inputs(GLFWwindow* window);
};
#endif