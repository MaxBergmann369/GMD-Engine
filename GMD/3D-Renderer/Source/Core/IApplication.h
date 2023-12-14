#pragma once

#include <iostream>

namespace gmd
{
	class IApplication
	{
	protected:
		virtual void Init() = 0;	
	public:
		IApplication() { };

		virtual void Update() = 0;	
	};
}

