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

void gmd::Window::Update()
{
    glfwPollEvents();

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    // Imgui

           // 2. Show a simple window that we create ourselves. We use a Begin/End pair to create a named window.
    {
        static float f = 0.0f;
        static int counter = 0;

        ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

        ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)

        ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f

        if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
            counter++;
        ImGui::SameLine();
        ImGui::Text("counter = %d", counter);

        ImGui::End();
    }
    

    ImGui::Render();
    int display_w, display_h;
    glfwGetFramebufferSize(this->m_Window, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    glClear(GL_COLOR_BUFFER_BIT);

    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    glfwSwapBuffers(this->m_Window);
}
