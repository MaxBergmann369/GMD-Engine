#pragma once

#include "Headers/GDM.h"

#include "Math/Vector2.h"
#include "Core/Log.h"

namespace gmd
{
	class Window
	{
	private:
		GLFWwindow* m_Window;

		Vector2 m_Size;

		void Init();

	public:
		Window() = default;
		Window(const Vector2& size);
		~Window();

		void EndFrame();
		void NewFrame();

		inline bool IsOpen() const { return !glfwWindowShouldClose(this->m_Window); }
	};
}
