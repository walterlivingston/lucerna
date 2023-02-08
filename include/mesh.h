#ifndef MESH_H
#define MESH_H

#include <string>

#include "vao.h"
#include "ebo.h"
#include "shader.h"

class Mesh{
    public:
        std::vector<Vertex> vertices;
        std::vector<GLuint> indices;
        VAO VAO;

        Mesh(std::vector<Vertex>& vertices, std::vector<GLuint>& indices);
        void Draw(Shader& shader, GLenum type = GL_TRIANGLES);
};

#endif