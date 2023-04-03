#pragma once

#include <vector>

struct Vertex{
    glm::vec3 position;
    glm::vec2 texcoord;
};

class Primitive{
    private:
        Shader m_shader;

        std::vector<Vertex> m_vertices;
        std::vector<unsigned int> m_indices;

        unsigned int m_VAO;
        unsigned int m_VBO;
        unsigned int m_EBO;

        glm::mat4 m_modelMat = glm::mat4(1.0f);
        glm::vec3 m_position;
        glm::vec3 m_scale = glm::vec3(1.0f, 1.0f, 1.0f);
        glm::vec3 m_rotation = glm::vec3(0.0f, 0.0f, 0.0f);

    public:
        Primitive(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), std::string shader = "default");
        ~Primitive();

        void update();
        void draw();
        void initRenderData();
        void set(std::vector<Vertex> vertices, std::vector<unsigned int> indices);

        inline std::vector<Vertex> getVertices() { return this->m_vertices; };
        inline std::vector<unsigned int> getIndices() { return this->m_indices; };
        inline void setPos(glm::vec3 position) { this->m_position = position; };
        inline void setScale(glm::vec3 scale) { this->m_scale = scale; };
        inline void setRotation(glm::vec3 rotation) { this->m_rotation = rotation; };
};

class Quad : public Primitive{
    private:
        float m_width;
        float m_height;
    public:
        Quad(float width = 1.0f, float height = 1.0f);
};

class Triangle : public Primitive{
    private:
    public:
        Triangle();
};

class Line : public Primitive{
    private:
    public:
        Line();
};