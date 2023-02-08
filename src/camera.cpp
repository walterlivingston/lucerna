#include <camera.h>

Camera::Camera(int width, int height, glm::vec3 position){
    Camera::width = width;
    Camera::height = height;
    pos = position;
}

void Camera::updateMatrix(float FOVdeg, float nearPlane, float farPlane){
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection = glm::mat4(1.0f);

    view = glm::lookAt(pos, pos + orientation, up);
    projection = glm::perspective(glm::radians(FOVdeg), (float)(width / height), nearPlane, farPlane);

    camMatrix = projection * view;
}

void Camera::matrix(Shader& shader, const char* uniform){
    glUniformMatrix4fv(glGetUniformLocation(shader.ID, uniform), 1, GL_FALSE, glm::value_ptr(camMatrix));
}

void Camera::input(GLFWwindow* window){
    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){
        pos += speed * orientation;
    }
    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS){
        pos += speed * -glm::normalize(glm::cross(orientation, up));
    }
    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){
        pos += speed * -orientation;
    }
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS){
        pos += speed * glm::normalize(glm::cross(orientation, up));
    }
    if(glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS){
        pos += speed * up;
    }
    if(glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS){
        pos += speed * -up;
    }
    if(glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS){
        speed = 0.4f;
    }else if(glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE){
        speed = 0.1f;
    }

    if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS){
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
        
        if(firstClick){
            glfwSetCursorPos(window, (width / 2), (height / 2));
            firstClick = false;
        }

        double mouseX;
        double mouseY;
        glfwGetCursorPos(window, &mouseX, &mouseY);

        float rotX = sensitivity * (float)(mouseY - (height / 2)) / height;
        float rotY = sensitivity * (float)(mouseX - (width / 2)) / width;
        glm::vec3 newOrientation = glm::rotate(orientation, glm::radians(-rotX), glm::normalize(glm::cross(orientation, up)));

        if(glm::angle(newOrientation, up) <= glm::radians(5.0f) or glm::angle(newOrientation, -up) <= glm::radians(5.0f)){
            orientation = newOrientation;
        }
        orientation = glm::rotate(orientation, glm::radians(-rotY), up);

        glfwSetCursorPos(window, (width / 2), (height / 2));

    }else if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE){
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        firstClick = true;
    }
}