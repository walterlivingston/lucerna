#pragma once

#include <vector>
#include <glad/glad.h>
#include "renderer.h"

struct BufferElement{
    unsigned int type;
    unsigned int count;
    unsigned char normalized;

    static unsigned int GetSize(unsigned int type){
        switch (type){
            case GL_FLOAT:          return 4;
            case GL_UNSIGNED_INT:   return 4;
            case GL_UNSIGNED_BYTE:  return 1;
        }
        ASSERT(false);
        return 0;
    }
};

class BufferLayout{
    private:
        std::vector<BufferElement> m_Elements;
        unsigned int m_Stride;
    public:
        BufferLayout() : m_Stride(0) {};
        ~BufferLayout() {};

        template<typename T>
        void Push(unsigned int count){
            count;
            assert(false);
        }

        template<>
        void Push<float>(unsigned int count){
            m_Elements.push_back({GL_FLOAT, count, GL_FALSE});
            m_Stride += BufferElement::GetSize(GL_FLOAT) * count;
        }

        template<>
        void Push<unsigned int>(unsigned int count){
            m_Elements.push_back({GL_UNSIGNED_INT, count, GL_FALSE});
            m_Stride += BufferElement::GetSize(GL_UNSIGNED_INT) * count;
        }

        template<>
        void Push<unsigned char>(unsigned int count){
            m_Elements.push_back({GL_UNSIGNED_BYTE, count, GL_TRUE});
            m_Stride += BufferElement::GetSize(GL_UNSIGNED_BYTE) * count;
        }

        inline const std::vector<BufferElement> GetElements() const& { return m_Elements; }
        inline unsigned int GetStride() const { return m_Stride; };
};