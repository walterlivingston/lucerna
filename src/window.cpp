#include "window.h"

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}

Window::Window(const char* title, int width, int height) : m_Width(width), m_Height(height), m_Title(title){}

Window::~Window(){
    if (m_Initialized)
        glfwTerminate();

    if (m_Window != nullptr)
        glfwDestroyWindow(m_Window);
}

void Window::Init(){
    m_Initialized = glfwInit();
	if (!m_Initialized)
        throw std::runtime_error("GLFW failed to initialize");

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

	m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
	if (m_Window == NULL){
		std::cerr << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
        return;
	}
    glfwSetKeyCallback(m_Window, key_callback);
    glfwSetFramebufferSizeCallback(m_Window, framebuffer_size_callback);

    glfwMakeContextCurrent(m_Window);
    gladLoadGL();
    
    setShader(ResourceManager::LoadShader("default.vert", "default.frag", nullptr, "default"));
    glm::mat4 view = glm::mat4(1.0f);
    // note that we're translating the scene in the reverse direction of where we want to move
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -100.0f));

    this->shader.SetMatrix4("view", view, true);
    this->shader.SetMatrix4("projection", glm::perspective(glm::radians(45.0f), (float)m_Width/(float)m_Height, 0.1f, 100.0f), true);
}

void Window::Clear(float x, float y, float z){
    glClearColor(x, y, z, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::Update(){
    glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);

    glViewport(0, 0, m_Width, m_Height);

    glfwSwapBuffers(m_Window);
    glfwPollEvents();
}

void Window::setShader(Shader& shader){
    this->shader = shader;
}

Shader& Window::getShader(){
    return this->shader;
}

