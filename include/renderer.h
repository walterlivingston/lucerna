#pragma once

#include "glad/glad.h"
#include "vertex_array.h"
#include "index_buffer.h"
#include "shader.h"

#define ASSERT(x) if(!(x)) __builtin_debugtrap();
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__))

void GLClearError();
bool GLLogCall(const char* function, const char* file, int line);

class Renderer{
    private:
    public:
        void Clear();
        void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
};