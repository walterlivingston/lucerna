#pragma once

#include "window.h"

class Application{
    private:
        Window* m_window;
    public:
        Application();
        Application(const char* name, unsigned int width, unsigned int height);
        virtual ~Application();

        void run();
};