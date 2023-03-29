#pragma once

#include <iostream>
#include <functional>

#include <SDL.h>

class Application{
    private:
        SDL_Window* m_window;
        SDL_Renderer* m_renderer;
        bool m_isRunning = true;

        Uint32 m_framerate = 60;
        int m_mouseX;
        int m_mouseY;

        std::function<void(void)> m_eventCallback;
        std::function<void(void)> m_renderCallback;
    public:
        Application(const char* title, int width, int height);
        ~Application();

        inline void setEventCallback(std::function<void(void)> func){ m_eventCallback = func; };
        inline void setRenderCallback(std::function<void(void)> func){ m_renderCallback = func; };
        inline SDL_Window* getWindow() const { return m_window; };
        inline SDL_Renderer* getRenderer() const { return m_renderer; };
        inline void setFramerate(int framerate) { m_framerate = framerate; };
        inline int getMouseX(){ return m_mouseX; };
        inline int getMouseY(){ return m_mouseY; };

        void run();
        inline void stop(){ m_isRunning = false; };
};