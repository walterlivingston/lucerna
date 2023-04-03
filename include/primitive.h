#pragma once

#include <vector>

struct Vertex{
    glm::vec3 position;
    glm::vec2 texcoord;
};

class Primitive{
    private:
        std::vector<Vertex> m_vertices;
        std::vector<unsigned int> m_indices;

    public:
        Primitive() {};
        virtual ~Primitive() {};

        inline void set(std::vector<Vertex> vertices, std::vector<unsigned int> indices){
            m_vertices = vertices;
            m_indices = indices;
        };
        inline std::vector<Vertex> getVertices() { return m_vertices; };
        inline std::vector<unsigned int> getIndices() { return m_indices; };
};

class Quad : public Primitive{
    private:
    public:
        Quad();
};

class Triangle : public Primitive{
    private:
    public:
        Triangle();
};
