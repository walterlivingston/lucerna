#ifndef VBO_H
#define VBO_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <vector>

struct Vertex{
    glm::vec3 position;
    glm::vec3 color;
};

class VBO{
    public:
        GLuint ID;
        VBO(std::vector<Vertex> vertices);

        void Bind();
        void Unbind();
        void Delete();
};

#endif
