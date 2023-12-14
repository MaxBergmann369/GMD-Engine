#pragma once

#include <iostream>

namespace gmd
{
	class Log
	{
	public:
		Log() = delete;

		static void Error(const std::string& name);
		static void Warning(const std::string& name);
	};
}

