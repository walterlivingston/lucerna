#pragma once

#include <vector>
#include <string>
#include <glm/glm.hpp>

#include "texture.h"
#include "shader.h"

struct Vertex{
    glm::vec3 position;
    glm::vec2 texcoord;
};

class Mesh{
    private:
        Shader m_shader;

        std::vector<Vertex> m_vertices;
        std::vector<unsigned int> m_indices;

        unsigned int m_VAO;
        unsigned int m_VBO;
        unsigned int m_EBO;

        void initRenderData();
    public:
        Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices = {}, std::string shader = "default");
        ~Mesh();
        void draw(Tex2D texture, glm::vec2 position, glm::vec2 size = glm::vec2(10.0f, 10.0f), float rotate = 0.0f, glm::vec3 color = glm::vec3(1.0f));
};