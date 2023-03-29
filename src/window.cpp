#include "lucerna/lucerna.h"

Window::Window(const char* name, unsigned int width, unsigned int height): m_name(name), m_width(width), m_height(height) {}
Window::~Window(){
    glfwTerminate();
}

bool Window::init(){
	if (!glfwInit()){
        throw std::runtime_error("GLFW failed to initialize");
        return false;
    }

	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL 

    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

	m_window = glfwCreateWindow(m_width, m_height, m_name, NULL, NULL);
	if (m_window == NULL){
		std::cerr << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
        return false;
	}
    //glfwSetKeyCallback(m_Window, key_callback);
    glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);

    glfwMakeContextCurrent(m_window);
    gladLoadGL();

    return true;
}

void Window::clear(){
    glClear( GL_COLOR_BUFFER_BIT );
}

void Window::update(){
    glfwSwapBuffers(m_window);
    glfwPollEvents();
}

bool Window::closed(){
    return glfwWindowShouldClose(m_window);
}

void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
} 