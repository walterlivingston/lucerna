#include "lucerna/lucerna.h"

Mesh::Mesh(Primitive* primitive, std::string shader){
    m_primitive = primitive;
}

Mesh::~Mesh(){}

void Mesh::update(){
    m_primitive->update();
}

void Mesh::draw(Tex2D texture){
    this->m_primitive->setScale(glm::vec3(texture.width, texture.height, 1.0f));
    this->update();
    
    glActiveTexture(GL_TEXTURE0);
    texture.Bind();

    m_primitive->draw();
}