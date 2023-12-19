#pragma once

#include <iostream>
#include <vector>
#include <Windows.h>
#include <sstream>

#include "Core/Log.h"

namespace gmd
{
	class Utility
	{
	public:
		static std::string GetDefaultDir(uint32_t depth);
		static std::vector<std::string> Split(const std::string& s, char delim);
		static void SetCurrentDir(const std::string& path);
		static std::string GetCurrentDir();

	};
}
