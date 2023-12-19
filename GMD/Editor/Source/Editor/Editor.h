#pragma once

#include <Libs/GLEW/glew.h>
#include <Libs/GLFW/glfw3.h>
#include <Libs/GLM/glm.hpp>
#include "Camera/Camera.h"
#include "Core/Window.h"
#include "Core/IApplication.h"
#include "Core/shaderClass.h"

namespace gmd
{
	class Editor : public IApplication
	{

	unsigned int width = 1280;
	unsigned int height = 720;

	private:
		// Generates Shader object using shaders default.vert and default.frag
		Shader m_Shader = Shader("default.vert", "default.frag");
		Camera m_Camera = Camera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));
		Window m_Window;

		void Init() override;
		void RenderGUI();
		void Render();
	public:
		Editor();

		void Update() override;
		inline bool IsOpen() const { return this->m_Window.IsOpen(); }
	};
}
