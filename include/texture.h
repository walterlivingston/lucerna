#pragma once

#include "glad/glad.h"

class Tex2D{
    private:
        unsigned int m_width;
        unsigned int m_height;

        unsigned int m_format = GL_RGB;
        unsigned int m_wrap = GL_REPEAT;
        unsigned int m_filter = GL_LINEAR;
    public:
        unsigned int ID;

        Tex2D();
        void Generate(unsigned int width, unsigned int height, unsigned char* data);
        void Bind() const;

        inline void setFormat(unsigned int format) { m_format = format; };
};