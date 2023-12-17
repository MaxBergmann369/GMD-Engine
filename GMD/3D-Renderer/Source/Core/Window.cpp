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

        throw std::runtime_error("Couldnt init GLFW");
    }

    this->m_Window = glfwCreateWindow((int)this->m_Size.X, (int)this->m_Size.Y, "GLFW Window", NULL, NULL);

    if (!this->m_Window) {
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(this->m_Window);

    if (glewInit() != GLEW_OK)
    {
        gmd::Log::Error("Failed to initialize GLEW");
        throw std::runtime_error("Couldnt init GLEW");
    }
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    ImGui_ImplGlfw_InitForOpenGL(this->m_Window, true);
    ImGui_ImplOpenGL3_Init("#version 330");
}

// Dtor

gmd::Window::~Window()
{
    glfwDestroyWindow(this->m_Window);
    glfwTerminate();
}

// Public

void gmd::Window::EndFrame()
{
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    glfwSwapBuffers(this->m_Window);
}

void gmd::Window::NewFrame()
{
    glfwPollEvents();
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}
