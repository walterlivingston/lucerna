#ifndef CAMERA_H
#define CAMERA_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/vector_angle.hpp>

#include <shader.h>

class Camera{
    public:
        glm::vec3 pos;
        glm::vec3 orientation = glm::vec3(0.0f, 0.0f, -1.0f);
        glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
        glm::mat4 camMatrix = glm::mat4(1.0f);

        bool firstClick = true;

        int width;
        int height;

        float speed = 0.1f;
        float sensitivity = 100.0f;

        Camera(int width, int height, glm::vec3 position);

        void updateMatrix(float FOVdeg, float nearPlane, float farPlane);
        void matrix(Shader& shader, const char* uniform);
        void input(GLFWwindow* window);
};

#endif