#include "Editor.h"

gmd::Editor::Editor()
	: m_Window(Vector2(1280, 720))
{
	std::cout << "ctor" << std::endl;
}

void gmd::Editor::Init() 
{
}

void gmd::Editor::Update()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(0.0f, 0.5f);
	glVertex2f(0.5f, -0.5f);
	glEnd();

	// Update OpenGL window and poll events
	this->m_Window.Update();
}
