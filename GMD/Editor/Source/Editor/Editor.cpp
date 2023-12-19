#include "Editor.h"

// Constructor & Destructor

gmd::Editor::Editor()
	: m_Shader(PATH_TO_RESSOURCES_SHADER"/default.vert", PATH_TO_RESSOURCES_SHADER"/default.frag"),
	m_Camera(this->WIDTH, this->HEIGHT, glm::vec3(0.0f, 0.0f, 2.0f)),
	m_Window(Vector2(1280, 720))
{
	this->Init();
}

// Private

void gmd::Editor::Init() 
{
	// Init here
}

void gmd::Editor::RenderGUI()
{
	ImGui::Begin("Triangle Example");
	ImGui::Text("Hello, this is a triangle!");
	ImGui::End();
}

void gmd::Editor::Render()
{
	// OpenGL Rendering
	glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(0.0f, 0.5f);
	glVertex2f(0.5f, -0.5f);
	glEnd();
}

// Public

void gmd::Editor::Update()
{
	this->m_Window.NewFrame();

	this->Render();
	this->RenderGUI();

	this->m_Window.EndFrame();
}
