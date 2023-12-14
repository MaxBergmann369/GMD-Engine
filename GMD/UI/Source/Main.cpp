#include "Editor/Editor.h"

int main() 
{
    gmd::Editor editor;
    while (editor.IsOpen())
    {
		editor.Update();
	}
}
