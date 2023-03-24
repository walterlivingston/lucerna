#pragma once

#include <SDL.h>
#include <iostream>

class Application{
    private:
        SDL_Window* m_window;
        SDL_Renderer* m_renderer;
        bool m_isRunning = true;
    public:
        Application(const char* title, int width, int height);
        ~Application();

        void handleEvents();
        void render();
        void loop();
};