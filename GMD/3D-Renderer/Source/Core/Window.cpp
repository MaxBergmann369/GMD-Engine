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
        gmd::Log::Error("Failed to initialize GLFW");
        return;
    }

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
    glfwDestroyWindow(this->m_Window);
    glfwTerminate();
}

// Public

void gmd::Window::Update()
{
    glfwSwapBuffers(this->m_Window);
    glfwPollEvents();
}
