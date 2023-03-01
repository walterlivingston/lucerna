#pragma once

#include <string>

class Window{
    private:
        const char* m_name;
        int m_width, m_height;
        GLFWwindow* m_window;

        static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    public:
        Window(const char* name, int width, int height);
        ~Window();
        bool init();

        void clear();
        void update();

        bool closed();

        inline const char* getName() { return m_name; };
        inline int getWidth() { return m_width; };
        inline int getHeight() { return m_height; };
        inline GLFWwindow* getWindow() { return m_window; };
};