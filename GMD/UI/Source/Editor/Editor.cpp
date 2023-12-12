#include "Editor.h"


gmd::Editor::Editor()
	: m_Window(Vector2(1280, 720))
{

}

void gmd::Editor::Update()
{
	this->m_Window.Update();
}
