#pragma once

#include "Core/Window.h"

namespace gmd
{
	class Editor
	{
	private:
		Window m_Window;

	public:
		Editor();

		void Update();
		inline bool IsOpen() const { return this->m_Window.IsOpen(); }
	};
}