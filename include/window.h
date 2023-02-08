#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "resource_manager.h"

class Window{
    private:
        GLFWwindow* m_Window;
        int m_Width, m_Height;
        Shader shader;
        const char* m_Title;
        bool m_Initialized;
    public:
        Window(const char* title, int width, int height);
        ~Window();
        void Init();
        void Clear(float x, float y, float z);
        void Update();

        void setShader(Shader& shader);
        Shader& getShader();

        bool Closed() { return glfwWindowShouldClose(m_Window); }
};

#endif