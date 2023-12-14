#pragma once

#include "Core/Window.h"
#include "Core/Log.h"
#include "Core/IApplication.h"

namespace gmd
{
	class Editor : public IApplication
	{
	private:
		Window m_Window;

		void Init() override;
	public:
		Editor();

		void Update() override;
		inline bool IsOpen() const { return this->m_Window.IsOpen(); }
	};
}