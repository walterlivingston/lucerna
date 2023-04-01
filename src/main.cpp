#include "lucerna/lucerna.h"

int width = 1080;
int height = 720;

SpriteRenderer* renderer;
Mesh* mesh;

void render(){
    mesh->draw(ResourceManager::getTexture("mario"), 
        glm::vec2(width/2, height/2), 
        glm::vec2(ResourceManager::getTexture("mario").width, ResourceManager::getTexture("mario").height));
}

int main(){
    Application app("Lucerna", width, height);
    
    ResourceManager::loadTexture("assets/textures/Mario.png", true, "mario");
    // ResourceManager::loadTexture("assets/textures/lamp.jpg", false, "lamp");
    // ResourceManager::loadTexture("assets/textures/flowers.jpeg", false, "flowers");

    ResourceManager::loadShader("shaders/default.glsl", "default");
    ResourceManager::loadShader("shaders/sprite.glsl", "sprite");

    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(width), 
        static_cast<float>(height), 0.0f, -1.0f, 1.0f);
    ResourceManager::getShader("default").use().setInteger("image", 0);
    ResourceManager::getShader("default").setMat4f("projection", projection);

    std::vector<Vertex> vertices = { 
        // pos                          // tex
        {glm::vec3(0.0f, 1.0f, 0.0f),   glm::vec2(0.0f, 1.0f)},
        {glm::vec3(1.0f, 0.0f, 0.0f),   glm::vec2(1.0f, 0.0f)},
        {glm::vec3(0.0f, 0.0f, 0.0f),   glm::vec2(0.0f, 0.0f)}, 

        {glm::vec3(0.0f, 1.0f, 0.0f),   glm::vec2(0.0f, 1.0f)},
        {glm::vec3(1.0f, 1.0f, 0.0f),   glm::vec2(1.0f, 1.0f)},
        {glm::vec3(1.0f, 0.0f, 0.0f),   glm::vec2(1.0f, 0.0f)}
    };
    std::vector<unsigned int> indices = {
        0,1,2,
        3,4,5
    };

    renderer = new SpriteRenderer(ResourceManager::getShader("sprite"));
    mesh = new Mesh(vertices, indices);

    app.setRenderCallback(render);
    app.run();
    return 0;
}