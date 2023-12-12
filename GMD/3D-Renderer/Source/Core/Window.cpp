#include "Window.h"

// Ctor

gmd::Window::Window(const Vector2& size)
{
	this->m_Size = size; 
    this->Init();
}

void gmd::Window::Init()
{
    if (!glfwInit()) {
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    this->m_Window = glfwCreateWindow((int)this->m_Size.X, (int)this->m_Size.Y, "GLFW Window", NULL, NULL);

    if (!this->m_Window) {
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(this->m_Window);
}

// Dtor

gmd::Window::~Window()
{
    glfwTerminate();
}

// Public

void gmd::Window::Update()
{
    glfwSwapBuffers(this->m_Window);
    glfwPollEvents();
}
