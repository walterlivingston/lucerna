#pragma once

#include <vector>
#include <string>
#include <glm/glm.hpp>

#include "texture.h"
#include "shader.h"
#include "primitive.h"

class Mesh{
    private:
        Primitive* m_primitive;
    public:
        Mesh(Primitive* primitive, std::string shader = "default");
        ~Mesh();

        void draw(Tex2D texture);
        void update();
};