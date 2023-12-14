#include "Log.h"

void gmd::Log::Error(const std::string& name)
{
	std::cout << "Error: " << name << std::endl;
}

void gmd::Log::Warning(const std::string& name)
{
	std::cout << "Warning: " << name << std::endl;
}
