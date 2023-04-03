#include "lucerna/lucerna.h"

Tex2D::Tex2D() : width(0), height(0){
    glGenTextures(1, &this->ID);
}

void Tex2D::Generate(unsigned int width, unsigned int height, unsigned char* data){
    this->width = width;
    this->height = height;
    // create Texture
    glBindTexture(GL_TEXTURE_2D, this->ID);
    glTexImage2D(GL_TEXTURE_2D, 0, m_format, width, this->height, 0, m_format, GL_UNSIGNED_BYTE, data);
    // set Texture wrap and filter modes
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, m_wrap);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, m_wrap);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, m_filter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, m_filter);
    // unbind texture
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Tex2D::Bind() const {
    glBindTexture(GL_TEXTURE_2D, this->ID);
}