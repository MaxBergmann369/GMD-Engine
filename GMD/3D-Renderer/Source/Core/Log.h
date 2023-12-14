#pragma once

#include <iostream>

namespace gmd
{
	class Log
	{
	public:
		Log() = delete;

		static void LogString(const std::string& name);
	};
}

