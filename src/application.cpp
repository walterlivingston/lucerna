#include "lucerna/lucerna.h"

Application::Application(){
    m_window = new Window("Lucerna", 1080, 720);
    m_window->init();
}

Application::Application(const char* name, unsigned int width, unsigned int height){
    m_window = new Window(name, width, height);
    m_window->init();
}

Application::~Application(){
    delete m_window;
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void Application::run(){
    while(!m_window->closed()){
        // m_eventCallback();

        m_window->clear();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        m_renderCallback();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        m_window->update();
    }
}