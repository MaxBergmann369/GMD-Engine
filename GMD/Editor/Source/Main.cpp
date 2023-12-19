#include "Editor/Editor.h"

int main() 
{
    const std::string dir = gmd::Utility::GetDefaultDir(2);
    gmd::Utility::SetCurrentDir(dir);

    gmd::Editor editor;
    while (editor.IsOpen())
    {
		editor.Update();
	}
}
