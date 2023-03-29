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
    SDL_Quit();
}

void Application::run(){
    while(m_isRunning){
        SDL_GetMouseState(&m_mouseX, &m_mouseY);
        m_eventCallback();

        // (TODO) Allow user to pick background color
        SDL_SetRenderDrawColor(m_renderer,0,0,0,SDL_ALPHA_OPAQUE);
        SDL_RenderClear(m_renderer);
        SDL_SetRenderDrawColor(m_renderer,255,255,255,SDL_ALPHA_OPAQUE);
        
        m_renderCallback();
        SDL_RenderPresent(m_renderer);
        SDL_Delay(100);
    }
}