#include "lucerna/lucerna.h"

Application::Application(){
    m_window = new Window("Lucerna", 1080, 720);
}

Application::Application(const char* name, unsigned int width, unsigned int height){
    m_window = new Window(name, width, height);
    m_window->init();
}

Application::~Application(){
    delete m_window;
}

void Application::run(){
    if(m_window->init()){
        while(!m_window->closed()){
            m_window->clear();
            m_window->update();
        }
    }
}