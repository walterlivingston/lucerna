#include "lucerna/lucerna.h"

Mesh::Mesh(Primitive* primitive, std::string shader){
    this->m_vertices = primitive->getVertices();
    this->m_indices = primitive->getIndices();
    this->m_shader = ResourceManager::getShader(shader);
    this->initRenderData();
}

Mesh::~Mesh(){
    glDeleteVertexArrays(1, &this->m_VAO);
    glDeleteBuffers(1, &this->m_VBO);
    if(!m_indices.empty()) 
        glDeleteBuffers(1, &this->m_EBO);
}

void Mesh::draw(Tex2D texture, glm::vec2 position, glm::vec2 size, float rotate, glm::vec3 color){
    m_shader.use();
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(position.x - (texture.width/2), position.y - (texture.height/2), 0.0f));

    model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f));
    model = glm::rotate(model, glm::radians(rotate), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f));
    model = glm::scale(model, glm::vec3(size, 1.0f));

    m_shader.setMat4f("model", model);
    m_shader.setVec3f("spriteColor", color);

    glActiveTexture(GL_TEXTURE0);
    texture.Bind();

    glBindVertexArray(this->m_VAO);
    if(m_indices.empty())
        glDrawArrays(GL_TRIANGLES, 0, this->m_vertices.size());
    else{
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
        glDrawElements(GL_TRIANGLES, this->m_indices.size(), GL_UNSIGNED_INT, 0);
    }
    glBindVertexArray(0);
}

void Mesh::initRenderData(){
    glGenVertexArrays(1, &this->m_VAO);
    glGenBuffers(1, &m_VBO);

    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(Vertex), m_vertices.data(), GL_STATIC_DRAW);

    if(!m_indices.empty()){
        glGenBuffers(1, &m_EBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.size() * sizeof(unsigned int), &m_indices[0], GL_STATIC_DRAW);
    }

    glBindVertexArray(this->m_VAO);
    // Position
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
    // Texture Coordinate
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texcoord));

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}