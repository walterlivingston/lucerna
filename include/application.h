#pragma once

#include <functional>

#include "window.h"

class Application{
    private:
        Window* m_window;

        // std::function<void(void)> m_eventCallback;
        std::function<void(void)> m_renderCallback;
    public:
        Application();
        Application(const char* name, unsigned int width, unsigned int height);
        ~Application();

        void run();

        inline void setRenderCallback(std::function<void(void)> func){ m_renderCallback = func; };
};