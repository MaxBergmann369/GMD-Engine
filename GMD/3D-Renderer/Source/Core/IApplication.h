#pragma once

#include <iostream>

namespace gmd
{
	class IApplication
	{
	protected:
		virtual void Init() = 0;	
	public:
		IApplication() = default;

		virtual void Update() = 0;	
	};
}

