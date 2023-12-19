#include "Utility.h"

void gmd::Utility::SetCurrentDir(const std::string& path)
{
    gmd::Log::Warning("Setting dir..");
    if (!SetCurrentDirectoryA(path.c_str()))
    {
        throw std::runtime_error("Couldn't set directory");
    }
}

std::string gmd::Utility::GetCurrentDir()
{
    char NPath[MAX_PATH];
    GetCurrentDirectoryA(MAX_PATH, NPath);
    std::string path(NPath);
    return path;
}

std::string gmd::Utility::GetDefaultDir(uint32_t depth)
{
    gmd::Log::Warning("Calling GetDefaultDir()..");
    char NPath[MAX_PATH];
    GetCurrentDirectoryA(MAX_PATH, NPath);
    std::string path(NPath);
    std::vector<std::string> parts = gmd::Utility::Split(path, '\\');

    std::string projectString = "";

    for (size_t i = 0; i < parts.size() - depth; i++)
    {
        projectString += (i == parts.size() - depth - 1) ? parts[i] : parts[i] + "\\";
    }

    return projectString;
}

std::vector<std::string> gmd::Utility::Split(const std::string& s, char delim)
{
    std::vector<std::string> result;
    std::stringstream ss(s);
    std::string item;

    while (getline(ss, item, delim)) {
        result.push_back(item);
    }

    return result;
}
