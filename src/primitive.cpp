#include "lucerna/lucerna.h"

Quad::Quad() : Primitive(){
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

    this->set(vertices, indices);
}

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