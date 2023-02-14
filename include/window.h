#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include "shader.h"

class Window{
    private:
        int m_width, m_height;
        const char* m_name;
        GLFWwindow* m_window;

        static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    public:
        Window(const char* name, int width, int height);
        ~Window();
        bool init();

        void clear();
        void update();

        bool closed();
};

#endif