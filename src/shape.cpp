#include "lucerna/lucerna.h"

Shape::Shape(float c_x, float c_y, std::string shader){
    this->m_x = c_x;
    this->m_y = c_y;
    this->m_shader = shader;
    this->calcVertices();

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(m_vertices), m_vertices, GL_STATIC_DRAW);
    // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    // glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0); 
    glBindVertexArray(0);
}

Shape::~Shape(){
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

void Shape::Draw(GLenum drawType) const{
    glBindVertexArray(VAO);
    glDrawArrays(drawType, 0, 3);
}

Circle::Circle(float c_x, float c_y, float radius, std::string shader) : Shape(c_x, c_y, shader){
    this->m_radius = radius;
    this->calcVertices();
}

Triangle::Triangle(float c_x, float c_y, float width, float height, std::string shader) : Shape(c_x, c_y, shader) {
    this->m_width = width;
    this->m_height = height;
    this->calcVertices();
}

void Triangle::calcVertices(){
    m_vertices = (float*)malloc(sizeof(float)*9);
    m_vertices[0] = m_x - m_width / 2;      m_vertices[1] = m_y - m_height / 2;     m_vertices[2] = 0.0f;
    m_vertices[3] = m_x + m_width / 2;      m_vertices[4] = m_y - m_height / 2;     m_vertices[5] = 0.0f;
    m_vertices[6] = m_x;                    m_vertices[7] = m_y + m_height / 2;     m_vertices[8] = 0.0f;
}