#include "lucerna/lucerna.h"

// GENERAL PRIMITIVE FUNCTIONS
Primitive::Primitive(glm::vec3 position, std::string shader) 
    : m_shader(ResourceManager::getShader(shader)), m_position(position) {}

Primitive::~Primitive() {
    glDeleteVertexArrays(1, &this->m_VAO);
    glDeleteBuffers(1, &this->m_VBO);
    if(!this->m_indices.empty()) 
        glDeleteBuffers(1, &this->m_EBO);
}

void Primitive::update(){
    m_shader.use();
    m_modelMat = glm::mat4(1.0f);
    m_modelMat = glm::translate(m_modelMat, glm::vec3(m_position.x - (m_scale.x / 2), m_position.y - (m_scale.y / 2), m_position.z));
    // std::cout << m_vertices[1].position.x << std::endl;

    m_modelMat = glm::translate(m_modelMat, glm::vec3(0.5f * m_scale.x, 0.5f * m_scale.y, 0.5f * m_scale.z));
    m_modelMat = glm::rotate(m_modelMat, glm::radians(m_rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
    m_modelMat = glm::rotate(m_modelMat, glm::radians(m_rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    m_modelMat = glm::rotate(m_modelMat, glm::radians(m_rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
    m_modelMat = glm::translate(m_modelMat, glm::vec3(-0.5f * m_scale.x, -0.5f * m_scale.y, -0.5f * m_scale.z));
    m_modelMat = glm::scale(m_modelMat, m_scale);

    m_shader.setMat4f("model", m_modelMat);
}

void Primitive::draw(){
    this->update();

    glBindVertexArray(this->m_VAO);
    if(m_indices.empty())
        glDrawArrays(GL_TRIANGLES, 0, this->m_vertices.size());
    else{
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
        glDrawElements(GL_TRIANGLES, this->m_indices.size(), GL_UNSIGNED_INT, 0);
    }
    glBindVertexArray(0);
}

void Primitive::set(std::vector<Vertex> vertices, std::vector<unsigned int> indices){
    m_vertices = vertices;
    m_indices = indices;
    this->initRenderData();
};

void Primitive::initRenderData(){
    glGenVertexArrays(1, &this->m_VAO);
    glGenBuffers(1, &this->m_VBO);

    glBindBuffer(GL_ARRAY_BUFFER, this->m_VBO);
    glBufferData(GL_ARRAY_BUFFER, this->m_vertices.size() * sizeof(Vertex), this->m_vertices.data(), GL_STATIC_DRAW);

    if(!this->m_indices.empty()){
        glGenBuffers(1, &this->m_EBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->m_indices.size() * sizeof(unsigned int), &this->m_indices[0], GL_STATIC_DRAW);
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

// QUAD CONSTRUCTOR
Quad::Quad(float width, float height) : Primitive(), m_width(width), m_height(height){
    std::vector<Vertex> vertices = { 
        // pos                          // tex
        {glm::vec3(0.0f, 1.0f, 0.0f),   glm::vec2(0.0f, 1.0f)},
        {glm::vec3(1.0f, 0.0f, 0.0f),   glm::vec2(1.0f, 0.0f)},
        {glm::vec3(0.0f, 0.0f, 0.0f),   glm::vec2(0.0f, 0.0f)}, 
        {glm::vec3(1.0f, 1.0f, 0.0f),   glm::vec2(1.0f, 1.0f)},
    };
    std::vector<unsigned int> indices = {
        2,1,0,
        0,3,1
    };

    this->setScale(glm::vec3(m_width, m_height, 1.0f));
    this->set(vertices, indices);
}

// TRIANGLE CONSTRUCTOR
Triangle::Triangle() : Primitive() {
    std::vector<Vertex> vertices = { 
        // pos                              // tex
        {glm::vec3( 0.5f, 0.5f, 0.0f),     glm::vec2(0.0f, 1.0f)},
        {glm::vec3(-0.5f, 0.5f, 0.0f),     glm::vec2(1.0f, 1.0f)}, 
        {glm::vec3( 0.0f, 0.0f, 0.0f),     glm::vec2(0.5f, 0.0f)},
    };
    std::vector<unsigned int> indices = {
        0,1,2
    };

    this->set(vertices, indices);
}