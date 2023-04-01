#pragma once

#include <string>
#include <imgui.h>

class Window{
    private:
        const char* m_name;
        unsigned int m_width, m_height;
        GLFWwindow* m_window;

        static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    public:
        Window(const char* name, unsigned int width, unsigned int height);
        ~Window();
        bool init();

        void clear();
        void update();

        bool closed();

        inline const char* getName() { return m_name; };
        inline unsigned int getWidth() { return m_width; };
        inline unsigned int getHeight() { return m_height; };
        inline GLFWwindow* getWindow() { return m_window; };
};