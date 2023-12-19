#pragma once

#include "Headers/GDM.h"
#include "Core/Window.h"
#include "Utility/Utility.h"
#include "Camera/Camera.h"
#include "Core/IApplication.h"
#include "Core/shaderClass.h"
#include "Utility/Macros.h"

namespace gmd
{
	class Editor : public IApplication
	{
	private:
		constexpr static float WIDTH = 1280;
		constexpr static float HEIGHT = 720;

		// Generates Shader object using shaders default.vert and default.frag
		Shader m_Shader;
		Camera m_Camera;
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
