#include "Application.h"

Application::Application(const char* title, int width, int height){
    if (SDL_Init( SDL_INIT_EVERYTHING ) < 0)
		std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;

	// Create our window
	m_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);

	// Make sure creating the window succeeded
	if (!m_window)
		std::cout << "Error creating window: " << SDL_GetError()  << std::endl;

    // Create our window
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

	// Make sure creating the renderer succeeded
	if (!m_renderer)
		std::cout << "Error creating renderer: " << SDL_GetError()  << std::endl;
}

Application::~Application(){
	// Destroy the window. This will also destroy the surface
	SDL_DestroyWindow(m_window);
}

void Application::handleEvents(){
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            m_isRunning = false;
        }
    }
}

void Application::render(){

}

void Application::loop(){
    while(m_isRunning){
        handleEvents();
        render();
    }
}