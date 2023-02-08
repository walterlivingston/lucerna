#include "mesh.h"

Mesh::Mesh(std::vector<Vertex>& vertices, std::vector<GLuint>& indices){
    Mesh::vertices = vertices;
    Mesh::indices = indices;
    VAO.Bind();

    VBO VBO(vertices);
    EBO EBO(indices);
    VAO.LinkAttrib(VBO, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
    VAO.LinkAttrib(VBO, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3* sizeof(float)));
    VAO.Unbind();
    VBO.Unbind();
    EBO.Unbind();
}

void Mesh::Draw(Shader& shader, GLenum type){
    shader.Use();
    VAO.Bind();
    glDrawArrays(type, 0, vertices.size());
}